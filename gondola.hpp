#ifndef GONDOLA_H_INCLUDED
#define GONDOLA_H_INCLUDED

#include <fstream>
#include "producto.hpp"

class Gondola{
    private:
        Producto* producto;
        int cantProductos;

        void cargarGondola(ifstream&);
        void mostrar();

    public:
        Gondola();
        void leer();
        int buscarPorNombre();
        int buscarPorCodB();
        void modificarPrecio();
        void quitarProducto();
        void cantidadProdOferta();
        void agregarProductoGondola();
        void cargarInventario();
        Producto* recuperarProducto();
};

#endif // GONDOLA_H_INCLUDED
