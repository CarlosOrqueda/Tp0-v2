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
        //Constructor
        Stock();
        //Desc: imprime los productos dentro del vector de clase Producto
        void mostrar();
        //pos: devuelve la cantidad de productos del vector de clase Producto
        int recuperarCantProd();
        //pre: cantidad de productos actual del vector de clase Producto
        void sumarCantProd(int cantProductos);
        //pos: devuelve el puntero al vector de clase producto
        Producto* recuperarListaDeProducto();
        //Destructor
        ~Stock();
};

#endif //STOCK_H_INCLUDED