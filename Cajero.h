#ifndef CAJERO_H
#define CAJERO_H

#include "Personal.h"
#include <iostream>
using namespace std;

/*
 * Cajero: Clase hija de Personal, 
 *      se refiere a los cajero del comercio.
 * */
class Cajero: public Personal{
	private:
		int salario; //Por hora
	public:
		//Constructores || @Overload
		Cajero(){}
        Cajero(int _id, string _nombre, int _numeroTel, int _salario):Personal( _id, _nombre, _numeroTel){ salario =  _salario;}	
		Cajero(int _id, string _nombre, string _correo, string _direccion, int _numeroTel, int _salario):Personal(_id, _nombre, _correo, _direccion, _numeroTel){ salario =  _salario;}			
        
        //Getters/Setters
        int getSalario(){ return salario;}
        void setSalario(int _salario){ salario = _salario;}
		
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