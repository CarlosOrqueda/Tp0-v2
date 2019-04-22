#include <iostream>
#include "gondola.hpp"
#include "chango.hpp"

using namespace std;

int main(){
    Gondola nuevaGondola;
    nuevaGondola.leer();
    Chango nuevoChango;

    int opcion=0;
    while(opcion!=8){
        cout<<"1) Buscar producto por nombre"<<endl;
        cout<<"2) Buscar producto por codigo de barras"<<endl;
        cout<<"3) Modificar precio de un producto"<<endl;
        cout<<"4) Quitar producto de la gondola"<<endl;
        cout<<"5) Cantidad de productos en oferta"<<endl;
        cout<<"6) Agregar productos al chango"<<endl;
        cout<<"7) Agregar productos a la gondola"<<endl;
        cout<<"8) Salir"<<endl;
        cout<<"Ingrese opcion: ";
        cin>>opcion;

        switch(opcion){
            case 1:{
                int pos_nombre = nuevaGondola.buscarPorNombre();
                if(pos_nombre<50){
                    Producto* estante = nuevaGondola.recuperarProducto();
                    cout<<"El producto existe: "<<estante[pos_nombre].recuperarNombre()<<endl;
                    cout<<estante[pos_nombre].recuperarCod_b()<<endl;
                    cout<<estante[pos_nombre].recuperarPrecio()<<endl;
                    if(estante[pos_nombre].recuperarOferta()){
                         cout<<"En oferta: si"<<endl;
                        }else{cout<<"En oferta: no"<<endl;}
                }else{
                    cout<<"No existe el producto"<<endl;
                }
            break;
            }
            case 2:{
                int pos_cod = nuevaGondola.buscarPorCodB();
                if(pos_cod<50){
                    Producto* estante = nuevaGondola.recuperarProducto();
                    cout<<"El producto existe: "<<estante[pos_cod].recuperarNombre()<<endl;
                    cout<<estante[pos_cod].recuperarCod_b()<<endl;
                    cout<<estante[pos_cod].recuperarPrecio()<<endl;
                    if(estante[pos_cod].recuperarOferta()){
                         cout<<"En oferta: si"<<endl;
                        }else{cout<<"En oferta: no"<<endl;}
                }else{
                    cout<<"No existe el producto"<<endl;
                }
            break;
            }
            case 3:
                nuevaGondola.modificarPrecio();
            break;
            case 4:
                nuevaGondola.quitarProducto();
            break;
            case 5:
                nuevaGondola.cantidadProdOferta();
            break;
            case 6:
                nuevoChango.agregarAlChango(nuevaGondola);
            break;
            case 7:
                nuevaGondola.agregarProductoGondola();
            break;
            default:
                if(opcion<1||opcion>8){
                    cout<<"Opcion no valida"<<endl;
                }
        }
    }
    nuevaGondola.cargarInventario();

    return 0;
}
