#include "../headers/enemy.h"


void spawnEnemy(Queue *enemyQueue, char *path, int type){

    int quantity, i;
    float size;
    switch (type) {
        case ONE_BIG:
            quantity = 1;
            size = BIG_ENEMY;
            break;
        case TWO_BIG:
            quantity = 2;
            size = BIG_ENEMY;
            break;
        case ONE_MEDIUM:
            quantity = 1;
            size = MEDIUM_ENEMY;
            break;
        case TWO_MEDIUM:
            quantity = 2;
            size = MEDIUM_ENEMY;
            break;
        case ONE_SMALL:
            quantity = 1;
            size = SMALL_ENEMY;
            break;
        case TWO_SMALL:
            quantity = 2;
            size = SMALL_ENEMY;
            break;
        case THREE_SMALL:
            quantity = 3;
            size = SMALL_ENEMY;
            break;
        case FOUR_SMALL:
            quantity = 4;
            size = SMALL_ENEMY;
            break;
    }

    for(i=0;i<quantity;i++)
        enqueue(enemyQueue, createEnemy(size, path, i));

}


Enemy* createEnemy(float size, char *path, int offset){

    char file[40];
    int r = rand() % NUM_ENEMY_SPRITES;

    sprintf(file, "%s%d.png", path, r);

    ALLEGRO_BITMAP *enemyBmp = al_load_bitmap(file);
    if(enemyBmp == NULL){
        printf("Error loading %s file", file);
        exit(1);
    }

    Enemy *enemy = (Enemy*)malloc(sizeof(Enemy));

    enemy->bmp = enemyBmp;

    enemy->val.baseHeight = (float)al_get_bitmap_height(enemy->bmp);
    enemy->val.baseWidth = (float)al_get_bitmap_width(enemy->bmp);

    enemy->val.height = enemy->val.baseHeight * 2 * size;
    enemy->val.width = enemy->val.baseWidth * 2 * size;

    enemy->val.x = STARTING_ENEMY_X + offset * 150 * size;
    enemy->val.y = STARTING_ENEMY_Y + 2 * enemy->val.baseHeight - enemy->val.height;

    enemy->mov = 20;

    return enemy;
}

void updateEnemy(Queue *enemyQueue, float speed){
    QueueNode *aux = enemyQueue->head;
    Enemy *enemy;

    while(aux != NULL){
        enemy = aux->data;
        aux = aux->next;

        enemy->val.x -= enemy->mov;

        if(enemy->val.x < - SCREEN_WIDTH / 2.0) // If enemy leaves screen
            destroyEnemy(dequeue(enemyQueue));

    }
}

void drawEnemy(Queue *enemyQueue) {
    Enemy *enemy;
    QueueNode *aux = enemyQueue->head;

    while (aux != NULL){
        enemy = aux->data;
        drawObject(enemy->bmp, enemy->val);
        aux = aux->next;
    }
}

void destroyEnemy(Enemy *enemy){
    al_destroy_bitmap(enemy->bmp);
    free(enemy);
}

