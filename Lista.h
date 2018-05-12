/*
  Archivo: Lista.h
  Autor: Luis Yovany Romo
  Email: luis.romo@correounivalle.edu.co
  Fecha creación: 2018-02-09
  Fecha Última modificación: 2018-02-09
  Versión: 0.1
  Licencia: GPL
*/

// Clase: Lista
// Responsabilidad: elemento (nodo) de una lista
// ColaboraciÃ³n: ninguna

#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"

class Lista
{
private:
    Nodo *cab;
public:
    Lista();
    ~Lista();
    void nuevo(int info);
    void imprimir();
    int cantidadElem();
    bool listaOrde();
    void borrarPrimero();
    void borrarUltimo();
    void borrarElemento(int elem); //Borra el primer elemento que coincida
    void borrarElementos(int elem); // Borra todos los elementos que coincidan
    bool estaElemento(int elem);
};

#endif
