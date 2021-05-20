/**
Programación orientada a objetos - TC1030.1
By: José Ángel Rico Mendieta - A01707404
**/

#include "Personal.h"
#include "Cliente.h"
#include "Proveedor.h"
#include "Cajero.h"

int main() {
    
    //Objeto de la clase padre para su presentación
 
    cout << "\nCLASE PADRE:\n";
    Personal per_sinDatos = Personal(1,"Pablo de La Purísima Concepción", 123456789);
    per_sinDatos.printPersonal();

    Personal per_conDatos = Personal(1,"Pablo de La Purísima Concepción","pablito@gmail.com","Av. México #204", 123456789);
    per_conDatos.printPersonal();


    //Objeto de clase cliente para su presentación

    cout << "\n\nCLASE CLIENTE:\n";
    Cliente cliente_sinDatos = Cliente(1,"Juan de La Purísima Concepción", 567891234, "JDPC20342");
    cliente_sinDatos.printPersonal();

    Cliente cliente_conDatos = Cliente(1,"Juan de La Purísima Concepción","juanito@gmail.com","Av. Japón #204", 567891234, "JDPC20342");
    cliente_conDatos.printPersonal();


    //Objeto de clase proveedor para su presentación

    cout << "\n\nCLASE PROVEEDOR:\n";
    Proveedor prov_sinDatos = Proveedor(1,"Raul de La Purísima Concepción", 987654321, "Cuplasa");
    prov_sinDatos.printPersonal();

    Proveedor prov_conDatos = Proveedor(1,"Raul de La Purísima Concepción","raulito@gmail.com","Av. Tlaxcala #204", 987654321, "Cuplasa");
    prov_conDatos.printPersonal();

    //Objeto de clase cajero para su presentación

    cout << "\n\nCLASE CAJERO:\n";
    Cajero caj_sinDatos = Cajero(1,"Fermin de La Purísima Concepción", 918273640, 18);
    caj_sinDatos.printPersonal();

    Cajero caj_conDatos = Cajero(1,"Fermin de La Purísima Concepción","fermincito@gmail.com","Av. Roma #204", 918273640, 18);
    caj_conDatos.printPersonal();

    caj_conDatos.calcularSalario(48);

    return 0;
}