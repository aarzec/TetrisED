#ifndef UTILS_H
#define UTILS_H

class Utils {
    public:
        static int getConsoleWidth(void);
        static void clearScreen(void);
        static int randomInt(int min, int max, int divisor = 1);
};

#endif
