#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>
#include "Utils.h"

int Utils::getConsoleWidth(void) {
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    return (int)size.ws_col;
}

void Utils::clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

int Utils::randomInt(int min, int max, int divisor) {
    int r = rand() % (max - min + 1) + min;
    while (r % divisor != 0) {
        r--;
    }
    if (r < min) {
        r = min;
    }
    return r;
}
