#ifndef FACTURA_H
#define FACTURA_H

//
//
// Proyecto Proveedora Factura
//
// José Ángel Rico Mendieta
//
// A01707404
// 
// 27/05/2021
//
// Clase Factura, es cuando la compra
// Se relaciona con un cliente para su
// facturación. 
//
//

#include "Cliente.h"
#include "Ticket.h"
#include <sstream>
#include <string>
using namespace std;

class Factura{
        private:
                int id;
                Ticket ticket;
                Cliente*cliente;
	public:
                Factura(){}
                Factura(int _id, Ticket _ticket, Cliente*_cliente){
                        id = _id;
                        ticket = _ticket;
                        cliente = _cliente;
                }
                Ticket getTicket(){ return ticket;}
                string printFactura();
                string printListaFactura();
};

string Factura::printListaFactura(){
        stringstream aux;
        aux << "\n" << id << "\t" << cliente->getNombre() << "\t" << ticket.calcularTotal();
        return aux.str();
}

string Factura::printFactura(){
        stringstream aux;
        aux << "\n***********************************" 
            << "\nId de Factura:" << id 
            << "\nCliente: " << cliente->getNombre()
            << ticket.printTicket();
        return aux.str();
}

#endif