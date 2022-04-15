#include "../headers/game.h"

void gameLoop(Config *cfg, GameSession *session){
    Dino    *dino           = createDino(cfg->prefs->dinoPath);
    Queue   *enemyQueue  = createQueue();
    Player  *player         = createPlayer();

    FILE *wordList = fopen(cfg->prefs->listPath, "r");

    BaseValues floorVals = {
            .x = 0,
            .y = DINO_Y + 220,
            .baseHeight = 1,
            .baseWidth = 1,
            .height = 1,
            .width = 4
    };
    Generic *floor = createGeneric("../external/images/floor", floorVals);

    char currentWord[22] = {0};
    int isWordValid = 0, redraw = 1, typedMidAir = 1;
    int speedCounter = 0, spawnCounter = 0, jumpFrame = 0;
    int spawnDelay = 3 * FPS, wrongCounter = 0;

    if(session->difficulty == 3)
        al_play_sample_instance(cfg->audio->megalovania);

    al_flush_event_queue(cfg->sys->eventQueue);
    al_start_timer(cfg->sys->timer);

    while(player->isAlive){

        ALLEGRO_EVENT event;
        al_wait_for_event(cfg->sys->eventQueue, &event);

        if(event.type == ALLEGRO_EVENT_KEY_DOWN){
            if(isWordValid == 1) {
                strcpy(currentWord, "");
                isWordValid = 0;
                typedMidAir = 1;
            }
            if((event.keyboard.keycode >= ALLEGRO_KEY_A && event.keyboard.keycode <= ALLEGRO_KEY_Z || event.keyboard.keycode == ALLEGRO_KEY_SPACE)) {
                if(event.keyboard.keycode == ALLEGRO_KEY_SPACE)
                    sprintf(currentWord, "%s%c", currentWord, ' ');
                else
                    sprintf(currentWord, "%s%c", currentWord, event.keyboard.keycode + 0x40);

                isWordValid = isInWordList(currentWord, wordList);

                if(isWordValid == -1) {
                    if (!session->backspaces || wrongCounter == 3)
                        player->isAlive = 0;
                    else
                        wrongCounter++;
                }else
                    wrongCounter=0;

                if(!player->isJumping)
                    typedMidAir = 0;

                if(isWordValid == 1) {
                    if (isWordRepeated(session, currentWord))
                        player->isAlive = 0;
                    else{
                        if(typedMidAir)
                            player->bonus *= 4;
                        else
                            player->bonus = 1;
                        pushStack(session->typedWords, createWord(currentWord, player->bonus));
                    }

                }

                if(!player->isJumping)
                    al_play_sample(cfg->audio->jump, 0.3f, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);

                player->isJumping = 1;

            }
            else if(event.keyboard.keycode == ALLEGRO_KEY_BACKSPACE && session->backspaces){
                session->backspaces --;
                currentWord[strlen(currentWord) - 1] = '\0';

                isWordValid = isInWordList(currentWord, wordList);
                if(isWordValid == -1 && !session->backspaces)
                    player->isAlive = 0;
            }
        }
        if(event.type == ALLEGRO_EVENT_TIMER){
            if(speedCounter == player->speed){
                if (dino->frame == 1)
                    dino->frame = 2;
                else
                    dino->frame = 1;

                speedCounter = 0;
            }
            if(spawnCounter == spawnDelay){
                spawnEnemy(enemyQueue, cfg->prefs->enemyPath, rand() % 8);

                if(spawnDelay > MAX_SPEED)
                    spawnDelay -= 5;

                printf("%d\n", spawnDelay);
                spawnCounter = 0;
            }
            if (player->isJumping) {
                dino->jumpMultiplier = getJumpMultiplier(jumpFrame);
                updateDino(dino);

                if (jumpFrame == JUMP_DURATION) {
                    player->isJumping = 0;
                    jumpFrame = 0;
                } else
                    jumpFrame++;

            }

            player->isAlive = !checkCollision(dino, enemyQueue);
            updateEnemy(enemyQueue, (float)player->speed);

            spawnCounter ++;
            speedCounter ++;
            redraw = 1;

        }
        if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            exit(0);
        }

        if(redraw && al_event_queue_is_empty(cfg->sys->eventQueue)){

            al_clear_to_color(cfg->prefs->bgColour);
            drawObject(floor->bmp, floor->val);
            drawDino(dino);
            drawEnemy(enemyQueue);
            drawGUI(cfg->fonts, session, currentWord, isWordValid, player->bonus);

            al_flip_display();

            redraw = 0;
        }
        session->points ++;

    }

    al_play_sample(cfg->audio->death, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);

    fclose(wordList);

    if(session->difficulty == 3)
        al_stop_sample_instance(cfg->audio->megalovania);

    al_stop_timer(cfg->sys->timer);
    destroyPlayer(player);
    destroyDino(dino);
    destroyGeneric(floor);
    destroyQueue(enemyQueue);
}