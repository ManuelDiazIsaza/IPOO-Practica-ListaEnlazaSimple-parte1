
#include <stdio.h>
#include "Lista.h"
#include <iostream>

using namespace std;

int main()
{
   Lista lista;

 //  lista.imprimir();

   lista.nuevo(3);
   lista.nuevo(3);
   lista.nuevo(3);
   lista.nuevo(3);
 //  lista.nuevo(5);
//   lista.nuevo(4);
   lista.nuevo(10);
   lista.nuevo(1);
   lista.nuevo(3);
   lista.nuevo(3);
   lista.nuevo(3);
   lista.nuevo(3);
   lista.nuevo(3);
   lista.nuevo(3);
   lista.nuevo(3);
   lista.nuevo(3);
   lista.nuevo(3);
   lista.nuevo(3);




   lista.imprimir();
   cout << endl << lista.cantidadElem();
   cout << endl << lista.listaOrde();
//   lista.borrarPrimero();
//   cout <<  endl << endl;
//   lista.imprimir();
//   cout <<  endl << endl;
//   lista.borrarUltimo();
//   lista.imprimir();
   cout << endl << endl;
   lista.borrarElementos(3);
   lista.imprimir();

   cout << endl << lista.estaElemento(3) << endl;

   return 0;
}