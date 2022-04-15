#include "../headers/physics.h"

float getJumpMultiplier(int jumpFrame){
    return 1 - (JUMP_A*(float)jumpFrame - JUMP_B*(float)(jumpFrame*jumpFrame)/2);
}

int checkCollision(Dino *dino, Queue *enemyQueue){

    if(isQueueEmpty(enemyQueue))
        return 0;

    QueueNode *aux     = enemyQueue->head;
    Enemy *enemy = aux->data;

    while(enemy->val.x <= (dino->val.x + dino->val.width)){

        if(0.95*(dino->val.x + dino->val.width) > enemy->val.x && 1.1*dino->val.x < enemy->val.x + enemy->val.width)
            if((dino->val.y + dino->val.height) > enemy->val.y)
                return 1;

        if(aux->next != NULL){
            aux = aux->next;
            enemy = aux->data;
        }
        else
            break;
    }


    return 0;

}