#include <iostream>
#include <fstream>
#include <string>
#include "gondola.hpp"

using namespace std;

Gondola::Gondola(){
    producto = new Producto [50];
    cantProductos = 0;
}

void Gondola::leer(){
    int opcion;
    ifstream gondola;
    gondola.open("gondola.txt");
    if (!gondola.is_open()){
        cout<<"Error al abrir el archivo"<<endl;
        cout<<"Desea crear uno nuevo Si = 1 No = 0"<<endl;
        cin>>opcion;
        if (opcion == 1){
            agregarProductoGondola();
            leer();}
    }else{
        cargarGondola(gondola);}
    mostrar();
}

void Gondola::cargarGondola(ifstream& gondola){
    string datoAux;
    while (!gondola.eof())
    {
        getline(gondola,datoAux,',');
        producto[cantProductos].ingresarNombre(datoAux);
        getline(gondola,datoAux,',');
        producto[cantProductos].ingresarCod_b(stoi(datoAux));
        getline(gondola,datoAux,',');
        producto[cantProductos].ingresarPrecio(stof(datoAux));
        getline(gondola,datoAux);
        producto[cantProductos].ingresarOferta(stoi(datoAux));
        cantProductos ++;
    }
    gondola.close();
}

void Gondola::mostrar(){
    for (int i = 0; i < cantProductos; i++)
    {
        cout<<producto[i].recuperarNombre()<<endl;
        cout<<producto[i].recuperarCod_b()<<endl;
        cout<<producto[i].recuperarPrecio()<<endl;
        if(producto[i].recuperarOferta()){
            cout<<"En oferta: si"<<endl;
        }else{cout<<"En oferta: no"<<endl;}
    }
}

int Gondola::buscarPorNombre(){
    string nombre;
    cout<<"Nombre del producto: ";
    cin>>nombre;
    for(int i=0; i < cantProductos; i++){
        if(producto[i].recuperarNombre().compare(nombre) == 0){
            return i;
        }
    }return 51;
}

int Gondola::buscarPorCodB(){
    string codigo_de_barras;
    cout<<"Codigo de barras del producto: ";
    cin>>codigo_de_barras;
    for(int i=0;i<cantProductos;i++){
        if(to_string(producto[i].recuperarCod_b()).compare(codigo_de_barras) == 0){
            return i;
        }
    }return 51;
}

void Gondola::modificarPrecio(){
    int pos;
    float n_precio;
    mostrar();
    pos = buscarPorNombre();
    cout<<"El precio del producto es: "<< producto[pos].recuperarPrecio()<<endl;
    cout<<"Ingrese el nuevo precio: ";
    cin>>n_precio;
    producto[pos].ingresarPrecio(n_precio);
}

void Gondola::quitarProducto(){
    mostrar();
    int pos = buscarPorNombre();
    Producto pAux = producto[cantProductos];
    producto[pos] = pAux;
    cantProductos --;
}

void Gondola::cantidadProdOferta(){
    int cant = 0;
    for(int i = 0; i < cantProductos; i++){
        if(producto[i].recuperarOferta())
            cant++;}
    cout<<"Hay "<< cant << " productos en oferta"<<endl;
}

void Gondola::agregarProductoGondola(){
    int opcion =1;
    while(opcion!=0){
        Producto nuevoProducto;
        string nombre;
        int cod;
        float precio;
        int oferta;
        cout<<"Ingrese nombre"<<endl;
        cin>>nombre;
        for(int i=0;i<cantProductos;i++){
            if(producto[i].recuperarNombre().compare(nombre)==0){
                cout<<"El producto existe"<<endl;
            }else{
                nuevoProducto.ingresarNombre(nombre);
                cout<<"Ingrese codigo de barras: ";
                cin>>cod;
                nuevoProducto.ingresarCod_b(cod);
                cout<<"Ingrese precio: ";
                cin>>precio;
                nuevoProducto.ingresarPrecio(precio);
                cout<<"Ingrese si esta en oferta Si=1 , No=0: ";
                cin>>oferta;
                nuevoProducto.ingresarOferta(oferta);
                producto[cantProductos] = nuevoProducto;
                cantProductos ++;
            }
        }
        cout<<"¿Cargar un nuevo producto? Si=1, No=0"<<endl;
        cin>>opcion;
    }
}

void Gondola::cargarInventario(){
    ofstream salida;
    salida.open("gondola.txt");
    if (!salida.is_open()) {
    cout << "Error de apertura"<<endl;
    return;
    }
    for (int i = 0; i < cantProductos; i++) {
        salida << producto[i].recuperarNombre();
        salida << ",";
        salida << producto[i].recuperarCod_b();
        salida << ",";
        salida << producto[i].recuperarPrecio();
        salida << ",";
        salida << producto[i].recuperarOferta();
        if (i + 1 != cantProductos) {
            salida << "\n";
        }
  }
  salida.close();
}
//Devuelve el vector de 50 objetos tipo Producto
Producto* Gondola::recuperarListaDeProducto(){
    return producto;
}
