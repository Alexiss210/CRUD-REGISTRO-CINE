#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#include <QMessageBox>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QIntValidator>
#include <QDoubleValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , indiceSeleccionado(-1)
    , indiceVentaSeleccionado(-1)
{
    ui->setupUi(this);

    // Validadores
    ui->txtCodigo->setValidator(
        new QIntValidator(1, 999999, this)
        );

    ui->txtStock->setValidator(
        new QIntValidator(0, 999999, this)
        );

    QDoubleValidator *validadorPrecio =
        new QDoubleValidator(0.01, 999999.99, 2, this);

    validadorPrecio->setNotation(
        QDoubleValidator::StandardNotation
        );

    ui->txtPrecio->setValidator(validadorPrecio);

    // Configuración de la tabla
    ui->tblProductos->setSelectionBehavior(
        QAbstractItemView::SelectRows
        );

    ui->tblProductos->setSelectionMode(
        QAbstractItemView::SingleSelection
        );

    ui->tblProductos->setEditTriggers(
        QAbstractItemView::NoEditTriggers
        );

    ui->tblProductos->horizontalHeader()->setSectionResizeMode(
        QHeaderView::Stretch
        );
    // Configuración de la tabla de ventas
    ui->tblVentas->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tblVentas->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tblVentas->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tblVentas->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->btnEditarVenta->setEnabled(false);
    ui->btnEliminarVenta->setEnabled(false);

    connect(ui->btnGuardarVenta, &QPushButton::clicked, this, &MainWindow::guardarVenta);
    connect(ui->btnEditarVenta, &QPushButton::clicked, this, &MainWindow::editarVenta);
    connect(ui->btnEliminarVenta, &QPushButton::clicked, this, &MainWindow::eliminarVenta);
    connect(ui->btnLimpiarVenta, &QPushButton::clicked, this, &MainWindow::limpiarFormularioVenta);
    connect(ui->tblVentas, &QTableWidget::cellClicked, this, &MainWindow::seleccionarVenta);

    // Recalcular el precio en pantalla cada vez que cambias algo
    connect(ui->cmbPelicula, &QComboBox::currentTextChanged, this, &MainWindow::actualizarPrecioEnPantalla);
    connect(ui->cmbTipoCliente, &QComboBox::currentTextChanged, this, &MainWindow::actualizarPrecioEnPantalla);
    connect(ui->cmbMetodoPago, &QComboBox::currentTextChanged, this, &MainWindow::actualizarPrecioEnPantalla);

    // Estado inicial
    ui->btnEditar->setEnabled(false);
    ui->btnEliminar->setEnabled(false);

    // Conexiones de botones
    connect(
        ui->btnGuardar,
        &QPushButton::clicked,
        this,
        &MainWindow::guardarProducto
        );

    connect(
        ui->btnEditar,
        &QPushButton::clicked,
        this,
        &MainWindow::editarProducto
        );

    connect(
        ui->btnEliminar,
        &QPushButton::clicked,
        this,
        &MainWindow::eliminarProducto
        );

    connect(
        ui->btnBuscar,
        &QPushButton::clicked,
        this,
        &MainWindow::buscarProducto
        );

    connect(
        ui->btnLimpiar,
        &QPushButton::clicked,
        this,
        &MainWindow::limpiarFormulario
        );

    connect(
        ui->tblProductos,
        &QTableWidget::cellClicked,
        this,
        &MainWindow::seleccionarProducto
        );

    // --- Navegación entre menús ---
    connect(ui->btnCategoria, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(0);   // ir al CRUD (page_3)
    });

    connect(ui->btnRegistros, &QPushButton::clicked, this, [this]() {
        llenarComboPeliculas();
        actualizarTablaVentas();
        actualizarPrecioEnPantalla();
        ui->stackedWidget->setCurrentIndex(2);   // ir a Registros (page_2)
    });

    connect(ui->btnVolverMenu1, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(1);   // volver al Menú (page)
    });

    connect(ui->btnVolverMenu2, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(1);   // volver al Menú (page)
    });

    ui->stackedWidget->setCurrentIndex(1);   // arranca en el Menú Principal (page)

    cargarVentasDesdeArchivo();
    actualizarTablaVentas();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::validarFormulario()
{
    if (ui->txtCodigo->text().trimmed().isEmpty()) {
        QMessageBox::warning(
            this,
            "Campo obligatorio",
            "Ingrese el código del producto."
            );

        ui->txtCodigo->setFocus();
        return false;
    }

    if (ui->txtNombre->text().trimmed().isEmpty()) {
        QMessageBox::warning(
            this,
            "Campo obligatorio",
            "Ingrese el nombre del producto."
            );

        ui->txtNombre->setFocus();
        return false;
    }

    if (ui->cmbCategoria->currentIndex() == 0) {
        QMessageBox::warning(
            this,
            "Campo obligatorio",
            "Seleccione una categoría."
            );

        return false;
    }

    if (ui->txtPrecio->text().trimmed().isEmpty()) {
        QMessageBox::warning(
            this,
            "Campo obligatorio",
            "Ingrese el precio."
            );

        ui->txtPrecio->setFocus();
        return false;
    }

    if (ui->txtStock->text().trimmed().isEmpty()) {
        QMessageBox::warning(
            this,
            "Campo obligatorio",
            "Ingrese el stock."
            );

        ui->txtStock->setFocus();
        return false;
    }

    if (ui->txtPrecio->text().toDouble() <= 0) {
        QMessageBox::warning(
            this,
            "Precio inválido",
            "El precio debe ser mayor que cero."
            );

        return false;
    }
    return true;
}

int MainWindow::buscarIndicePorCodigo(int codigo)
{
    for (int i = 0; i < productos.size(); i++) {

        if (productos[i].codigo == codigo) {
            return i;
        }
    }

    return -1;
}

void MainWindow::guardarProducto()
{
    if (!validarFormulario()) {
        return;
    }

    int codigo = ui->txtCodigo->text().toInt();

    if (buscarIndicePorCodigo(codigo) != -1) {
        QMessageBox::warning(
            this,
            "Código duplicado",
            "Ya existe un producto con ese código."
            );

        return;
    }

    Producto producto;

    producto.codigo = codigo;
    producto.nombre = ui->txtNombre->text().trimmed();
    producto.categoria = ui->cmbCategoria->currentText();
    producto.precio = ui->txtPrecio->text().toDouble();
    producto.stock = ui->txtStock->text().toInt();

    productos.append(producto);

    guardarProductosEnArchivo();
    actualizarTabla();
    limpiarFormulario();

    QMessageBox::information(
        this,
        "Producto guardado",
        "El producto se guardó correctamente."
        );
}

void MainWindow::actualizarTabla()
{
    ui->tblProductos->setRowCount(productos.size());

    for (int fila = 0; fila < productos.size(); fila++) {

        const Producto &producto = productos[fila];

        ui->tblProductos->setItem(
            fila,
            0,
            new QTableWidgetItem(
                QString::number(producto.codigo)
                )
            );

        ui->tblProductos->setItem(
            fila,
            1,
            new QTableWidgetItem(producto.nombre)
            );

        ui->tblProductos->setItem(
            fila,
            2,
            new QTableWidgetItem(producto.categoria)
            );

        ui->tblProductos->setItem(
            fila,
            3,
            new QTableWidgetItem(
                QString::number(producto.precio, 'f', 2)
                )
            );

        ui->tblProductos->setItem(
            fila,
            4,
            new QTableWidgetItem(
                QString::number(producto.stock)
                )
            );
    }
}

void MainWindow::seleccionarProducto(int fila, int columna)
{
    Q_UNUSED(columna);

    if (fila < 0 || fila >= productos.size()) {
        return;
    }

    indiceSeleccionado = fila;

    const Producto &producto = productos[fila];

    ui->txtCodigo->setText(
        QString::number(producto.codigo)
        );

    ui->txtNombre->setText(producto.nombre);

    int posicionCategoria =
        ui->cmbCategoria->findText(producto.categoria);

    ui->cmbCategoria->setCurrentIndex(posicionCategoria);

    ui->txtPrecio->setText(
        QString::number(producto.precio, 'f', 2)
        );

    ui->txtStock->setText(
        QString::number(producto.stock)
        );

    ui->btnGuardar->setEnabled(false);
    ui->btnEditar->setEnabled(true);
    ui->btnEliminar->setEnabled(true);
}

void MainWindow::editarProducto()
{
    if (indiceSeleccionado == -1) {
        QMessageBox::warning(
            this,
            "Sin selección",
            "Seleccione un producto de la tabla."
            );

        return;
    }

    if (!validarFormulario()) {
        return;
    }

    int nuevoCodigo = ui->txtCodigo->text().toInt();

    int indiceCodigo =
        buscarIndicePorCodigo(nuevoCodigo);

    if (indiceCodigo != -1 &&
        indiceCodigo != indiceSeleccionado) {

        QMessageBox::warning(
            this,
            "Código duplicado",
            "Ya existe otro producto con ese código."
            );

        return;
    }

    Producto &producto =
        productos[indiceSeleccionado];

    producto.codigo = nuevoCodigo;
    producto.nombre = ui->txtNombre->text().trimmed();
    producto.categoria = ui->cmbCategoria->currentText();
    producto.precio = ui->txtPrecio->text().toDouble();
    producto.stock = ui->txtStock->text().toInt();

    guardarProductosEnArchivo();
    actualizarTabla();
    limpiarFormulario();

    QMessageBox::information(
        this,
        "Producto actualizado",
        "El producto fue actualizado correctamente."
        );
}

void MainWindow::eliminarProducto()
{
    if (indiceSeleccionado == -1) {
        QMessageBox::warning(
            this,
            "Sin selección",
            "Seleccione un producto de la tabla."
            );

        return;
    }

    QMessageBox::StandardButton respuesta;

    respuesta = QMessageBox::question(
        this,
        "Confirmar eliminación",
        "¿Desea eliminar el producto?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (respuesta == QMessageBox::Yes) {

        productos.removeAt(indiceSeleccionado);

        guardarProductosEnArchivo();
        actualizarTabla();
        limpiarFormulario();

        QMessageBox::information(
            this,
            "Producto eliminado",
            "El producto fue eliminado correctamente."
            );
    }
}

void MainWindow::buscarProducto()
{
    if (ui->txtCodigo->text().trimmed().isEmpty()) {
        QMessageBox::warning(
            this,
            "Código requerido",
            "Ingrese el código que desea buscar."
            );

        return;
    }

    int codigo = ui->txtCodigo->text().toInt();

    int indice = buscarIndicePorCodigo(codigo);

    if (indice == -1) {
        QMessageBox::information(
            this,
            "Producto no encontrado",
            "No existe un producto con ese código."
            );

        return;
    }

    indiceSeleccionado = indice;

    const Producto &producto = productos[indice];

    ui->txtNombre->setText(producto.nombre);

    int posicionCategoria =
        ui->cmbCategoria->findText(producto.categoria);

    ui->cmbCategoria->setCurrentIndex(posicionCategoria);

    ui->txtPrecio->setText(
        QString::number(producto.precio, 'f', 2)
        );

    ui->txtStock->setText(
        QString::number(producto.stock)
        );

    ui->tblProductos->selectRow(indice);

    ui->btnGuardar->setEnabled(false);
    ui->btnEditar->setEnabled(true);
    ui->btnEliminar->setEnabled(true);

    QMessageBox::information(
        this,
        "Producto encontrado",
        "El producto fue encontrado correctamente."
        );
}

void MainWindow::limpiarFormulario()
{
    ui->txtCodigo->clear();
    ui->txtNombre->clear();
    ui->cmbCategoria->setCurrentIndex(0);
    ui->txtPrecio->clear();
    ui->txtStock->clear();

    ui->tblProductos->clearSelection();

    indiceSeleccionado = -1;

    ui->btnGuardar->setEnabled(true);
    ui->btnEditar->setEnabled(false);
    ui->btnEliminar->setEnabled(false);

    ui->txtCodigo->setFocus();
}

void MainWindow::guardarProductosEnArchivo()
{
    QString ruta =
        QDir::currentPath() + "/productos.txt";

    QFile archivo(ruta);

    if (!archivo.open(
            QIODevice::WriteOnly |
            QIODevice::Text)) {

        QMessageBox::critical(
            this,
            "Error",
            "No se pudo guardar el archivo."
            );

        return;
    }

    QTextStream salida(&archivo);

    for (const Producto &producto : productos) {

        salida << producto.codigo << ";"
               << producto.nombre << ";"
               << producto.categoria << ";"
               << QString::number(
                      producto.precio,
                      'f',
                      2
                      ) << ";"
               << producto.stock
               << "\n";
    }

    archivo.close();
}

void MainWindow::cargarProductosDesdeArchivo()
{
    QString ruta =
        QDir::currentPath() + "/productos.txt";

    QFile archivo(ruta);

    if (!archivo.exists()) {
        return;
    }

    if (!archivo.open(
            QIODevice::ReadOnly |
            QIODevice::Text)) {

        QMessageBox::warning(
            this,
            "Error",
            "No se pudo abrir el archivo."
            );

        return;
    }

    QTextStream entrada(&archivo);

    productos.clear();

    while (!entrada.atEnd()) {

        QString linea = entrada.readLine();

        if (linea.trimmed().isEmpty()) {
            continue;
        }

        QStringList datos = linea.split(";");

        if (datos.size() != 5) {
            continue;
        }

        Producto producto;

        producto.codigo = datos[0].toInt();
        producto.nombre = datos[1];
        producto.categoria = datos[2];
        producto.precio = datos[3].toDouble();
        producto.stock = datos[4].toInt();

        productos.append(producto);
    }

    archivo.close();
}

// Nuevo CRUD PARA el metodo de VENTA DE VOLETOS
void MainWindow::llenarComboPeliculas()
{
    ui->cmbPelicula->clear();
    for (const Producto &p : productos) {
        ui->cmbPelicula->addItem(p.nombre);
    }
}

double MainWindow::calcularPrecioFinal()
{
    QString nombrePelicula = ui->cmbPelicula->currentText();
    double precioBase = 0.0;

    for (const Producto &p : productos) {
        if (p.nombre == nombrePelicula) {
            precioBase = p.precio;
            break;
        }
    }

    // Aplicar tipo de cliente
    QString tipoCliente = ui->cmbTipoCliente->currentText();

    if (tipoCliente.startsWith("Infantil")) {
        precioBase = precioBase * 0.50;   // 50% de descuento
    } else if (tipoCliente.startsWith("Adulto Mayor")) {
        precioBase = precioBase * 0.40;   // 60% de descuento (paga el 40%)
    }
    // Adulto normal no cambia el precio

    // Aplicar método de pago
    QString metodo = ui->cmbMetodoPago->currentText();
    if (metodo == "Tarjeta") {
        precioBase = precioBase * 1.15;
    } else if (metodo == "Transferencia") {
        precioBase = precioBase * 0.90;
    }
    // Efectivo no cambia el precio

    return precioBase;
}

void MainWindow::actualizarPrecioEnPantalla()
{
    double precio = calcularPrecioFinal();
    ui->lblPrecioFinal->setText(
        QString("Precio final: $%1").arg(QString::number(precio, 'f', 2))
        );
}

void MainWindow::guardarVenta()
{
    if (ui->cmbPelicula->currentText().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Campo obligatorio", "Registra al menos una película en Categoría primero.");
        return;
    }

    Venta v;
    v.id = ventas.size() + 1;
    v.pelicula = ui->cmbPelicula->currentText();
    v.tipoCliente = ui->cmbTipoCliente->currentText();
    v.metodoPago = ui->cmbMetodoPago->currentText();

    // Buscamos el precio base de la película seleccionada
    v.precioBase = 0.0;
    for (const Producto &p : productos) {
        if (p.nombre == v.pelicula) {
            v.precioBase = p.precio;
            break;
        }
    }

    v.precioFinal = calcularPrecioFinal();

    ventas.append(v);

    guardarVentasEnArchivo();
    actualizarTablaVentas();
    limpiarFormularioVenta();

    QMessageBox::information(this, "Venta registrada", "El boleto se registró correctamente.");
}

void MainWindow::actualizarTablaVentas()
{
    ui->tblVentas->setRowCount(ventas.size());

    for (int fila = 0; fila < ventas.size(); fila++) {
        const Venta &v = ventas[fila];

        ui->tblVentas->setItem(fila, 0, new QTableWidgetItem(QString::number(v.id)));
        ui->tblVentas->setItem(fila, 1, new QTableWidgetItem(v.pelicula));
        ui->tblVentas->setItem(fila, 2, new QTableWidgetItem(v.tipoCliente));
        ui->tblVentas->setItem(fila, 3, new QTableWidgetItem(v.metodoPago));
        ui->tblVentas->setItem(fila, 4, new QTableWidgetItem(
                                            QString("$%1").arg(QString::number(v.precioFinal, 'f', 2))
                                            ));
    }
}

void MainWindow::seleccionarVenta(int fila, int columna)
{
    Q_UNUSED(columna);

    if (fila < 0 || fila >= ventas.size()) {
        return;
    }

    indiceVentaSeleccionado = fila;
    const Venta &v = ventas[fila];

    int posicionPelicula = ui->cmbPelicula->findText(v.pelicula);
    ui->cmbPelicula->setCurrentIndex(posicionPelicula);

    int posicionCliente = ui->cmbTipoCliente->findText(v.tipoCliente);
    ui->cmbTipoCliente->setCurrentIndex(posicionCliente);

    int posicionPago = ui->cmbMetodoPago->findText(v.metodoPago);
    ui->cmbMetodoPago->setCurrentIndex(posicionPago);

    ui->btnGuardarVenta->setEnabled(false);
    ui->btnEditarVenta->setEnabled(true);
    ui->btnEliminarVenta->setEnabled(true);
}

void MainWindow::editarVenta()
{
    if (indiceVentaSeleccionado == -1) {
        QMessageBox::warning(this, "Sin selección", "Selecciona una venta de la tabla.");
        return;
    }

    Venta &v = ventas[indiceVentaSeleccionado];
    v.pelicula = ui->cmbPelicula->currentText();
    v.tipoCliente = ui->cmbTipoCliente->currentText();
    v.metodoPago = ui->cmbMetodoPago->currentText();

    for (const Producto &p : productos) {
        if (p.nombre == v.pelicula) {
            v.precioBase = p.precio;
            break;
        }
    }

    v.precioFinal = calcularPrecioFinal();

    guardarVentasEnArchivo();
    actualizarTablaVentas();
    limpiarFormularioVenta();

    QMessageBox::information(this, "Venta actualizada", "El registro fue actualizado correctamente.");
}

void MainWindow::eliminarVenta()
{
    if (indiceVentaSeleccionado == -1) {
        QMessageBox::warning(this, "Sin selección", "Selecciona una venta de la tabla.");
        return;
    }

    QMessageBox::StandardButton respuesta = QMessageBox::question(
        this, "Confirmar eliminación", "¿Deseas eliminar esta venta?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (respuesta == QMessageBox::Yes) {
        ventas.removeAt(indiceVentaSeleccionado);
        guardarVentasEnArchivo();
        actualizarTablaVentas();
        limpiarFormularioVenta();

        QMessageBox::information(this, "Venta eliminada", "El registro fue eliminado correctamente.");
    }
}

void MainWindow::limpiarFormularioVenta()
{
    ui->cmbPelicula->setCurrentIndex(0);
    ui->cmbTipoCliente->setCurrentIndex(0);
    ui->cmbMetodoPago->setCurrentIndex(0);

    ui->tblVentas->clearSelection();
    indiceVentaSeleccionado = -1;

    ui->btnGuardarVenta->setEnabled(true);
    ui->btnEditarVenta->setEnabled(false);
    ui->btnEliminarVenta->setEnabled(false);

    actualizarPrecioEnPantalla();
}

void MainWindow::guardarVentasEnArchivo()
{
    QString ruta = QDir::currentPath() + "/ventas.txt";
    QFile archivo(ruta);

    if (!archivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "No se pudo guardar el archivo de ventas.");
        return;
    }

    QTextStream salida(&archivo);
    for (const Venta &v : ventas) {
        salida << v.id << ";" << v.pelicula << ";" << v.tipoCliente << ";"
               << v.metodoPago << ";"
               << QString::number(v.precioBase, 'f', 2) << ";"
               << QString::number(v.precioFinal, 'f', 2) << "\n";
    }

    archivo.close();
}

void MainWindow::cargarVentasDesdeArchivo()
{
    QString ruta = QDir::currentPath() + "/ventas.txt";
    QFile archivo(ruta);

    if (!archivo.exists()) {
        return;
    }

    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream entrada(&archivo);
    ventas.clear();

    while (!entrada.atEnd()) {
        QString linea = entrada.readLine();
        if (linea.trimmed().isEmpty()) continue;

        QStringList datos = linea.split(";");
        if (datos.size() != 6) continue;

        Venta v;
        v.id = datos[0].toInt();
        v.pelicula = datos[1];
        v.tipoCliente = datos[2];
        v.metodoPago = datos[3];
        v.precioBase = datos[4].toDouble();
        v.precioFinal = datos[5].toDouble();

        ventas.append(v);
    }

    archivo.close();
}