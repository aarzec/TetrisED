#ifndef INPUT_H
#define INPUT_H

void initTermios(int echo);
void resetTermios(void);
char getch_(int echo);
char getch(void);
char getche(void);
int _kbhit(void);

#endif