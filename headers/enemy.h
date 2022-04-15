#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <time.h>

#include "queue.h"
#include "baseObjects.h"
#include "config.h"

#define NUM_ENEMY_SPRITES 3

#define STARTING_ENEMY_X SCREEN_WIDTH * 1.2
#define STARTING_ENEMY_Y SCREEN_HEIGHT * 8.2 / 12

#define BIG_ENEMY        1
#define MEDIUM_ENEMY     0.8
#define SMALL_ENEMY      0.5

#define ONE_BIG         0
#define TWO_BIG         1
#define ONE_MEDIUM      2
#define TWO_MEDIUM      3
#define ONE_SMALL       4
#define TWO_SMALL       5
#define THREE_SMALL     6
#define FOUR_SMALL      7

typedef struct Enemy{
    ALLEGRO_BITMAP *bmp;
    BaseValues val;
    float mov;
}Enemy;

void spawnEnemy(Queue *enemyQueue, char *path, int type);
Enemy* createEnemy(float size, char *path, int offset);
void drawEnemy(Queue *enemyQueue);
void updateEnemy(Queue *enemyQueue, float speed);
void destroyEnemy(Enemy *enemy);

#endif //GAME_ENEMY_H
