#ifndef CHANGO_H_INCLUDED
#define CHANGO_H_INCLUDED

#include "gondola.hpp"

class Chango{

    private:
        Producto* productoEnChango;
        int cantProductosEnChango;

        void mostrar();
        void verificarProdChango(int, Gondola);
        void ahorroYTotal();

    public:
        Chango();
        void agregarAlChango(Gondola&);
};
#endif // CHANGO_H_INCLUDED
