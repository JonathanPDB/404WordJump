#ifndef GAME_UTILS_H
#define GAME_UTILS_H

#include <allegro5/allegro.h>

#include "config.h"

int waitKeyPress(Config *cfg);
void waitForSomeTime(System *sys, float time);

#endif //GAME_UTILS_H
