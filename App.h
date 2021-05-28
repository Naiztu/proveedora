#ifndef APP_H
#define APP_H

//
//
// Proyecto Proveedora main
//
// José Ángel Rico Mendieta
//
// A01707404
// 
// 27/05/2021
//
// Clase App, tendra todas las funcionalidades para que el programa
// sea ejecutada desde el main
//
//

#include "Personal.h"
#include "Proveedor.h"
#include "Cliente.h"
#include "Cajero.h"
#include <vector>
#include <iostream>
using namespace std;

class App{
    private:
        vector<Personal*> personal;
        int numInt=1000;
        int menu();
        void generarEjemplos();
        void agregaPersonal(int);
        void verPersonal(string);
        void listaPersonal(string);
    public:
        App(){}
        ~App();
        void start();
};

App::~App() {
    for (Personal *aux : personal) {
        delete aux;
    }
}

void App::start(){
    generarEjemplos();
    int op = 0;
    do{
        op = menu();
        switch(op){
            case 1: 
                cout << "\n*******************************************";
	            cout << "\n*           Agregar Cliente               *";
                cout << "\n*******************************************\n";
                agregaPersonal(1);
                break;
            case 2: 
                cout << "\n*******************************************";
	            cout << "\n*           Agregar Proveedor             *";
                cout << "\n*******************************************\n";
                agregaPersonal(2);
                break;
            case 3: 
                cout << "\n*******************************************";
	            cout << "\n*            Agregar Cajero               *";
                cout << "\n*******************************************\n";
                agregaPersonal(3);
                break;
            case 4: 
                cout << "\n*******************************************";
	            cout << "\n*              Ver Cliente                *";
                cout << "\n*******************************************\n";
                verPersonal("Cliente");
                break;
            case 5: 
                cout << "\n*******************************************";
	            cout << "\n*             Ver Proveedor               *";
                cout << "\n*******************************************\n";
                verPersonal("Proveedor");
                break;
            case 6: 
                cout << "\n*******************************************";
	            cout << "\n*              Ver Cajeros                *";
                cout << "\n*******************************************\n";
                verPersonal("Cajero");
                break;
            case 7: 
                cout << "\n*******************************************";
	            cout << "\n*            Lista Clientes               *";
                cout << "\n*******************************************\n";
                listaPersonal("Cliente");
                break;
            case 8: 
                cout << "\n*******************************************";
	            cout << "\n*          Lista Proveedores              *";
                cout << "\n*******************************************\n";
                listaPersonal("Proveedor");
                break;
            case 9: 
                cout << "\n*******************************************";
	            cout << "\n*             Lista Cajeros               *";
                cout << "\n*******************************************\n";
                listaPersonal("Cajero");
                break;
            default:
                cout << "\n*******************************************";
	            cout << "\n*            ¡¡¡Adios!!!               *";
                cout << "\n*******************************************\n";
        }
    }while(op!=10);
}

int App::menu(){
    bool ban = true;
    int op=0; 

    while (ban){

        cout << "\n*******************************************";
        cout << "\n                MENU:\n";
        cout << "*******************************************\n";
        cout << "1. Agregar Cliente. \n";
        cout << "2. Agregar Proveedor. \n";
        cout << "3. Agregar Cajero. \n";
        cout << "4. Ver Cliente \n";
        cout << "5. Ver Proveedor \n";
        cout << "6. Ver Cajero \n";
        cout << "7. Lista Clientes \n";
        cout << "8. Lista Proveedores \n";
        cout << "9. Lista Cajeros \n";
        cout << "10. Salir \n";
        cout << "*******************************************\n";
        
        cout << "\nOpción: "; cin>>op;

        if ((op>=1)&&(op<=10)){
            ban = false;
        }else{
            cout << "\n   ¡¡¡Introduce una opción valida!!! \n";
        }
    } 

    return op;
}

void App::generarEjemplos(){
    personal.push_back(new Cajero(personal.size()+numInt, "Andy", "andy@gmail.com", "av. yucatan #56", "9991255323", 18.3));
    personal.push_back(new Cajero(personal.size()+numInt, "Fermin", "fer@gmail.com", "av. queretaro #434", "422868357", 18.5));

    personal.push_back(new Proveedor(personal.size()+numInt, "Yose", "yose@gmail.com", "av. ejidal #124", "4611255323", "Cuplasa"));
    personal.push_back(new Proveedor(personal.size()+numInt, "Lucero", "lucy@gmail.com", "av. Lopes #863", "4615673432", "Gorila"));

    personal.push_back(new Cliente(personal.size()+numInt, "Sam", "sam@gmail.com", "av. Tecnologico #76", "422967578", "3S4A5M7"));
    personal.push_back(new Cliente(personal.size()+numInt, "Lili", "lili@gmail.com", "av. alemania #812", "461737783", "L9I4L3I9"));
    personal.push_back(new Cliente(personal.size()+numInt, "Carlos", "carlitos@hotmail.com", "av. mexico #346", "462461542", "C8A2RL5O6S"));
    personal.push_back(new Cliente(personal.size()+numInt, "Juan", "juanin@gmail.com", "av. japon #861", "422346781", "J8U9A6N"));
    personal.push_back(new Cliente(personal.size()+numInt, "Diego", "diegin@gmail.com", "av. celaya #413", "461523563", "D1I2E3G4O"));
}

void App::verPersonal(string tipo){
    int id;
    bool ban = true;
	cout << "\nID: "; cin >> id;
    vector<Personal*>::const_iterator i;
    for(i= personal.begin(); i<personal.end(); ++i){
        if (((*i)->getTipo()==tipo)&&((*i)->getId()==id)){
            (*i)->printPersonal();
            ban = false;
            break;
        }
    }
    if (ban){
        cout << "\n       ¡¡¡NO ENCONTRADO!!!\n";
    }
    cout << "\n";
}

void App::listaPersonal(string tipo){
    cout << "\nID\tNombre";
    vector<Personal*>::const_iterator i;
    for(i= personal.begin(); i<personal.end(); ++i){
        if ((*i)->getTipo()==tipo){
            (*i)->printListaPersonal();
        }
    }
    cout << "\n";
}

void App::agregaPersonal(int op){
    string nombre, correo, direccion, RFC, empresa, numeroTel;
	double salario;
	cout << "\nNombre: "; cin >> nombre;
	cout << "\nCorreo: "; cin >> correo;
	cout << "\nDirección: "; cin >> direccion;
	cout << "\nTelefono: "; cin >> numeroTel;
    switch(op){
        case 1:
            cout << "\nRFC: "; cin >> RFC;
            personal.push_back(new Cliente(personal.size()+numInt, nombre, correo, direccion, numeroTel, RFC));
            break;
        case 2:
            cout << "\nEmpresa: "; cin >> empresa;
            personal.push_back(new Proveedor(personal.size()+numInt, nombre, correo, direccion, numeroTel, empresa));
            break;
        case 3:
            cout << "\nSalario p/Hr: "; cin >> salario;
            personal.push_back(new Cajero(personal.size()+numInt, nombre, correo, direccion, numeroTel, salario));
            break; 
    }
    cout << "\n\n   ID ASIGNADO: "<<personal.size()+numInt-1<<"\n";
    cout << "\n       ¡¡¡AGREGADO CON EXITO!!!\n";
}

#endif