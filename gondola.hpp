#ifndef GONDOLA_H_INCLUDED
#define GONDOLA_H_INCLUDED

#include <fstream>
#include "producto.hpp"
#include "stock.hpp"

class Gondola : public Stock{
    private:
        void cargarGondola(ifstream& gondola);

    public:
        void leer();
        int buscarPorNombre();
        int buscarPorCodB();
        void modificarPrecio();
        void quitarProducto();
        void cantidadProdOferta();
        void agregarProductoGondola();
        void cargarInventario();
        void mostrarGondola();
};

#endif // GONDOLA_H_INCLUDED
