#ifndef PERSONAL_H
#define PERSONAL_H
  
//
//
// Proyecto Proveedora Personal
//
// José Ángel Rico Mendieta
//
// A01707404
// 
// 27/05/2021
//
// Clase Personal, clase abstracta para ser padre de las clases:
// Cliente, Personal y Proveedor.
//
// 

#include <iostream>
using namespace std;


class Personal{
	private:
        string nombre, correo, direccion, numeroTel, tipo;
		int id;
        
	public:
		//Constructores || @Overload
		Personal(){}	
		Personal(int _id, string _nombre, string _correo, string _direccion, string _numeroTel){
            id = _id;
            nombre = _nombre;
            correo = _correo;
            direccion = _direccion; 
            numeroTel = _numeroTel;
        }
        
        //Getters/Setters
        int getId(){ return id;}
        string getNombre(){ return nombre;}
        string getCorreo(){ return correo;}
        string getDireccion(){ return direccion;}
        string getNumeroTel(){ return numeroTel;}
        string getTipo(){ return tipo;}
        void setCorreo(string _correo){ correo = _correo;}
        void setDireccion(string _direccion){ direccion = _direccion;} 
        void setNumeroTel(string _numeroTel){ numeroTel = _numeroTel;}
        void setTipo(string _tipo){ tipo = _tipo;}
        
        //Metodo auxiliar
         virtual void printPersonal()=0;

         void printListaPersonal();
};

void Personal::printListaPersonal(){
	cout << "\n" << id<< "\t" << nombre;
}

#endif