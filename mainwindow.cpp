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
