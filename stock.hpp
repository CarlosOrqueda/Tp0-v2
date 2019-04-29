#ifndef STOCK_H_INCLUDED
#define STOCK_H_INCLUDED

#include <fstream>
#include "producto.hpp"

class Stock{
    private:
        Producto* producto;
        int cantProductos;
        void mostrar();
    public:
        int recuperarCantProd();
};

#endif //STOCK_H_INCLUDED