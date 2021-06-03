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
        double total;
        Cajero cajero;
        vector<Subproducto> lista;
        double calcularTotal();
	public:
        Ticket(){}
        Ticket(int _id, string _fecha, Cajero _cajero, vector<Subproducto> _lista){
            id = _id;
            fecha = _fecha;
            cajero = _cajero;
            lista = _lista;
            total = calcularTotal();
        }		
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
        vector<Subproducto*>::const_iterator i;
        for(i= lista.begin(); i<lista.end(); ++i){
                aux += (*i)->getSubtotal;
        }
        return aux;
}

#endif