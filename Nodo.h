/*************************
 * UFA-ESPE
 * ALUMNOS:  Leonardo Obando, William Leon
 * FECHA CREACION: Miercoles, 21 de noviembre de 2022
 * FECHA MODIFICACION: Miercoles, 23 de noviembre de 2022
 * Enunciado del problema: Crear los m�todos Insertar, Buscar
 y Eliminar elementos de una lista Simple, Doble y Circular
 * Nivel: TERCERO     NRC: 7999
 *************************/
#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <string>

using namespace std;

class Nodo {
private:
    int dato;
    Nodo* siguiente;
public:
    Nodo(int);
    void setDato(int);
    void setSiguiente(Nodo*);
    int getDato();
    Nodo* getSiguiente();
};

#endif