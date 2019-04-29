#include <iostream>
#include <string>
#include "stock.hpp"

using namespace std;

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

int Stock::recuperarCantProd(){
    return cantProductos;
}
