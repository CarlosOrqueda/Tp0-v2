#include <iostream>
#include <string>
#include "stock.hpp"
#include "producto.hpp"
using namespace std;

int Stock::recuperarCantProd(){
    return cantProductos;
}

void Stock::mostrar(){
    cout << "********************************************************************\n";
    for (int i = 0; i < cantProductos; i++)
    {
        cout<<i<<" - ";
        cout<<"Nombre: "<<producto[i].recuperarNombre()<<" - ";
        cout<<"Codigo de barra: "<<producto[i].recuperarCod_b()<<" - ";
        cout<<"Precio: "<<producto[i].recuperarPrecio()<<" - ";
        if(producto[i].recuperarOferta()){
            cout<<"En oferta: si"<<endl;
        }else{cout<<"En oferta: no"<<endl;}
    }
    cout << "********************************************************************\n";
}

Stock::Stock(){
    producto = new Producto [50];
    cantProductos = 0;
}

void Stock::sumarCantProd(int cantProductos){
    this -> cantProductos += cantProductos;
}

//Devuelve el vector de 50 objetos tipo Producto
Producto* Stock::recuperarListaDeProducto(){
    return producto;
}
Stock::~Stock(){
    delete []producto;
}
