#ifndef GAME_SESSION_H
#define GAME_SESSION_H

#include <stdlib.h>
#include <time.h>

#include "stack.h"

typedef struct GameSession{
    long points;
    int backspaces;
    int theme;
    int difficulty;
    Stack *typedWords;
}GameSession;

typedef struct Player{
    int isAlive;
    int isJumping;
    int speed;
    int bonus;
}Player;

GameSession* startGameSession();
Player* createPlayer();
void destroyPlayer(Player *player);
void destroyGameSesion(GameSession *session);

#endif //GAME_SESSION_H
