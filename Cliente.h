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
#include <sstream>
#include <string>
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
        string printPersonal();
};		

/**
 * printPersonal()
 * 
 * Método que imprime los datos
 *  del Cliente al que se le ejecute.
 * @param
 * @return string aux varibale auxiliar para 
 * presentar los datos en forma de string 
 */
string Cliente::printPersonal(){
	stringstream aux;
    aux <<"\n*******************************************"
		<< "\n*               Cliente                  *"
		<< "\n*   Nombre: " << nombre
		<< "\n*   RFC: " << RFC
		<< "\n*   Correo: " << correo
		<< "\n*   Dirección: " << direccion
		<< "\n*   Telefono: "<< numeroTel
		<< "\n*******************************************\n";
	return aux.str();
}

#endif