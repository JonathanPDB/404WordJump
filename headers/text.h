#ifndef GAME_TEXT_H
#define GAME_TEXT_H

#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "session.h"
#include "config.h"
#include "words.h"

#define CENTERED_X      (int)(SCREEN_WIDTH / 2)
#define CENTERED_Y      (int)(SCREEN_HEIGHT / 2)
#define TITLE_Y         (int)(SCREEN_HEIGHT / 9)
#define SUBTITLE_Y      (int)(SCREEN_HEIGHT / 4)



void drawCenteredTitle(Fonts *fonts);
void drawCenteredSubtitle(Fonts *fonts, char *subtitle);
void drawMenu(Fonts *fonts, char *options[], char *descriptions[], int numOptions, int highlighted);
void drawGUI(Fonts *fonts, GameSession *session, char *currentWord, int isWordValid, int bonus);
void printLastWord(Fonts *fonts, GameSession *session);
void destroyFonts(Fonts *fonts);

#endif //GAME_TEXT_H
