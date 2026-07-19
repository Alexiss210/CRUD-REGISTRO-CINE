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
#endif // REGISTRO_H
