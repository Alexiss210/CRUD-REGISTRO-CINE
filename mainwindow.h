#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QVector>
#include "registro.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void guardarProducto();
    void editarProducto();
    void eliminarProducto();
    void buscarProducto();
    void limpiarFormulario();
    void seleccionarProducto(int fila, int columna);
private:
    Ui::MainWindow *ui;
    QVector<Producto> productos;
    int indiceSeleccionado;
    bool validarFormulario();
    int buscarIndicePorCodigo(int codigo);
    void actualizarTabla();
    void guardarProductosEnArchivo();
    void cargarProductosDesdeArchivo();
    void actualizarResumenRegistros();   // <-- LÍNEA NUEVA
};
#endif // MAINWINDOW_H