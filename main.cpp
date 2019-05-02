#include <iostream>
#include "menu.hpp"
#include "gondola.hpp"
#include "chango.hpp"
#include <fstream>
using namespace std;

int main(){
    Gondola nuevaGondola; //Gondola unaGondola(50,0);
    nuevaGondola.leer();
    Chango nuevoChango;
    Menu nuevoMenu;
    while (!nuevoMenu.obtenerSalir())
    {
        nuevoMenu.mostrarMenu(nuevaGondola, nuevoChango);
    }
    cout<<"este cambio es re piola"<<endl
    return 0;
}
