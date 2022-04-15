#ifndef GAME_CONFIG_H
#define GAME_CONFIG_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#define GAME_NAME "404 Word Jump"

#define SCREEN_WIDTH 2160
#define SCREEN_HEIGHT 1440

#define FPS 60

#define DINO_X (int)(SCREEN_WIDTH / 6)
#define DINO_Y (int)(SCREEN_HEIGHT * 8 / 12)

#define FRUIT_DINO_PATH "../external/images/dinoFruit"
#define ANIMAL_DINO_PATH "../external/images/dinoAnimal"
#define ICECREAM_BASE_PATH "../external/images/icecream"
#define PENGUIN_BASE_PATH "../external/images/penguin"

#define FRUITS_PATH "../external/lists/fruits.txt"
#define ANIMALS_PATH "../external/lists/animals.txt"

#define SELECT_SOUND_PATH "../external/audio/blip.ogg"
#define JUMP_SOUND_PATH "../external/audio/jump.ogg"
#define DEATH_SOUND_PATH "../external/audio/death.ogg"
#define MEGALOVANIA_PATH "../external/audio/megalovania.ogg"

#define TITLE_SIZE      (int)SCREEN_WIDTH / 8
#define GAMEWORD_SIZE   (int)SCREEN_WIDTH / 12
#define BIG_TEXT_SIZE   (int)SCREEN_WIDTH / 16
#define MEDIUM_TEXT_SIZE    (int)SCREEN_WIDTH / 20
#define SMALL_TEXT_SIZE (int)SCREEN_WIDTH / 24
#define TINY_TEXT_SIZE  (int)SCREEN_WIDTH / 34

typedef struct Preferences{
    ALLEGRO_COLOR bgColour;
    char dinoPath[50];
    char enemyPath[50];
    char listPath[50];
}Preferences;

typedef struct Audio{
    ALLEGRO_SAMPLE *jump, *death, *select;
    ALLEGRO_SAMPLE_INSTANCE *megalovania;
}Audio;

typedef struct System{
    ALLEGRO_EVENT_QUEUE *eventQueue;
    ALLEGRO_TIMER *timer;
    ALLEGRO_DISPLAY *display;
}System;

typedef struct Fonts{
    ALLEGRO_FONT *titleArcade, *bigArcade, *bigVt;
    ALLEGRO_FONT *mediumVt, *smallVt, *tinyVt;
}Fonts;

typedef struct Config{
    Preferences *prefs;
    Audio *audio;
    System *sys;
    Fonts *fonts;
}Config;


Config* createConfig();
void setThemePreferences(Preferences *prefs, int theme);
void destroyConfig(Config *cfg);

#endif //GAME_CONFIG_H
