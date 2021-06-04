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

#include <sstream>
#include <string>
using namespace std;


class Personal{
	protected:
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
         virtual string printPersonal()=0;

         string printListaPersonal();
};

/**
 * printPersonal
 * 
 * Método que imprime Id y nombre
 *  del personal al que se le ejecute.
 * @param
 * @return string aux varibale auxiliar para 
 * presentar los datos en forma de string 
 */
string Personal::printListaPersonal(){
    stringstream aux;
	aux << "\n" << id<< "\t" << nombre;
    return aux.str();
}

#endif