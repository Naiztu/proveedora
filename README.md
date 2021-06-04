<a href="#">
    <img src="https://javier.rodriguez.org.mx/itesm/2014/tecnologico-de-monterrey-black.png" alt="ITESM" title="ITESM" align="right" height="60" />
</a>

# **La Proveedora** 🚀

#### **_Programación orientada a objetos - TC1030.1_**
_Sistema diseñado para la administración de un comercio dedicado a la venta de utensilios para la cocina, entre otros._

## **Logica inicial** ⚙️ 
_Teniendo un apartado de cajero, proveedores y clientes, que conforman las personas que interactúan con el comercio, por otro lado, en una factura solo puede haber un ticket, pero puede haber varios tickets que no pertenezcan a una factura. La factura debe de referenciar a un solo cliente con sus respectivos datos, mientras que el ticket debe contener la lista de productos y solo un cajero, el que atendió; cliente puede tener varias facturas, pero una factura no puede tener más de un cliente. Por último, cada producto debe estar referenciado solo con un respectivo proveedor._

### **Diagrama UML clases**
<p align="center">
  <img src="UML.png" />
</p>

## **Compilación**

_Clonar repositorio._

```shell
    git clone https://github.com/Naiztu/proveedora.git
```

_Compilar programa_

```shell
    g++ Personal.h Proveedor.h Cliente.h Cajero.h Producto.h Subproducto.h Ticket.h Factura.h App.h main.cpp
```

_Ejecutar_
```shell
    a.exe
```

## **Notas** 📌
_Ultimo avance, esto es un avance donde se plantea el ULM de todo el proyecto y se aplicó en código las partes que necesitaban de herencia, tambien se realizo polimorfismo y la implementacion de clases abstractas._

## **Lenguaje** 👅
*  *C++*

## **Autor** ✒️
_Este proyecto es realizado para la UF "Pensamiento Computacional para Orientado a Objetos" (TC1033.2) por :_
* **José Ángel Rico Mendieta** - *A01707404*
