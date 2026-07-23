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

    // --- NUEVO ---
    void guardarVenta();
    void editarVenta();
    void eliminarVenta();
    void limpiarFormularioVenta();
    void seleccionarVenta(int fila, int columna);
    void actualizarPrecioEnPantalla();      // recalcula en vivo al cambiar combos
private:
    Ui::MainWindow *ui;
    QVector<Producto> productos;
    QVector<Venta> ventas;                 // <-- NUEVO
    int indiceSeleccionado;
    int indiceVentaSeleccionado;           // <-- NUEVO
    bool validarFormulario();
    int buscarIndicePorCodigo(int codigo);
    void actualizarTabla();
    void guardarProductosEnArchivo();
    void cargarProductosDesdeArchivo();

    // --- NUEVO: CRUD de ventas ---
    void llenarComboPeliculas();
    double calcularPrecioFinal();
    void actualizarTablaVentas();
    void guardarVentasEnArchivo();
    void cargarVentasDesdeArchivo();
};
#endif // MAINWINDOW_H