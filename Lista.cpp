/*
  Archivo: Lista.cpp
  Autor: Luis Yovany Romo Portilla
  Email: luis.romo@correounivalle.edu.co
  Fecha creación: 2017-08-31
  Fecha última modificación: 2017-08-31
  Versión: 0.1
  Licencia: GPL
*/

#include "Lista.h"
#include "Nodo.h"
#include <time.h>
#include <stdio.h>
#include <iostream>

Lista::Lista()
{
    cab = nullptr;
}


void Lista::nuevo(int info){
    Nodo *nuevo;
    nuevo = new Nodo();
    nuevo->setInfo(info);
    if(cab == nullptr){
        cab = nuevo;
        nuevo->setSig(nullptr);
    } else {
        nuevo->setSig(cab);
        cab = nuevo;
    }
}

void Lista::imprimir(){
    Nodo *desplaza = cab;

    if(cab == nullptr){
        cout << endl << "Lista vacia" << endl <<endl;
    }else{
        while(desplaza != nullptr){
            cout << desplaza->getInfo() << endl;
            desplaza = desplaza->getSig();
        }
    }
}


Lista::~Lista()
{
    Nodo *desplaza = cab;
    Nodo *borrar;
    while (desplaza != nullptr)
    {
        borrar = desplaza;
        desplaza = desplaza->getSig();
        delete borrar;
    }
}

int Lista::cantidadElem()
{
    Nodo *desplaza = cab;
    int cont=0;

    if(cab == nullptr){
        return cont;
    }else{
        while(desplaza != nullptr){
            cont++;
            desplaza = desplaza->getSig();
        }
    }
    return cont;
}

bool Lista::listaOrde()
{
    Nodo *pos1 = cab;
    bool orde = true;

    if(cantidadElem()==1)
    {
        return orde;
    }
    else if(cab== nullptr)
    {
        return orde;
    }
    else
    {
        Nodo *pos2 = cab->getSig();
        while(pos2 != nullptr)
        {
            if(pos1->getInfo() < pos2->getInfo())
            {
                pos1 = pos1->getSig();
                pos2 = pos2->getSig();
            }
            else
            {
                orde = false;
                pos1 = pos1->getSig();
                pos2 = pos2->getSig();
            }
        }
    }
    return orde;
}

void Lista::borrarPrimero()
{
    Nodo *pos1 = cab;

    if(cantidadElem()==0)
    {
        cout << "Lista Vacia" << endl;
    }
    else if(cantidadElem()==1)
    {
        cab = nullptr;
        delete pos1;
    }
    else
    {
    Nodo *pos2 = cab->getSig();
    cab = pos2;
    delete pos1;
    }
}

void Lista::borrarUltimo()
{
    Nodo *pos1 = cab;

    if(cantidadElem()==0)
    {
        cout << "Lista Vacia" << endl;
    }
    else if(cantidadElem()==1)
    {
        cab = nullptr;
        delete pos1;
    }
    else
    {
    Nodo *pos2 = cab->getSig();
    while(pos2->getSig() != nullptr)
    {
        pos1 = pos1->getSig();
        pos2 = pos2->getSig();
    }
    pos1->setSig(nullptr);
    delete pos2;
    }
}

void Lista::borrarElemento(int elem)
{
    Nodo *pos1 = cab;
    bool encontro = false;

    if(cantidadElem()==0)
    {
        cout << "Lista Vacia" << endl;
    }
    else if(cantidadElem()==1 && pos1->getInfo()==elem)
    {
        cab = nullptr;
        delete pos1;
        encontro = true;
    }
    else
    {
        Nodo *pos2 = cab->getSig();

        if(pos1->getInfo()==elem)
        {
            cab = pos2;
            delete pos1;
            encontro = true;
        }
        else
        {
            while(pos2 != nullptr)
            {
                if(pos2->getInfo()==elem && pos2->getSig()== nullptr)
                {
                    pos1->setSig(nullptr);
                    delete pos2;
                    pos2 = nullptr;
                    encontro = true;
                }
                else if(pos2->getInfo()==elem)
                {
                    pos1->setSig(pos2->getSig());
                    pos1 = pos2->getSig();
                    delete pos2;
                    pos2 = pos1->getSig();
                    encontro = true;
                }
                else
                {
                    pos1 = pos1->getSig();
                    pos2 = pos2->getSig();
                }
            }
        }
    }
    if(encontro)
    {
        cout << "El elemento ha sido eliminado correctamente." << endl;
    }
    else
    {
        cout << "El elemento no se encontraba en la lista." << endl;
    }

}

void Lista::borrarElementos(int elem)
{
    Nodo *pos1 = cab;
    bool encontro = false;

    while(estaElemento(elem))
    {
        pos1 = cab;

        if(cantidadElem()==0)
        {
            cout << "Lista Vacia" << endl;
        }
        else if(cantidadElem()==1 && pos1->getInfo()==elem)
        {
           cab = nullptr;
          delete pos1;
           encontro = true;
        }
        else
        {
            Nodo *pos2 = cab->getSig();
            while(pos2 != nullptr)
            {
                if(pos1->getInfo()==elem && pos1 == cab)
                {
                    cab = pos2;
                    delete pos1;
                    encontro = true;
                    pos1 = pos2;
                    pos2 = pos2->getSig();
                }
                else if(pos2->getInfo()==elem && pos2->getSig()== nullptr)
                {
                    pos1->setSig(nullptr);
                    delete pos2;
                    pos2 = nullptr;
                    encontro = true;
                }
                else if(pos2->getInfo()==elem)
                {
                    pos1->setSig(pos2->getSig());
                    pos1 = pos2->getSig();
                    delete pos2;
                    pos2 = pos1->getSig();
                    encontro = true;
                }
                else
                {
                    pos1 = pos1->getSig();
                    pos2 = pos2->getSig();
                }
            }
        }
    }
    if(pos1->getInfo() == elem)
    {
        borrarUltimo();
    }
    if(encontro)
    {
        cout << "Todas las coincidencias han sido eliminadas correctamente." << endl;
    }
    else
    {
        cout << "El elemento no se encontraba en la lista." << endl;
    }

}

bool Lista::estaElemento(int elem)
{
    Nodo *pos1 = cab;
    bool esta=false;

    while(pos1 != nullptr)
    {
        if(pos1->getInfo()==elem)
        {
            esta=true;
            pos1= nullptr;
        }
        else
        {
            pos1 = pos1->getSig();
        }
    }
    return esta;
}
