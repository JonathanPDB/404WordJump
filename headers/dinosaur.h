#ifndef GAME_DINOSAUR_H
#define GAME_DINOSAUR_H

#include "baseObjects.h"

typedef struct Dino{
    ALLEGRO_BITMAP *bmp[3];
    BaseValues val;
    float jumpMultiplier;
    int frame;
}Dino;

Dino* createDino(char *baseFile);
void drawDino(Dino *dino);
void updateDino(Dino *dino);
void destroyDino(Dino *dino);

#endif //GAME_DINOSAUR_H
