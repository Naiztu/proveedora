#ifndef CAJERO_H
#define CAJERO_H

//
//
// Proyecto Proveedora Cajero
//
// José Ángel Rico Mendieta
//
// A01707404
// 
// 27/05/2021
//
// Clase Cajero, clase hija de Personal que refiere a todas
// las operaciones que se hagan relacionado a los cajeros.
//
//

#include "Personal.h"
#include <sstream>
#include <string>
using namespace std;

class Cajero: public Personal{
	private:
		double salario; //Por hora
	public:
		//Constructores || @Overload
		Cajero(){}	
		Cajero(int _id, string _nombre, string _correo, string _direccion, string _numeroTel, double _salario):Personal(_id, _nombre, _correo, _direccion, _numeroTel){
			salario =  _salario;
			this->setTipo("Cajero");
		}
        //Getters/Setters
        double getSalario(){ return salario;}
        void setSalario(double _salario){ salario = _salario;}
		
        //Metodo auxiliar || @Override
        string printPersonal();
        string calcularSalario(int);
};

/**
 * printPersonal
 * 
 * Método que imprime los datos
 *  del Cajero al que se le ejecute.
 * @param
 * @return string aux varibale auxiliar para 
 * presentar los datos en forma de string 
 */
string Cajero::printPersonal(){
	stringstream aux;
    aux <<"\n*******************************************"
		<< "\n*                Cajero                  *"
		<< "\n*   Nombre: " << nombre
		<< "\n*   Salario: $" << salario << " p/hora"
		<< "\n*   Correo: " << correo
		<< "\n*   Dirección: " << direccion
		<< "\n*   Telefono: "<< numeroTel
		<< "\n*******************************************\n";
	return aux.str();
}

/**
 * calcularSalario(double)
 *
 * Calcula el salario por las horas trabajadas por el
 * cajero
 *
 * @param double horas trabajadas del cajero
 * @return string aux variable auxiliar para imprimir 
 * como string el calculo
 */
string  Cajero::calcularSalario(int horas){
	stringstream aux;
	aux << "\n    Salario: $" <<salario*double(horas);
	return aux.str();
}

#endif