#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "gondola.hpp"
#include "chango.hpp"

class Menu{
private:
    int opcion;
    bool salir;

public:
    void mostrarMenu(Gondola&, Chango&);
    void ejecutarAccion(Gondola&, Chango&);
    bool obtenerSalir();
};


#endif // MENU_H_INCLUDED
