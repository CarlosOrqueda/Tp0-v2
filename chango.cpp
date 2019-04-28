#include <iostream>
#include "chango.hpp"
#include "gondola.hpp"
#include "producto.hpp"

using namespace std;

Chango::Chango(){
    productoEnChango = new Producto [50];
    cantProductos = -1;
}

void Chango::agregarAlChango(Gondola& nuevaGondola){
    int cargar = 1;
    while(cargar!=0){
        int pos = nuevaGondola.buscarPorNombre();
        verificarProdChango(pos,nuevaGondola);
        mostrar();
        cout<<"¿Seguir cargando? Si=1 , No=0"<<endl;
        cin>>cargar;
    }
    ahorroYTotal();
}

void Chango::verificarProdChango(int pos,Gondola nuevaGondola){
    Producto* listaDeProducto = nuevaGondola.recuperarListaDeProducto();
    Producto prodAux;
    if(cantProductos == -1){
        prodAux.ingresarNombre(listaDeProducto[pos].recuperarNombre());
        prodAux.ingresarCod_b(listaDeProducto[pos].recuperarCod_b());
        prodAux.ingresarPrecio(listaDeProducto[pos].recuperarPrecio());
        bool oferta =  listaDeProducto[pos].recuperarOferta();
        if (oferta){
            prodAux.ingresarOferta(1);
        }else{prodAux.ingresarOferta(0);}
        cantProductos = 1;
        productoEnChango[0] = prodAux;
    }else{
        for(int i = 0; i < cantProductos; i++){
            if(productoEnChango[i].recuperarNombre() == listaDeProducto[pos].recuperarNombre())
                productoEnChango[i].ingresarCant(1);
            else{
                prodAux.ingresarNombre(listaDeProducto[pos].recuperarNombre());
                prodAux.ingresarCod_b(listaDeProducto[pos].recuperarCod_b());
                prodAux.ingresarPrecio(listaDeProducto[pos].recuperarPrecio());
                bool oferta =  listaDeProducto[pos].recuperarOferta();
                if (oferta){
                    prodAux.ingresarOferta(1);
                }else{prodAux.ingresarOferta(0);}
                prodAux.ingresarCant(1);
                cantProductos ++;
                productoEnChango[i++] = prodAux;
            }
        }
    }
}

void Chango::ahorroYTotal(){
    float total = 0;
    float ahorro = 0;
    for(int i=0;i<cantProductos;i++){
        total = total + productoEnChango[i].recuperarPrecio();
        if(productoEnChango[i].recuperarOferta()){
            ahorro = ahorro + (productoEnChango[i].recuperarCant()*((productoEnChango[i].recuperarPrecio())*10)/100);
        }
    }
    cout<<"Total a pagar: "<<(total-ahorro)<<" Ahorro: "<<ahorro<<endl;
}

void Chango::mostrar(){
    cout << "************************************************\n";
    for (int i = 0; i < cantProductos; i++)
    {
        cout<<"Nombre: "<<productoEnChango[i].recuperarNombre()<<" ";
        cout<<"Codigo de barra: "<<productoEnChango[i].recuperarCod_b()<<" ";
        cout<<"Precio: "<<productoEnChango[i].recuperarPrecio()<<" ";
        if(productoEnChango[i].recuperarOferta()){
            cout<<"En oferta: si"<<endl;
        }else{cout<<"En oferta: no"<<endl;}
    }
    cout << "************************************************\n";
}
