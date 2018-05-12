/*
  Archivo: Nodo.cpp
  Autor: Luis Yovany Romo Portilla
  Email: luis.romo@correounivalle.edu.co
  Fecha creación: 2017-08-31
  Fecha última modificación: 2017-08-31
  Versión: 0.1
  Licencia: GPL
*/

#include <stdio.h>
#include <iostream>
#include "Nodo.h"

Nodo::Nodo()
{
    info = 0;
    sig = NULL;
}

Nodo::~Nodo()
{
    //Método destructor
}

void Nodo::setInfo(int info){
    this -> info = info;
}
int Nodo::getInfo(){
    return info;
}

void Nodo::setSig(Nodo *sig){
    this -> sig = sig;
}

Nodo* Nodo::getSig(){
    return this -> sig;
}