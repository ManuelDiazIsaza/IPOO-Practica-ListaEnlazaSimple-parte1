/*
  Archivo: Nodo.h
  Autor: Luis Yovany Romo
  Email: luis.romo@correounivalle.edu.co
  Fecha creación: 2018-02-09
  Fecha Última modificación: 2018-02-09
  Versión: 0.1
  Licencia: GPL
*/

// Clase: Nodo
// Responsabilidad: elemento (nodo) de una lista
// ColaboraciÃ³n: ninguna


#ifndef NODO_H
#define NODO_H


using namespace std;


class Nodo
{
protected:
    int info;
    Nodo *sig;
public:
    Nodo();
    ~Nodo();
    void setInfo(int info);
    int getInfo();
    Nodo *getSig();
    void setSig(Nodo *sig);
};

#endif
