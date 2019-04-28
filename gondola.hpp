#ifndef GONDOLA_H_INCLUDED
#define GONDOLA_H_INCLUDED

#include <fstream>
#include "producto.hpp"

class Gondola{
    private:
        Producto* producto;
        int cantProductos;

        void cargarGondola(ifstream&);

    public:
        Gondola();
        void mostrar();
        void leer();
        int recuperarCantProd();
        int buscarPorNombre();
        int buscarPorCodB();
        void modificarPrecio();
        void quitarProducto();
        void cantidadProdOferta();
        void agregarProductoGondola();
        void cargarInventario();
        Producto* recuperarListaDeProducto();
};

#endif // GONDOLA_H_INCLUDED
