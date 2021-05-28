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
#include <iostream>
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
        void printPersonal();
        void calcularSalario(int horas){cout << "\n    Salario: $" <<salario*horas;}
};

/*
 * Método que imprime los datos
 *  del Cajero al que se le ejecute.
 * */
void Cajero::printPersonal(){
    cout << "\n*******************************************";
	cout << "\n*              Cajero                  *";
	cout << "\n*   Nombre: " << this->getNombre();
    cout << "\n*   Salario: $" << salario << " p/hora"; 
	cout << "\n*   Correo: " << this->getCorreo();
	cout << "\n*   Dirección: " << this->getDireccion();
	cout << "\n*   Telefono: " << this->getNumeroTel();
	cout << "\n*******************************************\n";
}

#endif