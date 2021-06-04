#ifndef PROVEEDOR_H
#define PROVEEDOR_H

//
//
// Proyecto Proveedora Proveedor
//
// José Ángel Rico Mendieta
//
// A01707404
// 
// 27/05/2021
//
// Clase Proveedor, clase hija de Personal que refiere a todas
// las operaciones que se hagan relacionado a los proveedores.
//
//

#include "Personal.h"
#include <sstream>
#include <string>
using namespace std;

class Proveedor: public Personal{
	private:
		string empresa;
	public:
		//Constructores || @Overload
		Proveedor(){}
		Proveedor(int _id, string _nombre, string _correo, string _direccion, string _numeroTel, string _empresa):Personal(_id, _nombre, _correo, _direccion, _numeroTel){
			empresa = _empresa;
			this->setTipo("Proveedor");
		}
        //Getters/Setters
        string getEmpresa(){ return empresa;}
		
        //Metodo auxiliar || @Override
        string printPersonal();
};

/**
 * printPersonal
 * 
 * Método que imprime los datos
 *  del Proveedor al que se le ejecute.
 * @param
 * @return string aux varibale auxiliar para 
 * presentar los datos en forma de string 
 */
string Proveedor::printPersonal(){
	stringstream aux;
    aux <<"\n*******************************************"
		<< "\n*             Proveedor                  *"
		<< "\n*   Nombre: " << nombre
		<< "\n*   Empresa: " << empresa
		<< "\n*   Correo: " << correo
		<< "\n*   Dirección: " << direccion
		<< "\n*   Telefono: "<< numeroTel
		<< "\n*******************************************\n";
	return aux.str();
}

#endif