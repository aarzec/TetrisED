#include <iostream>
#include <chrono>
#include <thread>
#include "ListasSimples.h"
#include "Game.h"
#include "Input.h"
#include "Utils.h"
#include "FallingBlock.h"

Game::Game(int w, int h) {
    width = w;
    height = h;
    breakLoop = false;
    currentFallingBlock = FallingBlock(Utils::randomInt(1, 10), Utils::randomInt(0, width - 3, 3), 0);
    lastX = -1;
    lastY = -1;
    delta = 0;
    lista = new ListaSimples();
    nextNum = Utils::randomInt(1, 10);
}

void Game::startGameLoop(void) {
    while (!breakLoop) {
        update();
        draw();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        delta++;
    }
}

void Game::update(void) {
    std::cout << "\b \b";
    if (_kbhit()) {
        char pressed = getch();
        switch (pressed) {
            case 'a':
                if (currentFallingBlock.posX > 0) currentFallingBlock.posX -= 3;
                break;
            case 'd':
                if (currentFallingBlock.posX < width - 3) currentFallingBlock.posX += 3;
                break;
            case 's':
                currentFallingBlock.posY += 1;
                break;
        }
    }

    if (delta % 3 == 0) {
        currentFallingBlock.posY += 1;
    }

    if (delta >= 300) {
        delta = 0;
    }

    if (currentFallingBlock.posY >= height) {
        lista->InsertarPos(currentFallingBlock.num, currentFallingBlock.posX/3);
        currentFallingBlock = FallingBlock(nextNum, Utils::randomInt(0, width - 3, 3), 0);
        nextNum = Utils::randomInt(1, 10);
    }
}

void writeLine(std::string& line, std::string content, int finalWidth) {
    int left = finalWidth - content.length();
    if (left < 0) {
        content = content.substr(0, finalWidth);
        left = 0;
    }
    // std::cout << finalWidth << "/" << content.length() << "/" << left << std::endl;
    line = line + content + std::string(left, ' ');
}

void Game::draw(void) {
    // Decide to draw
    if (lastX == currentFallingBlock.posX && lastY == currentFallingBlock.posY) {
        return;
    }
    lastX = currentFallingBlock.posX;
    lastY = currentFallingBlock.posY;

    std::string line = "";

    // Next block
    writeLine(line, "Siguiente: " + std::to_string(nextNum) + " | Width: " + std::to_string(width) + " | PosX: " + std::to_string(currentFallingBlock.posX) + " | PosY: " + std::to_string(currentFallingBlock.posY) + " | Delta: " + std::to_string(delta), width);
    line += std::string(width, '-');

    // Main screen
    for (int y = 0; y < height; ++y) {
        std::string toWrite = "";
        for (int x = 0; x < width; ++x) {
            if (y == currentFallingBlock.posY && x == currentFallingBlock.posX) {
                toWrite += to_string(currentFallingBlock.num);
            } else {
                toWrite += " ";
            }
        }
        writeLine(line, toWrite, width);
    }

    // Placed blocks
    line += std::string(width, '-');
    writeLine(line, lista->MostrarGame(), width);
    line += std::string(width, '-');
    // Draw
    Utils::clearScreen();
    std::cout << line << std::endl;

    // List display
    std::cout << std::endl << "Lista: ";
    lista->Mostrar();
}
