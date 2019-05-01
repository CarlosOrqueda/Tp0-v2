#ifndef CHANGO_H_INCLUDED
#define CHANGO_H_INCLUDED
#include "stock.hpp"
#include "gondola.hpp"

class Chango: public Stock{

    private:
        void ahorroYTotal();

    public:
        //pre: recibe el objeto Gondola por referencia
        //post: agrega un producto de gondola al objeto chango 
        void agregarAlChango(Gondola& nuevaGondola);
};
#endif // CHANGO_H_INCLUDED
