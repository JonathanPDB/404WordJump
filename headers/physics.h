#ifndef GAME_PHYSICS_H
#define GAME_PHYSICS_H

#include "dinosaur.h"
#include "enemy.h"
#include "queue.h"

#define JUMP_DURATION 60
#define JUMP_A JUMP_DURATION/2000.0f
#define JUMP_B JUMP_A/30.0f

float getJumpMultiplier(int jumpFrame);
int checkCollision(Dino *dino, Queue *enemyQueue);


#endif //GAME_PHYSICS_H
