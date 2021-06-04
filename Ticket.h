#ifndef TICKET_H
#define TICKET_H

//
//
// Proyecto Proveedora Ticket
//
// José Ángel Rico Mendieta
//
// A01707404
// 
// 27/05/2021
//
// Clase Ticket, registra la lista del producto
// el cajero que hizo la venta y el total de la misma
//
//

#include "Cajero.h"
#include "Subproducto.h"
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Ticket{
	private:
                int id;
                string fecha;
                Cajero*cajero;
                vector<Subproducto> lista;
                string auxiterator();
	public:
                Ticket(){}
                Ticket(int _id, string _fecha, Cajero*_cajero, vector<Subproducto> _lista){
                        id = _id;
                        fecha = _fecha;
                        cajero = _cajero;
                        lista = _lista;
                }
                double calcularTotal();	
                string printListaTicket();
                string printTicket();
                vector<Subproducto> getLista(){ return lista;}	
};

/**
 * calcularTotal()
 * 
 * Suma todos los subtotales de la lista
 * de productos comprados
 * @param
 * @return double aux para la suma de los
 * subtotales
 */
double Ticket::calcularTotal(){
        double aux=0.0;
        for(Subproducto i : lista){
                aux += i.calcularSubTotal();
        }
        return aux;
}

string Ticket::printListaTicket(){
        stringstream aux;
        aux << "\n" << id<< "\t" << fecha << "\t" << cajero->getNombre() <<"\t$" << calcularTotal();
        return aux.str();
}

string Ticket::printTicket(){
        stringstream aux;
        aux << "\n***********************************" 
            << "\nId:"<< id<< "\tFecha: " << fecha << "\n"
            << "Cajero: "<< cajero->getNombre() <<"\n"
            << "\t\tTotal: $"<< calcularTotal()
            << "\n***********************************n"; 
        return aux.str();
}

#endif