/*************************
 * UFA-ESPE
 * ALUMNOS:  Leonardo Obando, William Leon
 * FECHA CREACION: Miercoles, 21 de noviembre de 2022
 * FECHA MODIFICACION: Miercoles, 23 de noviembre de 2022
 * Enunciado del problema: Crear los m�todos Insertar, Buscar
 y Eliminar elementos de una lista Simple, Doble y Circular
 * Nivel: TERCERO     NRC: 7999
 *************************/
#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include "Nodo.h"

using namespace std;

class ListaSimples {
private:
    Nodo* cabeza;
public:
    ListaSimples();
    void Insertar(int);
    void InsertarPos(int val, int pos);
    void Buscar(int);
    void Eliminar(int);
    void Mostrar();
    string MostrarGame();
    int Obtener(int);
    int Tamano();
    int Intercambiar(int, int);
};

#endif