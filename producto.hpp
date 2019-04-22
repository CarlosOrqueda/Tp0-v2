#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

#include <string>

using namespace std;

class Producto{
    private:
        string nombre;
        int cod_b;
        int cant;
        float precio;
        bool oferta;

    public:
        Producto(string,int,int,float,int);
        Producto();
        void ingresarNombre(string);
        string recuperarNombre();
        void ingresarCod_b(int);
        int recuperarCod_b();
        void ingresarCant(int);
        int recuperarCant();
        void ingresarPrecio(float);
        float recuperarPrecio();
        void ingresarOferta(int);
        bool recuperarOferta();
};

#endif // PRODUCTO_H_INCLUDED
