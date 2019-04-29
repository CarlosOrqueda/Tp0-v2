#ifndef STOCK_H_INCLUDED
#define STOCK_H_INCLUDED
#include <iostream>
#include <fstream>
#include "producto.hpp"
#include <string>

class Stock{
    private:
        Producto* producto;
        int cantProductos;
    public:
        Stock(int x,int y);
        void mostrar(Producto* producto);
        int recuperarCantProd();
        void sumarCantProd(int cantProductos);
        Producto* recuperarListaDeProducto();
};

#endif //STOCK_H_INCLUDED