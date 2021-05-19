/**
Programación orientada a objetos - TC1030.1
By: José Ángel Rico Mendieta - A01707404
**/

#include "Personal.h"

int main() {
    
    //Creamos un objeto de la clase padre para su presentación
    Personal pablo_sinDatos = Personal(1,"Pablo de La Purísima Concepción", 123456789);
    pablo_sinDatos.printPersonal();

    cout << "\n\n";

    Personal pablo_conDatos = Personal(1,"Pablo de La Purísima Concepción","pablito@gmail.com","Av. México #204", 123456789);
    pablo_conDatos.printPersonal();

    return 0;
}