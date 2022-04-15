#ifndef GAME_SCREENS_H
#define GAME_SCREENS_H

#define NAME_SIZE 16

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <math.h>

#include "baseObjects.h"
#include "dinosaur.h"
#include "utils.h"
#include "text.h"
#include "config.h"

void titleScreen(Config *cfg);
int menuScreen(Config *cfg);
void creditsScreen(Config *cfg);
void howToPlayScreen(Config *cfg);
int chooseDifficultyScreen(Config *cfg);
int chooseThemeScreen(Config *cfg);
void rankingScreen(Config *cfg);
void youDiedScreen(Config *cfg, GameSession *session);
void saveScreen(Config *cfg, GameSession *session);

#endif //GAME_SCREENS_H
