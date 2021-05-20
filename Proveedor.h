#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include "Personal.h"
#include <iostream>
using namespace std;

/*
 * Proveedor: Clase hija de Personal, 
 *      se refiere a los proveedores del comercio.
 * */
class Proveedor: public Personal{
	private:
		string empresa;
	public:
		//Constructores || @Overload
		Proveedor(){}
        Proveedor(int _id, string _nombre, int _numeroTel, string _empresa):Personal( _id, _nombre, _numeroTel){ empresa = _empresa;}	
		Proveedor(int _id, string _nombre, string _correo, string _direccion, int _numeroTel, string _empresa):Personal(_id, _nombre, _correo, _direccion, _numeroTel){ empresa = _empresa;}			
        
        //Getters/Setters
        string getEmpresa(){ return empresa;}
		
        //Metodo auxiliar || @Override
        void printPersonal();
};

/*
 * Método que imprime los datos
 *  del cliente al que se le ejecute.
 * */
void Proveedor::printPersonal(){
    cout << "\n*******************************************";
	cout << "\n*              Proveedor                  *";
	cout << "\n*   Nombre: " << this->getNombre();
    cout << "\n*   Empresa: " << empresa;
	cout << "\n*   Correo: " << this->getCorreo();
	cout << "\n*   Dirección: " << this->getDireccion();
	cout << "\n*   Telefono: " << this->getNumeroTel();
	cout << "\n*******************************************\n";
}

#endif