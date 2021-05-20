/**
Programación orientada a objetos - TC1030.1
By: José Ángel Rico Mendieta - A01707404
**/

//#include "Personal.h"
#include "Cliente.h"

int main() {
    
    //Objeto de la clase padre para su presentación
 
    cout << "\nCLASE PADRE:\n";
    Personal pablo_sinDatos = Personal(1,"Pablo de La Purísima Concepción", 123456789);
    pablo_sinDatos.printPersonal();

    Personal pablo_conDatos = Personal(1,"Pablo de La Purísima Concepción","pablito@gmail.com","Av. México #204", 123456789);
    pablo_conDatos.printPersonal();

    cout << "\n";

    cout << "\nCLASE CLIENTE:\n";
    //Objeto de clase cliente
    Cliente cliente_sinDatos = Cliente(1,"Juan de La Purísima Concepción", 567891234, "JDPC20342");
    cliente_sinDatos.printPersonal();

    Cliente cliente_conDatos = Cliente(1,"Juan de La Purísima Concepción","juanito@gmail.com","Av. Japón #204", 567891234, "JDPC20342");
    cliente_conDatos.printPersonal();

    return 0;
}