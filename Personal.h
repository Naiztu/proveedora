#ifndef PERSONAL_H
#define PERSONAL_H

#include <iostream>
using namespace std;

/*
 * Personal: Clase padre de Cliente, Proveedor y Cajero.
 * */

class Personal{
	private:
        string nombre, correo, direccion;
		int id, numeroTel;
        
	public:
		//Constructores || @Overload
		Personal(){}
        Personal(int _id, string nombre, int _numeroTel);	
		Personal(int _id, string nombre, string correo, string _direccion, int _numeroTel);			
        
        //Getters/Setters
        int getId(){ return id;}
        string getNombre(){ return nombre;}
        string getCorre(){ return correo;}
        string getDireccion(){ return direccion;}
        int getNumeroTel(){ return numeroTel;}
        void setCorreo(string _correo){ correo = _correo;}
        void setDireccion(string _direccion){ direccion = _direccion;} 
        void setNumeroTel(int _numeroTel){ numeroTel = _numeroTel;}
        
        //Metodo auxiliar
        void printPersonal();
};

Personal::Personal(int _id, string _nombre, int _numeroTel){
    id = _id;
    nombre = _nombre;
    correo = "*Sin proporcionar*";
    direccion = "*Sin proporcionar*";
    numeroTel = _numeroTel;
}

Personal::Personal(int _id, string _nombre, string _correo, string _direccion, int _numeroTel){
    id = _id;
    nombre = _nombre;
    correo = _correo;
    direccion = _direccion; 
    numeroTel = _numeroTel;
}


/*
 * Método que imprime los datos
 *  del personal al que se le ejecute.
 * */

void Personal::printPersonal(){
    cout << "\n*******************************************";
	cout << "\n*               Personal                  *";
	cout << "\n*   Nombre: " << nombre;
	cout << "\n*   Correo: " << correo;
	cout << "\n*   Dirección: " << direccion;
	cout << "\n*   Telefono: " << numeroTel;
	cout << "\n*******************************************\n";
}

#endif