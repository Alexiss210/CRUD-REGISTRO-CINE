#ifndef REGISTRO_H
#define REGISTRO_H

#include <QString>

struct Producto
{
    int codigo;
    QString nombre;
    QString categoria;
    double precio;
    int stock;
};
struct Venta
{
    int id;
    QString pelicula;
    QString tipoCliente;   // "Adulto" o "Infantil"
    QString metodoPago;    // "Efectivo", "Tarjeta" o "Transferencia"
    double precioBase;
    double precioFinal;
};
#endif // REGISTRO_H
