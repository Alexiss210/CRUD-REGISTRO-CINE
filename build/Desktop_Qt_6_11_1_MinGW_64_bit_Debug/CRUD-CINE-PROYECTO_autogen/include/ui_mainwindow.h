/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *txtStock;
    QLabel *label_3;
    QComboBox *cmbCategoria;
    QLabel *label_5;
    QLabel *label_2;
    QLineEdit *txtPrecio;
    QLabel *label_4;
    QLineEdit *txtNombre;
    QLabel *label_6;
    QLineEdit *txtCodigo;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnGuardar;
    QPushButton *btnEditar;
    QPushButton *btnBuscar;
    QPushButton *btnEliminar;
    QPushButton *btnLimpiar;
    QPushButton *btnVolverMenu1;
    QTableWidget *tblProductos;
    QLabel *lblTitulo;
    QWidget *page;
    QLabel *label;
    QPushButton *btnCategoria;
    QPushButton *btnRegistros;
    QLabel *label_7;
    QWidget *page_2;
    QPushButton *btnVolverMenu2;
    QLabel *lblPrecioFinal;
    QLabel *label_11;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QVBoxLayout *verticalLayout_3;
    QComboBox *cmbPelicula;
    QComboBox *cmbTipoCliente;
    QComboBox *cmbMetodoPago;
    QTableWidget *tblVentas;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnLimpiarVenta;
    QPushButton *btnEliminarVenta;
    QPushButton *btnEditarVenta;
    QPushButton *btnGuardarVenta;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1194, 690);
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(14);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 1171, 677));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        layoutWidget = new QWidget(page_3);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(130, 110, 901, 481));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        txtStock = new QLineEdit(layoutWidget);
        txtStock->setObjectName("txtStock");

        gridLayout->addWidget(txtStock, 4, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        cmbCategoria = new QComboBox(layoutWidget);
        cmbCategoria->addItem(QString());
        cmbCategoria->addItem(QString());
        cmbCategoria->addItem(QString());
        cmbCategoria->addItem(QString());
        cmbCategoria->addItem(QString());
        cmbCategoria->addItem(QString());
        cmbCategoria->addItem(QString());
        cmbCategoria->addItem(QString());
        cmbCategoria->setObjectName("cmbCategoria");

        gridLayout->addWidget(cmbCategoria, 2, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        txtPrecio = new QLineEdit(layoutWidget);
        txtPrecio->setObjectName("txtPrecio");

        gridLayout->addWidget(txtPrecio, 3, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        txtNombre = new QLineEdit(layoutWidget);
        txtNombre->setObjectName("txtNombre");

        gridLayout->addWidget(txtNombre, 1, 1, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        txtCodigo = new QLineEdit(layoutWidget);
        txtCodigo->setObjectName("txtCodigo");

        gridLayout->addWidget(txtCodigo, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnGuardar = new QPushButton(layoutWidget);
        btnGuardar->setObjectName("btnGuardar");

        horizontalLayout->addWidget(btnGuardar);

        btnEditar = new QPushButton(layoutWidget);
        btnEditar->setObjectName("btnEditar");

        horizontalLayout->addWidget(btnEditar);

        btnBuscar = new QPushButton(layoutWidget);
        btnBuscar->setObjectName("btnBuscar");

        horizontalLayout->addWidget(btnBuscar);

        btnEliminar = new QPushButton(layoutWidget);
        btnEliminar->setObjectName("btnEliminar");

        horizontalLayout->addWidget(btnEliminar);

        btnLimpiar = new QPushButton(layoutWidget);
        btnLimpiar->setObjectName("btnLimpiar");

        horizontalLayout->addWidget(btnLimpiar);

        btnVolverMenu1 = new QPushButton(layoutWidget);
        btnVolverMenu1->setObjectName("btnVolverMenu1");

        horizontalLayout->addWidget(btnVolverMenu1);


        verticalLayout->addLayout(horizontalLayout);

        tblProductos = new QTableWidget(layoutWidget);
        if (tblProductos->columnCount() < 5)
            tblProductos->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblProductos->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblProductos->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblProductos->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblProductos->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblProductos->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tblProductos->setObjectName("tblProductos");
        tblProductos->setColumnCount(5);
        tblProductos->horizontalHeader()->setMinimumSectionSize(56);

        verticalLayout->addWidget(tblProductos);

        lblTitulo = new QLabel(page_3);
        lblTitulo->setObjectName("lblTitulo");
        lblTitulo->setGeometry(QRect(380, 40, 481, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(28);
        font1.setBold(true);
        lblTitulo->setFont(font1);
        stackedWidget->addWidget(page_3);
        page = new QWidget();
        page->setObjectName("page");
        label = new QLabel(page);
        label->setObjectName("label");
        label->setGeometry(QRect(310, 180, 601, 161));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Bauhaus 93")});
        font2.setPointSize(36);
        font2.setBold(false);
        label->setFont(font2);
        btnCategoria = new QPushButton(page);
        btnCategoria->setObjectName("btnCategoria");
        btnCategoria->setGeometry(QRect(290, 430, 201, 81));
        btnRegistros = new QPushButton(page);
        btnRegistros->setObjectName("btnRegistros");
        btnRegistros->setGeometry(QRect(680, 430, 181, 71));
        label_7 = new QLabel(page);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(380, 320, 461, 61));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        btnVolverMenu2 = new QPushButton(page_2);
        btnVolverMenu2->setObjectName("btnVolverMenu2");
        btnVolverMenu2->setGeometry(QRect(100, 570, 172, 35));
        lblPrecioFinal = new QLabel(page_2);
        lblPrecioFinal->setObjectName("lblPrecioFinal");
        lblPrecioFinal->setGeometry(QRect(860, 540, 251, 81));
        label_11 = new QLabel(page_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(410, 30, 471, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial")});
        font3.setPointSize(28);
        label_11->setFont(font3);
        widget = new QWidget(page_2);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(50, 100, 1051, 431));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_8 = new QLabel(widget);
        label_8->setObjectName("label_8");

        verticalLayout_4->addWidget(label_8);

        label_9 = new QLabel(widget);
        label_9->setObjectName("label_9");

        verticalLayout_4->addWidget(label_9);

        label_10 = new QLabel(widget);
        label_10->setObjectName("label_10");

        verticalLayout_4->addWidget(label_10);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        cmbPelicula = new QComboBox(widget);
        cmbPelicula->addItem(QString());
        cmbPelicula->setObjectName("cmbPelicula");

        verticalLayout_3->addWidget(cmbPelicula);

        cmbTipoCliente = new QComboBox(widget);
        cmbTipoCliente->addItem(QString());
        cmbTipoCliente->addItem(QString());
        cmbTipoCliente->addItem(QString());
        cmbTipoCliente->setObjectName("cmbTipoCliente");

        verticalLayout_3->addWidget(cmbTipoCliente);

        cmbMetodoPago = new QComboBox(widget);
        cmbMetodoPago->addItem(QString());
        cmbMetodoPago->addItem(QString());
        cmbMetodoPago->addItem(QString());
        cmbMetodoPago->addItem(QString());
        cmbMetodoPago->setObjectName("cmbMetodoPago");

        verticalLayout_3->addWidget(cmbMetodoPago);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(horizontalLayout_2);

        tblVentas = new QTableWidget(widget);
        if (tblVentas->columnCount() < 5)
            tblVentas->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblVentas->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tblVentas->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tblVentas->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tblVentas->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tblVentas->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        tblVentas->setObjectName("tblVentas");
        tblVentas->setColumnCount(5);

        verticalLayout_5->addWidget(tblVentas);


        verticalLayout_2->addLayout(verticalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        btnLimpiarVenta = new QPushButton(widget);
        btnLimpiarVenta->setObjectName("btnLimpiarVenta");

        horizontalLayout_3->addWidget(btnLimpiarVenta);

        btnEliminarVenta = new QPushButton(widget);
        btnEliminarVenta->setObjectName("btnEliminarVenta");

        horizontalLayout_3->addWidget(btnEliminarVenta);

        btnEditarVenta = new QPushButton(widget);
        btnEditarVenta->setObjectName("btnEditarVenta");

        horizontalLayout_3->addWidget(btnEditarVenta);

        btnGuardarVenta = new QPushButton(widget);
        btnGuardarVenta->setObjectName("btnGuardarVenta");

        horizontalLayout_3->addWidget(btnGuardarVenta);


        verticalLayout_2->addLayout(horizontalLayout_3);

        stackedWidget->addWidget(page_2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1194, 32));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        txtStock->setText(QString());
        txtStock->setPlaceholderText(QCoreApplication::translate("MainWindow", "25", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Nombre:", nullptr));
        cmbCategoria->setItemText(0, QCoreApplication::translate("MainWindow", "Seleccione una categoria", nullptr));
        cmbCategoria->setItemText(1, QCoreApplication::translate("MainWindow", "Aventura", nullptr));
        cmbCategoria->setItemText(2, QCoreApplication::translate("MainWindow", "Suspenso", nullptr));
        cmbCategoria->setItemText(3, QCoreApplication::translate("MainWindow", "Terror", nullptr));
        cmbCategoria->setItemText(4, QCoreApplication::translate("MainWindow", "Comedia", nullptr));
        cmbCategoria->setItemText(5, QCoreApplication::translate("MainWindow", "Accion", nullptr));
        cmbCategoria->setItemText(6, QCoreApplication::translate("MainWindow", "Drama", nullptr));
        cmbCategoria->setItemText(7, QCoreApplication::translate("MainWindow", "Ciencia Ficcion", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "Precio:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Codigo:", nullptr));
        txtPrecio->setText(QString());
        txtPrecio->setPlaceholderText(QCoreApplication::translate("MainWindow", "7.50", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Categoria:", nullptr));
        txtNombre->setText(QString());
        txtNombre->setPlaceholderText(QCoreApplication::translate("MainWindow", "Avatar", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Entradas:", nullptr));
        txtCodigo->setPlaceholderText(QCoreApplication::translate("MainWindow", "001", nullptr));
        btnGuardar->setText(QCoreApplication::translate("MainWindow", "Guardar", nullptr));
        btnEditar->setText(QCoreApplication::translate("MainWindow", "Editar", nullptr));
        btnBuscar->setText(QCoreApplication::translate("MainWindow", "Buscar", nullptr));
        btnEliminar->setText(QCoreApplication::translate("MainWindow", "Eliminar", nullptr));
        btnLimpiar->setText(QCoreApplication::translate("MainWindow", "Limpiar", nullptr));
        btnVolverMenu1->setText(QCoreApplication::translate("MainWindow", "MENU", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblProductos->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Codigo", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblProductos->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Nombre", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblProductos->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Categoria", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblProductos->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Precio", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblProductos->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Stock", nullptr));
        lblTitulo->setText(QCoreApplication::translate("MainWindow", "REGISTRO DE CINE", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "CINEMAX POLIMOVIE", nullptr));
        btnCategoria->setText(QCoreApplication::translate("MainWindow", "REGISTRO", nullptr));
        btnRegistros->setText(QCoreApplication::translate("MainWindow", "LISTADO", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "FORMACION DE TECNOLOGOS", nullptr));
        btnVolverMenu2->setText(QCoreApplication::translate("MainWindow", "Volver al MENU", nullptr));
        lblPrecioFinal->setText(QCoreApplication::translate("MainWindow", "Precio final: $0.00", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "METODO DE PAGO", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Pelicula:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Tipo de Cliente:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Metodo de Pago:", nullptr));
        cmbPelicula->setItemText(0, QCoreApplication::translate("MainWindow", "Seleccione Tipo de Pelicula:", nullptr));

        cmbTipoCliente->setItemText(0, QCoreApplication::translate("MainWindow", "Adulto", nullptr));
        cmbTipoCliente->setItemText(1, QCoreApplication::translate("MainWindow", "Adulto Mayor", nullptr));
        cmbTipoCliente->setItemText(2, QCoreApplication::translate("MainWindow", "Infantil", nullptr));

        cmbMetodoPago->setItemText(0, QCoreApplication::translate("MainWindow", "Seleccione Metodo de Pago:", nullptr));
        cmbMetodoPago->setItemText(1, QCoreApplication::translate("MainWindow", "Efectivo", nullptr));
        cmbMetodoPago->setItemText(2, QCoreApplication::translate("MainWindow", "Tarjeta", nullptr));
        cmbMetodoPago->setItemText(3, QCoreApplication::translate("MainWindow", "Transferencia", nullptr));

        QTableWidgetItem *___qtablewidgetitem5 = tblVentas->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblVentas->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Pago", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tblVentas->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Cliente", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tblVentas->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Pago", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tblVentas->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Precio Final", nullptr));
        btnLimpiarVenta->setText(QCoreApplication::translate("MainWindow", "Limpiar", nullptr));
        btnEliminarVenta->setText(QCoreApplication::translate("MainWindow", "Eliminar", nullptr));
        btnEditarVenta->setText(QCoreApplication::translate("MainWindow", "Editar", nullptr));
        btnGuardarVenta->setText(QCoreApplication::translate("MainWindow", "Guardar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
