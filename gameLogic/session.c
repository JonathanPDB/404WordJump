#include "../headers/session.h"

GameSession* startGameSession(){

    GameSession *session = (GameSession*)malloc(sizeof(GameSession));

    session->points     = 0;
    session->backspaces = 3;
    session->difficulty = 0;
    session->theme      = 0;

    Stack *stack = createStack();
    session->typedWords = stack;

    return session;
}

Player* createPlayer(){
    Player *player = (Player*)malloc(sizeof(Player));

    player->speed       = 10;
    player->isAlive     = 1;
    player->isJumping   = 0;
    player->bonus       = 1;

    return player;
}

void destroyGameSesion(GameSession *session){
    destroyStack(session->typedWords);
    free(session);
}

void destroyPlayer(Player *player){
    free(player);
}