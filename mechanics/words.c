#include "../headers/words.h"

Word* createWord(char *currentWord, int bonus){

    Word *word = (Word*) malloc(sizeof (Word));
    word->w = (char*) malloc(sizeof (currentWord));

    strcpy(word->w, currentWord);
    word->bonus = bonus;
    word->value = BASE_WORD_VALUE * strlen(currentWord);

    return word;
}

int getRepetitionMemory(int difficulty){
    switch (difficulty) {
        case 0:
            return 2;
        case 1:
            return 5;
        case 2:
            return 8;
        case 3:
        default:
            return -1;
    }
}

int isWordRepeated(GameSession *session, char *currentWord){
    int i = 0;
    int cantRepeat = getRepetitionMemory(session->difficulty);

    StackNode *aux = session->typedWords->top;
    Word *word;

    while(aux != NULL && (cantRepeat > i || cantRepeat == -1)){
        word = aux->data;
        if(!strcmp(word->w, currentWord))
            return 1;

        aux = aux->next;
        i ++;
    }

    return  0;
}

int isInWordList(char *word, FILE *wordList){
    char line[20];
    int stillPossible = 0;
    fseek(wordList, 0, 0);

    do{
        fgets(line, 20, wordList);
        line[strlen(line)-1] = '\0';

        if(!strcmp(word, line))
            return 1;

        if(strstr(line, word) == line)
            stillPossible = 1;


    }while(!feof(wordList));

    if(!stillPossible)
        return -1;

    return 0;
}