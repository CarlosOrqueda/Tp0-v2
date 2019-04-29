#include "chango.hpp"
#include "stock.hpp"
#include "gondola.hpp"
#include <iostream>
using namespace std;

Chango::Chango(int x, int y) : Stock(x,y){
    
}

void Chango::agregarAlChango(Gondola& nuevaGondola){
    Producto* listaDeProducto = nuevaGondola.recuperarListaDeProducto();
    int continuar = 0;
    int i;
    bool esta = false;
    int cantidadDeProductos = recuperarCantProd();
    Producto* productoEnChango = recuperarListaDeProducto();
    do{
    mostrar(listaDeProducto);
        do{
            cout << "Selecciona un producto: " << endl;
            cin >> i; 
        }while (i >= nuevaGondola.recuperarCantProd());
        if (cantidadDeProductos == 0){
            productoEnChango[cantidadDeProductos].ingresarNombre(listaDeProducto[i].recuperarNombre());
            productoEnChango[cantidadDeProductos].ingresarCod_b(listaDeProducto[i].recuperarCod_b());
            productoEnChango[cantidadDeProductos].ingresarPrecio(listaDeProducto[i].recuperarPrecio());
            bool oferta =  listaDeProducto[i].recuperarOferta();
            if (oferta){
                productoEnChango[cantidadDeProductos].ingresarOferta(1);
            }else
                productoEnChango[cantidadDeProductos].ingresarOferta(0);
            productoEnChango[cantidadDeProductos].ingresarCant(1);
            sumarCantProd(1);
        }else{
            for(int j = 0; j < cantidadDeProductos; j++){
                if(productoEnChango[j].recuperarNombre() == listaDeProducto[i].recuperarNombre()){
                    productoEnChango[j].ingresarCant(1);
                    esta = true;  
                }
            }
            if (!esta){
                productoEnChango[cantidadDeProductos].ingresarNombre(listaDeProducto[i].recuperarNombre());
                productoEnChango[cantidadDeProductos].ingresarCod_b(listaDeProducto[i].recuperarCod_b());
                productoEnChango[cantidadDeProductos].ingresarPrecio(listaDeProducto[i].recuperarPrecio());
                bool oferta =  listaDeProducto[i].recuperarOferta();
                if (oferta){
                    productoEnChango[cantidadDeProductos].ingresarOferta(1);
                }else
                    productoEnChango[cantidadDeProductos].ingresarOferta(0);
                productoEnChango[cantidadDeProductos].ingresarCant(1);
                sumarCantProd(1);
            }
        }
        mostrar(productoEnChango);
        cout << "¿Agregar mas productos? Si=1, No=0" << endl;
        cin >> continuar;
    }while (continuar == 1);
    ahorroYTotal();
}

void Chango::ahorroYTotal(){
    double total = 0;
    double ahorro = 0;
    Producto* productoEnChango = recuperarListaDeProducto();
    int cantidadDeProductos = recuperarCantProd();
    for(int i=0;i<cantidadDeProductos;i++){
        total = total + (double)productoEnChango[i].recuperarPrecio()*productoEnChango[i].recuperarCant();
        if(productoEnChango[i].recuperarOferta()){
            ahorro = ahorro + (productoEnChango[i].recuperarCant()*((productoEnChango[i].recuperarPrecio())*10.0)/100.0);
        }
    }
    cout<<"Total a pagar: "<<(total-ahorro)<<" Ahorro: "<<ahorro<<endl;
}
