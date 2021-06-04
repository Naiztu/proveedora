#ifndef SUBPRODUCTO_H
#define SUBPRODUCTO_H

//
//
// Proyecto Proveedora SubProducto
//
// José Ángel Rico Mendieta
//
// A01707404
// 
// 27/05/2021
//
// Clase SubProducto, registra los productos
// del ticket con su cantidad y subtotal
//
//

#include "Producto.h"
#include <sstream>
#include <string>
using namespace std;


class Subproducto{
        private:
                int cantidad;
                Producto producto;
        public:
                Subproducto(){}
                Subproducto(int _cantidad, Producto _producto){
                        cantidad = _cantidad;
                        producto = _producto;
                }
                double calcularSubTotal();
                int getCantidad(){ return cantidad;}
                Producto getProducto(){ return producto;}
                string printSubproducto();
};

/**
 * calcularSubTotal()
 * 
 * Multiplica la cantidad del producto por el precio
 * @param
 * @return double multiplicacion de la cantidad 
 * por el precio del producto
 */
double Subproducto::calcularSubTotal(){
        return double(cantidad)*producto.getPrecio();
}

string Subproducto::printSubproducto(){
        stringstream aux;
        aux << "\n" << producto.getNombre() <<"\t"<< cantidad <<"\t\t$"<<producto.getPrecio()<<"\t$"<<calcularSubTotal();
        return aux.str();
}

#endif