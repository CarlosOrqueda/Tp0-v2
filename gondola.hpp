#ifndef GONDOLA_H_INCLUDED
#define GONDOLA_H_INCLUDED

#include <fstream>
#include "producto.hpp"
#include "stock.hpp"

class Gondola : public Stock{
    private:
        void cargarGondola(ifstream& gondola);

    public:
        /**PRE: Clase gondola instanciada correctamente
         * POST: Carga el arreglo de productos de la gondola.
         */
        void leer();
        /**PRE: compara el string con los nombres del objeto gondola
         * POST: retorna la posicion y si no lo encuentra retorna un 51
         */
        int buscarPorNombre();
        /**PRE: compara el string con los nombres del objeto gondola
         * POST: retorna la posicion y si no lo encuentra retorna un 51
         */
        int buscarPorCodB();
        /**PRE: compara el string con los codigos del objeto gondola
         * POST: modifica el precio del producto encontrado
         */
        void modificarPrecio();
        void quitarProducto();
        void cantidadProdOferta();
        void agregarProductoGondola();
        void cargarInventario();
        void mostrarGondola();
};

#endif // GONDOLA_H_INCLUDED
