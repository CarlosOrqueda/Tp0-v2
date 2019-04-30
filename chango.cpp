#include "chango.hpp"
#include "stock.hpp"
#include "gondola.hpp"
#include <iostream>
using namespace std;

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

            producto[cantProductos].ingresarNombre(listaDeProducto[i].recuperarNombre());
            cout << listaDeProducto[i].recuperarNombre();
            producto[cantProductos].ingresarCod_b(listaDeProducto[i].recuperarCod_b());
            producto[cantProductos].ingresarPrecio(listaDeProducto[i].recuperarPrecio());
            bool oferta =  listaDeProducto[i].recuperarOferta();
            if (oferta){
                producto[cantProductos].ingresarOferta(1);
            }else
                producto[cantProductos].ingresarOferta(0);
            producto[cantProductos].ingresarCant(1);
            sumarCantProd(1);
        }else{
            for(int j = 0; j < cantProductos; j++){
                if(producto[j].recuperarNombre() == listaDeProducto[i].recuperarNombre()){
                    producto[j].ingresarCant(1);
                    esta = true;  
                }
            }
            if (!esta){
                producto[cantProductos].ingresarNombre(listaDeProducto[i].recuperarNombre());
                producto[cantProductos].ingresarCod_b(listaDeProducto[i].recuperarCod_b());
                producto[cantProductos].ingresarPrecio(listaDeProducto[i].recuperarPrecio());
                bool oferta =  listaDeProducto[i].recuperarOferta();
                if (oferta){
                    producto[cantProductos].ingresarOferta(1);
                }else
                    producto[cantProductos].ingresarOferta(0);
                producto[cantProductos].ingresarCant(1);
                sumarCantProd(1);
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
    Producto* producto = recuperarListaDeProducto();
    int cantProductos = recuperarCantProd();
    for(int i=0;i<cantProductos;i++){
        total = total + (double)producto[i].recuperarPrecio()*producto[i].recuperarCant();
        if(producto[i].recuperarOferta()){
            ahorro = ahorro + (producto[i].recuperarCant()*((producto[i].recuperarPrecio())*10.0)/100.0);
        }
    }
    cout<<"Total a pagar: "<<(total-ahorro)<<" Ahorro: "<<ahorro<<endl;
}
