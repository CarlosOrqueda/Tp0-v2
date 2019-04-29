#ifndef CHANGO_H_INCLUDED
#define CHANGO_H_INCLUDED
#include "stock.hpp"
#include "gondola.hpp"

class Chango: public Stock{

    private:
        void ahorroYTotal();

    public:
        Chango(int x, int y);
        void agregarAlChango(Gondola& nuevaGondola);
};
#endif // CHANGO_H_INCLUDED
