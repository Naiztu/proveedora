#ifndef PRODUCTO_H
#define PRODUCTO_H

//
//
// Proyecto Proveedora Producto
//
// José Ángel Rico Mendieta
//
// A01707404
// 
// 27/05/2021
//
// Clase Producto, clase para el registro
// de los productos del negocio.
//
//

#include "Proveedor.h"
#include <sstream>
#include <string>
using namespace std;

class Producto{
	private:
        int id;
        string nombre;
        double precio;
        Proveedor*prov;

	public:
        Producto(){}
        Producto(int _id, string _nombre, double _precio, Proveedor*_prov){
            id = _id;
            nombre = _nombre;
            precio = _precio;
            prov = _prov;
        }	

        int getId(){ return id;}
        string getNombre(){return nombre;}
        double getPrecio(){return precio;}	
        string printProducto();
};

/**
 * printProducto
 * 
 * Método que imprime los datos
 *  del Producto al que se le ejecute.
 * @param
 * @return string aux varibale auxiliar para 
 * presentar los datos en forma de string 
 */
string Producto::printProducto(){
        stringstream aux;
        aux << "\n" << id<< "\t" << nombre << "\t$" << precio <<"\t"<<prov->getNombre();
        return aux.str();
}


#endif