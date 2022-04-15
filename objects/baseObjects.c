#include "../headers/baseObjects.h"


Generic* createGeneric(char *baseFile, BaseValues vals){

    char file[30];
    Generic *generic = (Generic*)malloc(sizeof(Generic));

    sprintf(file, "%s.png", baseFile);

    ALLEGRO_BITMAP *bmp = al_load_bitmap(file);
    if(bmp == NULL){
        printf("Error loading %s file", file);
        exit(1);
    }

    generic->bmp    = bmp;
    vals.baseHeight = (float)al_get_bitmap_height(generic->bmp);
    vals.baseWidth  = (float)al_get_bitmap_width(generic->bmp);
    vals.width      *= vals.baseWidth;
    vals.height     *= vals.baseHeight;
    generic->val    = vals;

    return generic;
}

void drawObject(ALLEGRO_BITMAP *bmp, BaseValues val){
    al_draw_scaled_bitmap(bmp,
                          0, 0,
                          val.baseWidth, val.baseHeight,
                          val.x, val.y,
                          val.width, val.height,
                          0);
}

void destroyGeneric(Generic *generic){
    al_destroy_bitmap(generic->bmp);
    free(generic);
}