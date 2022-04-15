#ifndef GAME_BASEOBJECTS_H
#define GAME_BASEOBJECTS_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "config.h"


typedef struct BaseValues{
    float x;
    float y;
    float baseWidth;
    float baseHeight;
    float width;
    float height;
}BaseValues;

typedef struct Generic{
    ALLEGRO_BITMAP *bmp;
    BaseValues val;
}Generic;


Generic* createGeneric(char *baseFile, BaseValues vals);
void drawObject(ALLEGRO_BITMAP *bmp, BaseValues val);
void destroyGeneric(Generic *generic);


#endif //GAME_BASEOBJECTS_H
