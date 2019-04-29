#include <iostream>
#include "chango.hpp"
#include "gondola.hpp"
#include "producto.hpp"

using namespace std;

Chango::Chango(){
    productoEnChango = new Producto [50];
    cantProductos = 0;
}

void Chango::agregarAlChango(Gondola& nuevaGondola){
    Producto* listaDeProducto = nuevaGondola.recuperarListaDeProducto();
    int continuar = 0;
    int i;
    bool esta = false;
    do{
    nuevaGondola.mostrar();
        do{
            cout << "Selecciona un producto: " << endl;
            cin >> i; 
        }while (i >= nuevaGondola.recuperarCantProd());
        if (cantProductos == 0){
            productoEnChango[cantProductos].ingresarNombre(listaDeProducto[i].recuperarNombre());
            productoEnChango[cantProductos].ingresarCod_b(listaDeProducto[i].recuperarCod_b());
            productoEnChango[cantProductos].ingresarPrecio(listaDeProducto[i].recuperarPrecio());
            bool oferta =  listaDeProducto[i].recuperarOferta();
            if (oferta){
                productoEnChango[cantProductos].ingresarOferta(1);
            }else
                productoEnChango[cantProductos].ingresarOferta(0);
            productoEnChango[cantProductos].ingresarCant(1);
            cantProductos = 1;
        }else{
            for(int j = 0; j < cantProductos; j++){
                if(productoEnChango[j].recuperarNombre() == listaDeProducto[i].recuperarNombre()){
                    productoEnChango[j].ingresarCant(1);
                    esta = true;  
                }
            }
            if (!esta){
                productoEnChango[cantProductos].ingresarNombre(listaDeProducto[i].recuperarNombre());
                productoEnChango[cantProductos].ingresarCod_b(listaDeProducto[i].recuperarCod_b());
                productoEnChango[cantProductos].ingresarPrecio(listaDeProducto[i].recuperarPrecio());
                bool oferta =  listaDeProducto[i].recuperarOferta();
                if (oferta){
                    productoEnChango[cantProductos].ingresarOferta(1);
                }else
                    productoEnChango[cantProductos].ingresarOferta(0);
                productoEnChango[cantProductos].ingresarCant(1);
                cantProductos++;
            }
        }
        mostrar();
        cout << "¿Agregar mas productos? Si=1, No=0" << endl;
        cin >> continuar;
    }while (continuar == 1);
    ahorroYTotal();
}

void Chango::ahorroYTotal(){
    double total = 0;
    double ahorro = 0;
    for(int i=0;i<cantProductos;i++){
        total = total + (double)productoEnChango[i].recuperarPrecio()*productoEnChango[i].recuperarCant();
        if(productoEnChango[i].recuperarOferta()){
            ahorro = ahorro + (productoEnChango[i].recuperarCant()*((productoEnChango[i].recuperarPrecio())*10.0)/100.0);
        }
    }
    cout<<"Total a pagar: "<<(total-ahorro)<<" Ahorro: "<<ahorro<<endl;
}

void Chango::mostrar(){
    cout << "********************************************************************\n";
    for (int i = 0; i < cantProductos; i++)
    {
        cout<<i<<" - ";
        cout<<"Nombre: "<<productoEnChango[i].recuperarNombre()<<" - ";
        cout<<"Codigo de barra: "<<productoEnChango[i].recuperarCod_b()<<" - ";
        cout<<"Precio: "<<productoEnChango[i].recuperarPrecio()<<" - ";
        if(productoEnChango[i].recuperarOferta()){
            cout<<"En oferta: si"<<endl;
        }else{cout<<"En oferta: no"<<endl;}
    }
    cout << "********************************************************************\n";
}
