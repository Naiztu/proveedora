#ifndef CLIENTE_H
#define CLIENTE_H

//
//
// Proyecto Proveedora Cliente
//
// José Ángel Rico Mendieta
//
// A01707404
// 
// 27/05/2021
//
// Clase Cliente, clase hija de Personal que refiere a todas
// las operaciones que se hagan relacionado a los que van a facturar.
//
//

#include "Personal.h"
#include <iostream>
using namespace std;

class Cliente: public Personal{
	private:
		string RFC;
	public:
		//Constructores || @Overload
		Cliente(){}	
		Cliente(int _id, string _nombre, string _correo, string _direccion, string _numeroTel, string _RFC):Personal(_id, _nombre, _correo, _direccion, _numeroTel){ 
			RFC = _RFC;
			this->setTipo("Cliente");
		}
        //Getters/Setters
        string getRFC(){ return RFC;}
		
        //Metodo auxiliar || @Override
        void printPersonal();
};		

/*
 * Método que imprime los datos
 *  del cliente al que se le ejecute.
 * */
void Cliente::printPersonal(){
    cout << "\n*******************************************";
	cout << "\n*               Cliente                  *";
	cout << "\n*   Nombre: " << this->getNombre();
    cout << "\n*   RFC: " << RFC;
	cout << "\n*   Correo: " << this->getCorreo();
	cout << "\n*   Dirección: " << this->getDireccion();
	cout << "\n*   Telefono: " << this->getNumeroTel();
	cout << "\n*******************************************\n";
}

#endif