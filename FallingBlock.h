#ifndef FALLING_BLOCK_H
#define FALLING_BLOCK_H

class FallingBlock {
    public:
        int posX;
        int posY;
        int num;
        FallingBlock();
        FallingBlock(int num, int x, int y);
};

#endif