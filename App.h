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
#include "Producto.h"
#include "Subproducto.h"
#include "Ticket.h"
#include "Factura.h"
#include <vector>
#include <iostream>
using namespace std;

class App{
    private:
        vector<Personal*> personal;
        vector<Producto*> productos;
        vector<Ticket*> tickets;
        vector<Factura*> facturas;
        int numInt=1000;
        int menu();
        void generarEjemplos();
        void agregaPersonal(int);
        void verPersonal(string);
        void listaPersonal(string);
        void listaProductos();
        void listaTickets();
        void listaFacturas();
        void venta(int);
        void agregaProdcuto();
        string tipoPer(int);
        bool validaOpcion(int, int, int);
        vector<Subproducto> listaSubproductos();
    public:
        App(){}
        ~App();
        void start();
};

App::~App(){
    for (Personal *aux : personal) {
        delete aux;
    }
    for (Producto *aux : productos) {
        delete aux;
    }
    for (Ticket *aux : tickets) {
        delete aux;
    }
    for (Factura *aux : facturas) {
        delete aux;
    }
}

/**
 * star()
 * 
 * Método que inicializa la ejecución 
 * del programa
 * @param
 * @return
 */
void App::start(){
    generarEjemplos();
    int op = 0, op2 = 0, op3 = 0;
    do{
        op = menu();
        bool ban = true;
        if ((op>=1)&&(op<=3)){
            while (ban){
                cout << "\n*******************************************";
                cout << "\n                Personal:\n";
                cout << "*******************************************\n";
                cout << "1. Cliente \n";
                cout << "2. Proveedor \n";
                cout << "3. Cajero \n";
                cout << "*******************************************\n";
                cout << "\nOpción: "; cin>>op2;
                ban = validaOpcion(op2,1,3);
            }
        }
        ban = true;
        cout << "\n*******************************************";
        switch(op){
            case 1:
                cout << "\n*           Agregar " << tipoPer(op2);
                cout << "\n*******************************************\n";
                agregaPersonal(op2);
                break;
            case 2: 
                cout << "\n*            Ver " << tipoPer(op2);
                cout << "\n*******************************************\n";
                verPersonal(tipoPer(op2));
                break;
            case 3: 
                cout << "\n*           Lista " << tipoPer(op2);
                cout << "\n*******************************************\n";
                listaPersonal(tipoPer(op2));
                break;
            case 4: 
                while (ban){
                    cout << "\n*              Venta:\n";
                    cout << "*******************************************\n";
                    cout << "1. Sin Factura\n";
                    cout << "2. Con Factura \n";
                    cout << "*******************************************\n";
                    cout << "\nOpción: "; cin>>op3;
                    ban = validaOpcion(op3,1,2);
                }
                venta(op3);
                break;
            case 5: 
                cout << "\n*           Agregar Producto";
                cout << "\n*******************************************\n";
                agregaProdcuto();
                break;
            case 6: 
                cout << "\n*            Lista Productos";
                cout << "\n*******************************************\n";
                listaProductos();
                break;
            case 7: 
                cout << "\n*            Lista Tickets";
                cout << "\n*******************************************\n";
                listaTickets();
                break;
            case 8: 
                cout << "\n*            Lista Facturas";
                cout << "\n*******************************************\n";
                listaFacturas();
                break;
            default:
	            cout << "\n*            ¡¡¡Adios!!!               *";
                cout << "\n*******************************************\n";
        }
    }while(op!=9);
}

/**
 * agregaProducto()
 * 
 * Método que agrega un producto al registro.
 * @param 
 * @return 
 */
void App::agregaProdcuto(){
    string nombre;
    int id;
    double precio;
    bool ban = true;
    cout <<"\nNombre: "; cin >> nombre;
    cout <<"\nPrecio: $"; cin >> precio;
    while (ban){
        cout << "\nId del Proveedor: "; cin>>id;
        for (Personal *i : personal){
            if ((i->getId()==id)&&(i->getTipo()=="Proveedor")){
                productos.push_back(new Producto(productos.size()+numInt, nombre, precio, (Proveedor*)i));
                cout << "\n       ¡¡¡AGREGADO CON EXITO!!!\n";
                ban = false;
            }
        }
        if(ban){
            cout << "\n   ¡¡¡Introduce una opción valida!!! \n";
        }
    }
    
}

/**
 * venta()
 * 
 * Método que agrega un ticket sin factura o con factura
 * @param int op Si es 1, es venta sin factura. Si es 2,
 *  es venta co factura.
 * @return 
 */
void App::venta(int op){
    int idC, id;
    bool ban=true;
    switch (op){
        case 1:
            while(ban){
                cout << "Id Cajero: "; cin >> idC;
                for(Personal *i : personal){
                    if ((i->getTipo()=="Cajero")&&(i->getId()==idC)){
                        tickets.push_back(new Ticket(tickets.size()+numInt, "03/06/2021", (Cajero*) i, listaSubproductos()));
                        cout << tickets[tickets.size()-1]->printTicket();
                        cout << "\nNombre\tCantidad\tPrecio\tSubtotal";
                        for(Subproducto k : tickets[tickets.size()-1]->getLista()){
                            cout<<k.printSubproducto();
                        }
                        ban = false;
                        break;
                    }
                }
                if(ban){
                cout << "\n   ¡¡¡Introduce una opción valida!!! \n";
                }
            }
            break;
        default:
            while(ban){
                cout << "Id Cajero: "; cin >> idC;
                for(Personal *i : personal){
                    if ((i->getTipo()=="Cajero")&&(i->getId()==idC)){
                        cout << "Id Cliente: "; cin >> id;
                        for(Personal *j : personal){
                            if ((j->getTipo()=="Cliente")&&(j->getId()==id)){
                                facturas.push_back(new Factura(facturas.size()+numInt,Ticket(tickets.size()+numInt, "03/06/2021", (Cajero*) i, listaSubproductos()), (Cliente*)j));
                                cout << facturas[facturas.size()-1]->printFactura();
                                cout << "\nNombre\tCantidad\tPrecio\tSubtotal";
                                for(Subproducto k : facturas[facturas.size()-1]->getTicket().getLista()){
                                    cout<<k.printSubproducto();
                                }
                                ban = false;
                                break;
                            }
                        }
                    }
                }
                if(ban){
                cout << "\n   ¡¡¡Introduce una opción valida!!! \n";
                }
            }
            break;
    }
    cout<<"\n";
}

/**
 * validaOpcion()
 * 
 * Metodo que valida la opcion escogida este dentro
 *  del rango asignado
 * @param int op opcion a evaluar
 *        int inf limite inferio
 *        int sup limite superior
 * @return bool que indicara si ya se cumple la condición
 */
bool App::validaOpcion(int op,int inf, int sup){
    bool ban = true;
    if ((op>=inf)&&(op<=sup)){
        ban = false;
    }else{
        cout << "\n   ¡¡¡Introduce una opción valida!!! \n";
    }
    return ban;
}

/**
 * tipoPer()
 * 
 * Método que devuelve el personas escogido
 * marcado en numero a string
 * @param int num numero relacion con el tipo
 * de personal
 * @return string tipo de personal
 */
string App::tipoPer(int num){
    switch (num){
        case 1:
            return "Cliente";
            break;
        case 2:
            return "Proveedor";
            break;
        case 3:
            return "Cajero";
            break;
        default:
            break;
    }
}

/**
 * menu()
 * 
 * Método que presenta el menu para despues evaluar
 * la opción escogida, el cin>>op solo debe ser tecleado 
 * con numero enteros
 * @param
 * @return int op opcion elegida por el usuario
 */
int App::menu(){
    bool ban = true;
    int op=0; 

    while (ban){
        cout << "\n*******************************************";
        cout << "\n                MENU:\n";
        cout << "*******************************************\n";
        cout << "1. Agregar Personal \n";
        cout << "2. Ver Personal \n";
        cout << "3. Lista Personal \n";
        cout << "4. Hacer Venta (con/sin factura)\n";
        cout << "5. Agregar Producto\n";
        cout << "6. Lista Productos\n";
        cout << "7. Lista Tickets \n";
        cout << "8. Lista Facturas \n";
        cout << "9. Salir \n";
        cout << "*******************************************\n";
        
        cout << "\nOpción: "; cin>>op;
        ban = validaOpcion(op,1,9);
    } 

    return op;
}

/**
 * generarEjemplos()
 * 
 * Genera ejemplos predeterminados como 
 * base para el programa.
 * @param
 * @return
 */
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

    productos.push_back(new Producto(productos.size()+numInt, "Cubeta", 21.20, (Proveedor*)personal[2]));
    productos.push_back(new Producto(productos.size()+numInt, "Sarten", 130.10, (Proveedor*)personal[3]));

    vector<Subproducto> sub;
    sub.push_back(Subproducto(2, *productos[0]));
    sub.push_back(Subproducto(3, *productos[1]));
    tickets.push_back(new Ticket(tickets.size()+numInt, "03/06/2021", (Cajero*) personal[0], sub));
    vector<Subproducto> sub2;
    sub2.push_back(Subproducto(5, *productos[1]));
    sub2.push_back(Subproducto(2, *productos[0]));
    tickets.push_back(new Ticket(tickets.size()+numInt, "03/06/2021", (Cajero*) personal[1], sub2));

    facturas.push_back(new Factura(facturas.size()+numInt, Ticket(tickets.size()+numInt, "03/06/2021", (Cajero*) personal[1], sub2), (Cliente*)personal[4]));
    facturas.push_back(new Factura(facturas.size()+numInt, Ticket(tickets.size()+numInt, "03/06/2021", (Cajero*) personal[0], sub), (Cliente*)personal[4]));
}

/**
 * listaFacturas()
 * 
 * Método que presenta todos los facturas
 *  registrados.
 * @param
 * @return 
 */
void App::listaFacturas(){
    cout << "\nID\tCajero\tTotal";
    for(Factura *i : facturas){
        cout << i->printListaFactura();
    }
    cout << "\n";
}

/**
 * listaTickets()
 * 
 * Método que presenta todos los tickets
 *  registrados.
 * @param
 * @return 
 */
void App::listaTickets(){
    cout << "\nID\tFecha\t\tCajero\tTotal";
    for(Ticket *i : tickets){
        cout << i->printListaTicket();
    }
    cout << "\n";
}

/**
 * listaProducto()
 * 
 * Método que presenta todos los productos
 *  registrados.
 * @param
 * @return 
 */
void App::listaProductos(){
    cout << "\nID\tNombre\tPrecio\tProveedor";
    for(Producto *i : productos){
        cout << i->printProducto();
    }
    cout << "\n";
}

/**
 * listaSubproducto()
 * 
 * Método que ejecuta un loop de registro de
 * subproductos para un ticket.
 * @param
 * @return vector<Subproducto> lista de 
 *  subproducto.
 */
vector<Subproducto> App::listaSubproductos(){
    vector<Subproducto> subproducto;
    int id, cant;
    string op ="n";
    bool ban = true;
    do{
        while (ban){
            cout << "\nId del Producto: "; cin>>id;
            for (Producto *i : productos){
                if (i->getId()==id){
                    cout << "Cantidad: "; cin>>cant;
                    subproducto.push_back(Subproducto(cant, *i));
                    ban = false;
                }
            }
            if(ban){
                cout << "\n   ¡¡¡Introduce una opción valida!!! \n";
            }
        }
        cout << "Agregar otro producto(s/n): "; cin >> op;
        ban=true;
    }while(op=="s");
    return subproducto;
}

/**
 * verPersonal(string)
 * 
 * Busca por medio del ID al personal
 * que le pertenesca
 * @param string tipo las opciones del
 * parametro son: "Proveedor", "Cliente" o "Cajero"
 * @return
 */
void App::verPersonal(string tipo){
    int id;
    bool ban = true;
	cout << "\nID: "; cin >> id;
    for(Personal *i : personal){
        if ((i->getTipo()==tipo)&&(i->getId()==id)){
            cout << i->printPersonal();
            ban = false;
            break;
        }
    }
    if (ban){
        cout << "\n       ¡¡¡NO ENCONTRADO!!!\n";
    }
    cout << "\n";
}

/**
 * listaPersonal(string)
 * 
 * En lista todos los personales del tipo 
 * requerido al que pertenecen
 * @param string tipo las opciones del
 * parametro son: "Proveedor", "Cliente" o "Cajero"
 * @return
 */
void App::listaPersonal(string tipo){
    cout << "\nID\tNombre";
    for(Personal *i : personal){
        if (i->getTipo()==tipo){
            cout << i->printListaPersonal();
        }
    }
    cout << "\n";
}

/**
 * verPersonal(string)
 * 
 * Agrega un personal en el ambito
 * en que se requiera
 * @param int op tipo las opciones del
 * parametro son: 1 para Proveedor, 
 * 2 para Cliente o 3 para Cajero.
 * @return
 */
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