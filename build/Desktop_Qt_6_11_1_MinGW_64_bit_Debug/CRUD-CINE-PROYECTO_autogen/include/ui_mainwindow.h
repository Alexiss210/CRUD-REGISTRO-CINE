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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *lblTitulo;
    QLineEdit *txtCodigo;
    QLabel *label_3;
    QLineEdit *txtNombre;
    QLabel *label_4;
    QComboBox *cmbCategoria;
    QLabel *label_5;
    QLineEdit *txtPrecio;
    QLabel *label_6;
    QLineEdit *txtStock;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnGuardar;
    QPushButton *btnEditar;
    QPushButton *btnBuscar;
    QPushButton *btnEliminar;
    QPushButton *btnLimpiar;
    QTableWidget *tblProductos;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1103, 688);
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(14);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(170, 20, 821, 601));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        lblTitulo = new QLabel(widget);
        lblTitulo->setObjectName("lblTitulo");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(18);
        lblTitulo->setFont(font1);

        gridLayout->addWidget(lblTitulo, 0, 1, 1, 1);

        txtCodigo = new QLineEdit(widget);
        txtCodigo->setObjectName("txtCodigo");

        gridLayout->addWidget(txtCodigo, 1, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        txtNombre = new QLineEdit(widget);
        txtNombre->setObjectName("txtNombre");

        gridLayout->addWidget(txtNombre, 2, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        cmbCategoria = new QComboBox(widget);
        cmbCategoria->addItem(QString());
        cmbCategoria->addItem(QString());
        cmbCategoria->addItem(QString());
        cmbCategoria->addItem(QString());
        cmbCategoria->addItem(QString());
        cmbCategoria->addItem(QString());
        cmbCategoria->setObjectName("cmbCategoria");

        gridLayout->addWidget(cmbCategoria, 3, 1, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        txtPrecio = new QLineEdit(widget);
        txtPrecio->setObjectName("txtPrecio");

        gridLayout->addWidget(txtPrecio, 4, 1, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        txtStock = new QLineEdit(widget);
        txtStock->setObjectName("txtStock");

        gridLayout->addWidget(txtStock, 5, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnGuardar = new QPushButton(widget);
        btnGuardar->setObjectName("btnGuardar");

        horizontalLayout->addWidget(btnGuardar);

        btnEditar = new QPushButton(widget);
        btnEditar->setObjectName("btnEditar");

        horizontalLayout->addWidget(btnEditar);

        btnBuscar = new QPushButton(widget);
        btnBuscar->setObjectName("btnBuscar");

        horizontalLayout->addWidget(btnBuscar);

        btnEliminar = new QPushButton(widget);
        btnEliminar->setObjectName("btnEliminar");

        horizontalLayout->addWidget(btnEliminar);

        btnLimpiar = new QPushButton(widget);
        btnLimpiar->setObjectName("btnLimpiar");

        horizontalLayout->addWidget(btnLimpiar);


        verticalLayout->addLayout(horizontalLayout);

        tblProductos = new QTableWidget(widget);
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

        verticalLayout->addWidget(tblProductos);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1103, 32));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lblTitulo->setText(QCoreApplication::translate("MainWindow", "GESTION DE CINE", nullptr));
        txtCodigo->setPlaceholderText(QCoreApplication::translate("MainWindow", "001", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Nombre:", nullptr));
        txtNombre->setText(QString());
        txtNombre->setPlaceholderText(QCoreApplication::translate("MainWindow", "Avatar", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Categoria:", nullptr));
        cmbCategoria->setItemText(0, QCoreApplication::translate("MainWindow", "Seleccione una categoria", nullptr));
        cmbCategoria->setItemText(1, QCoreApplication::translate("MainWindow", "Terror", nullptr));
        cmbCategoria->setItemText(2, QCoreApplication::translate("MainWindow", "Comedia", nullptr));
        cmbCategoria->setItemText(3, QCoreApplication::translate("MainWindow", "Accion", nullptr));
        cmbCategoria->setItemText(4, QCoreApplication::translate("MainWindow", "Drama", nullptr));
        cmbCategoria->setItemText(5, QCoreApplication::translate("MainWindow", "Ciencia Ficcion", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "Precio:", nullptr));
        txtPrecio->setText(QString());
        txtPrecio->setPlaceholderText(QCoreApplication::translate("MainWindow", "7.50", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Stock:", nullptr));
        txtStock->setText(QString());
        txtStock->setPlaceholderText(QCoreApplication::translate("MainWindow", "25", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Codigo:", nullptr));
        btnGuardar->setText(QCoreApplication::translate("MainWindow", "Guardar", nullptr));
        btnEditar->setText(QCoreApplication::translate("MainWindow", "Editar", nullptr));
        btnBuscar->setText(QCoreApplication::translate("MainWindow", "Buscar", nullptr));
        btnEliminar->setText(QCoreApplication::translate("MainWindow", "Eliminar", nullptr));
        btnLimpiar->setText(QCoreApplication::translate("MainWindow", "Limpiar", nullptr));
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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
