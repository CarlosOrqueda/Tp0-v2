#include <iostream>
#include "chango.hpp"
#include "gondola.hpp"
#include "producto.hpp"

using namespace std;

Chango::Chango(){
    productoEnChango = new Producto [50];
    cantProductosEnChango = -1;
}

void Chango::agregarAlChango(Gondola& nuevaGondola){
    mostrar();
    int cargar = 1;
    while(cargar!=0){
        int pos = nuevaGondola.buscarPorNombre();
        verificarProdChango(pos,nuevaGondola);
        cout<<"¿Seguir cargando? Si=1 , No=0"<<endl;
        cin>>cargar;
    }
    ahorroYTotal();
}

void Chango::verificarProdChango(int pos,Gondola nuevaGondola){
    Producto* listaDeProducto = nuevaGondola.recuperarProducto();
    Producto prodAux;
    if(cantProductosEnChango == -1){
        prodAux.ingresarNombre(listaDeProducto[pos].recuperarNombre());
        prodAux.ingresarCod_b(listaDeProducto[pos].recuperarCod_b());
        prodAux.ingresarPrecio(listaDeProducto[pos].recuperarPrecio());
        bool oferta =  listaDeProducto[pos].recuperarOferta();
        if (oferta){
            prodAux.ingresarOferta(1);
        }else{prodAux.ingresarOferta(0);}
        cantProductosEnChango = 1;
        productoEnChango[0] = prodAux;
    }else{
        for(int i = 0; i < cantProductosEnChango; i++){
            switch(productoEnChango[i].recuperarNombre().compare(listaDeProducto[pos].recuperarNombre())){
            case 0:
                productoEnChango[i].ingresarCant(1);
                break;
            default:
                prodAux.ingresarNombre(listaDeProducto[pos].recuperarNombre());
                prodAux.ingresarCod_b(listaDeProducto[pos].recuperarCod_b());
                prodAux.ingresarPrecio(listaDeProducto[pos].recuperarPrecio());
                bool oferta =  listaDeProducto[pos].recuperarOferta();
                if (oferta){
                    prodAux.ingresarOferta(1);
                }else{prodAux.ingresarOferta(0);}
                prodAux.ingresarCant(1);
                cantProductosEnChango ++;
                productoEnChango[i++] = prodAux;
            }
        }
    }
}

void Chango::ahorroYTotal(){
    float total = 0;
    float ahorro = 0;
    for(int i=0;i<cantProductosEnChango;i++){
        total = total + productoEnChango[i].recuperarPrecio();
        if(productoEnChango[i].recuperarOferta()){
            ahorro = ahorro + (productoEnChango[i].recuperarCant()*((productoEnChango[i].recuperarPrecio())*10)/100);
        }
    }
    cout<<"Total a pagar: "<<(total-ahorro)<<" Ahorro: "<<ahorro<<endl;
}

void Chango::mostrar(){
    for (int i = 0; i < cantProductosEnChango; i++)
    {
        cout<<productoEnChango[i].recuperarNombre()<<endl;
        cout<<productoEnChango[i].recuperarCod_b()<<endl;
        cout<<productoEnChango[i].recuperarPrecio()<<endl;
        if(productoEnChango[i].recuperarOferta()){
            cout<<"En oferta: si"<<endl;
        }else{cout<<"En oferta: no"<<endl;}
    }
}
