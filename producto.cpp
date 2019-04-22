#include "producto.hpp"

Producto::Producto(string nombre, int cod_b, int cant, float precio, int oferta){
    this->nombre = nombre;
    this->cod_b = cod_b;
    this->cant = cant;
    this->precio = precio;
    if (oferta == 1){
        this->oferta = true;
    }else{
        this->oferta = false;
    }
}

Producto::Producto(){
    nombre = "";
    cod_b = 0;
    cant = 0;
    precio = 0.0;
    oferta = false;
}

void Producto::ingresarNombre(string nombre){
    this->nombre = nombre;
}

string Producto::recuperarNombre(){
    return this->nombre;
}

void Producto::ingresarCod_b(int cod_b){
    this->cod_b = cod_b;

}

int Producto::recuperarCod_b(){
    return cod_b;
}

void Producto::ingresarCant(int cant){
    this->cant += cant;
}

int Producto::recuperarCant(){
    return cant;
}

void Producto::ingresarPrecio(float precio){
    this->precio = precio;
}

float Producto::recuperarPrecio(){
    return precio;
}

void Producto::ingresarOferta(int oferta){
    if(oferta == 1){
        this->oferta = true;
    }else{
        this->oferta = false;
    }
}

bool Producto::recuperarOferta(){
    return this->oferta;
}
