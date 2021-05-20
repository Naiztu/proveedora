#ifndef CLIENTE_H
#define CLIENTE_H

#include "Personal.h"
#include <iostream>
using namespace std;

/*
 * Cliente: Clase hija de Personal, 
 *      se refiere a los clientes que van a facturar.
 * */
class Cliente: public Personal{
	private:
		string RFC;
	public:
		//Constructores || @Overload
		Cliente(){}
        Cliente(int _id, string _nombre, int _numeroTel, string _RFC):Personal( _id, _nombre, _numeroTel){ RFC = _RFC;}	
		Cliente(int _id, string _nombre, string _correo, string _direccion, int _numeroTel, string _RFC):Personal(_id, _nombre, _correo, _direccion, _numeroTel){ RFC = _RFC;}			
        
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