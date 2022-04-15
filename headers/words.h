#ifndef GAME_MECHANICS_H
#define GAME_MECHANICS_H

#include <allegro5/allegro.h>
#include <string.h>

#include "config.h"
#include "session.h"
#include "stack.h"

#define BASE_WORD_VALUE 30

typedef struct Word{
    char *w;
    int value;
    int bonus;
}Word;

Word* createWord(char *currentWord, int bonus);
int getRepetitionMemory(int difficulty);
int isWordRepeated(GameSession *session, char *currentWord);
int isInWordList(char *word, FILE *wordList);

#endif //GAME_MECHANICS_H
