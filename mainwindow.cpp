#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    cargarProductosDesdeArchivo();
    actualizarTabla();
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

