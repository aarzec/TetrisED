/**
UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
Autor: Andrés Romero
Materia: Estructura de Datos - 2024
*/

#include <iostream>
#include "Utils.h"
#include "Game.h"

int main() {
    srand(time(NULL));
    Game game = Game(Utils::getConsoleWidth(), 15);
    game.startGameLoop();
}
