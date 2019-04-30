#ifndef STOCK_H_INCLUDED
#define STOCK_H_INCLUDED
#include <iostream>
#include <fstream>
#include "producto.hpp"
#include <string>

class Stock{
    protected:
        Producto* producto;
        int cantProductos;
    public:
        Stock();
        void mostrar();
        int recuperarCantProd();
        void sumarCantProd(int cantProductos);
        Producto* recuperarListaDeProducto();
        ~Stock();
};

#endif //STOCK_H_INCLUDED