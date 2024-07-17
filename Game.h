#ifndef GAME_H
#define GAME_H

#include "ListasSimples.h"
#include "FallingBlock.h"

class Game {
    public:
        Game(int width, int height);
        void startGameLoop(void);
    
    private:
        int width;
        int height;
        int delta;
        bool breakLoop;

        FallingBlock currentFallingBlock;
        int lastX;
        int lastY;
        int nextNum;

        ListaSimples* lista;

        void update(void);
        void draw(void);
};

#endif
