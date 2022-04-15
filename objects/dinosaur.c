#include "../headers/dinosaur.h"

Dino* createDino(char *baseFile){
    int i;
    char file[50];

    ALLEGRO_BITMAP *dinoBmp[3];
    Dino *dino = (Dino*)malloc(sizeof(Dino));

    for(i=0;i<3;i++){
        sprintf(file, "%s%d.png", baseFile, i);

        dinoBmp[i] = al_load_bitmap(file);
        if(dinoBmp[i] == NULL){
            printf("Error loading %s file", file);
            exit(1);
        }
        dino->bmp[i] = dinoBmp[i];
    }

    dino->jumpMultiplier = 1;
    dino->frame = 0;
    dino->val.x = DINO_X;
    dino->val.y = DINO_Y;
    dino->val.baseHeight = (float)al_get_bitmap_height(dino->bmp[0]);
    dino->val.baseWidth = (float)al_get_bitmap_width(dino->bmp[0]);
    dino->val.height = dino->val.baseHeight * 2;
    dino->val.width = dino->val.baseWidth * 2;

    return dino;
}

void updateDino(Dino *dino){
    dino->val.y = DINO_Y * dino->jumpMultiplier;
}

void drawDino(Dino *dino){
    drawObject(dino->bmp[dino->frame], dino->val);
}

void destroyDino(Dino *dino){
    int i;
    for(i=0;i<3;i++)
        al_destroy_bitmap(dino->bmp[i]);
    free(dino);
}
