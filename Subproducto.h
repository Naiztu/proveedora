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
                double subtotal;
                Producto producto;
                double calcularSubTotal();
        public:
                Subproducto(){}
                Subproducto(int _cantidad, Producto _producto){
                cantidad = _cantidad;
                producto = _producto;
                subtotal = calcularSubTotal();
                }
};

double Subproducto::calcularSubTotal(){
        return double(cantidad)*producto.getPrecio();
}

#endif