//
//
// Proyecto Proveedora main
//
// José Ángel Rico Mendieta
//
// A01707404
// 
// 27/05/2021
//
// Sistema diseñado para la administración de un 
// comercio dedicado a la venta de utensilios para la cocina, 
// entre otros. Realizado para la clase TC1030 Programación Orientado a
// Objetos.
//
//


#include "App.h"

int main() {
    
    App* app = new App();
    app->start();

    return 0;
}

//g++ Personal.h Proveedor.h Cliente.h Cajero.h Producto.h Subproducto.h Ticket.h Factura.h App.h main.cpp