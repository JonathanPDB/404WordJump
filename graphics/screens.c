#include "../headers/screens.h"

void titleScreen(Config *cfg){
    Dino *dino = createDino(cfg->prefs->dinoPath);

    al_clear_to_color(cfg->prefs->bgColour);

    drawCenteredTitle(cfg->fonts);
    al_draw_text(cfg->fonts->smallVt, al_map_rgb(0, 0, 0), CENTERED_X, (int)(SCREEN_HEIGHT / 2), ALLEGRO_ALIGN_CENTER, "Press  any  key  to  continue...");
    drawDino(dino);
    al_flip_display();

    waitKeyPress(cfg);

    destroyDino(dino);
}

int menuScreen(Config *cfg){
    Dino *dino = createDino(cfg->prefs->dinoPath);

    int highlighted = 0, exitLoop = 0, numOptions = 5;
    char *options[] = {
            "Play",
            "How to Play",
            "Ranking",
            "Credits",
            "Exit"
    };

    al_flush_event_queue(cfg->sys->eventQueue);

    do{
        ALLEGRO_EVENT event;
        al_wait_for_event(cfg->sys->eventQueue, &event);

        if(event.type == ALLEGRO_EVENT_KEY_DOWN){
            al_play_sample(cfg->audio->select, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
            switch (event.keyboard.keycode) {
                case ALLEGRO_KEY_DOWN:
                    if(highlighted < numOptions - 1)
                        highlighted ++;
                    break;
                case ALLEGRO_KEY_UP:
                    if(highlighted  > 0)
                        highlighted --;
                    break;
                case ALLEGRO_KEY_ENTER:
                    exitLoop = 1;
                    break;
            }
        }
        else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            exit(0);
        }

        al_clear_to_color(cfg->prefs->bgColour);
        drawCenteredTitle(cfg->fonts);
        drawMenu(cfg->fonts, options, NULL, numOptions, highlighted);
        drawDino(dino);

        al_flip_display();
    }while(!exitLoop);

    destroyDino(dino);

    return highlighted;
}

void creditsScreen(Config *cfg){
    char *credits[9] = {"Idea and Development:",
                        "Jonathan Paul Drimeyer Brown",
                        "",
                        "Universidade Federal do Rio Grande do Sul",
                        "",
                        "Data Structures I Class",
                        "PhD Thiago L. T. da Silveira",
                        "",
                        "2022"};

    int i;

    Dino *dino = createDino(cfg->prefs->dinoPath);

    al_clear_to_color(cfg->prefs->bgColour);
    drawCenteredTitle(cfg->fonts);

    for(i=0;i<9;i++)
        al_draw_text(cfg->fonts->tinyVt, al_map_rgb(0, 0, 0), CENTERED_X, (int)(SCREEN_HEIGHT / 3 + 80 * i), ALLEGRO_ALIGN_CENTER, credits[i]);

    drawDino(dino);
    al_flip_display();

    waitKeyPress(cfg);

    destroyDino(dino);
}

void howToPlayScreen(Config *cfg){
    char *howTo[10] = {"Your objetive is to survive the longest possible!",
                         "",
                         "Jump by typing a letter",
                         "But be careful, it must compose a valid word!",
                         "",
                         "You are allowed 3 backspaces",
                         "And you can't repeat the same word each time",
                         "",
                         "Get bonuses by typing words mid-air!"};

    int i;

    Dino *dino = createDino(cfg->prefs->dinoPath);

    al_clear_to_color(cfg->prefs->bgColour);
    drawCenteredTitle(cfg->fonts);

    for(i=0;i<9;i++)
        al_draw_text(cfg->fonts->tinyVt, al_map_rgb(0,0,0), (int)(SCREEN_WIDTH/2), (int)(SCREEN_HEIGHT / 3 + 80 * i), ALLEGRO_ALIGN_CENTER, howTo[i]);

    drawDino(dino);
    al_flip_display();

    waitKeyPress(cfg);

    destroyDino(dino);
}

int chooseDifficultyScreen(Config *cfg){
    int highlighted = 0, exitLoop = 0, numOptions = 4;
    char *options[] = {
            "Easy",
            "Challenging",
            "Hard",
            "Expert"
    };
    char *descriptions[] = {
            "You can't repeat the last 2 words",
            "You can't repeat the last 5 words",
            "You can't repeat the last 8 words",
            "You can't repeat any words"
    };

    Dino *dino = createDino(cfg->prefs->dinoPath);

    do{
        ALLEGRO_EVENT event;
        al_wait_for_event(cfg->sys->eventQueue, &event);

        if(event.type == ALLEGRO_EVENT_KEY_DOWN){
            al_play_sample(cfg->audio->select, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
            switch (event.keyboard.keycode) {
                case ALLEGRO_KEY_DOWN:
                    if(highlighted < numOptions - 1)
                        highlighted ++;
                    break;
                case ALLEGRO_KEY_UP:
                    if(highlighted  > 0)
                        highlighted --;
                    break;
                case ALLEGRO_KEY_ENTER:
                    exitLoop = 1;
                    break;
            }
        }
        else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            exit(0);
        }

        al_clear_to_color(cfg->prefs->bgColour);

        drawCenteredTitle(cfg->fonts);
        drawCenteredSubtitle(cfg->fonts, "Choose Difficulty");
        drawMenu(cfg->fonts, options, descriptions, numOptions, highlighted);
        drawDino(dino);

        al_flip_display();
    }while(!exitLoop);

    destroyDino(dino);

    return highlighted;
}

int chooseThemeScreen(Config *cfg){
    int highlighted = 0, exitLoop = 0, numOptions = 3;
    char *options[] = {
            "Fruits and Vegetables",
            "Animals",
            "Yet to be developed"
    };

    Dino *dino = createDino(cfg->prefs->dinoPath);

    al_flush_event_queue(cfg->sys->eventQueue);

    do{
        ALLEGRO_EVENT event;
        al_wait_for_event(cfg->sys->eventQueue, &event);

        if(event.type == ALLEGRO_EVENT_KEY_DOWN){
            al_play_sample(cfg->audio->select, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
            switch (event.keyboard.keycode) {
                case ALLEGRO_KEY_DOWN:
                    if(highlighted < numOptions - 2)
                        highlighted ++;
                    break;

                case ALLEGRO_KEY_UP:
                    if(highlighted  > 0)
                        highlighted --;
                    break;

                case ALLEGRO_KEY_ENTER:
                    exitLoop = 1;
                    break;
            }
        }
        else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            exit(0);
        }

        al_clear_to_color(cfg->prefs->bgColour);
        drawCenteredTitle(cfg->fonts);
        drawCenteredSubtitle(cfg->fonts, "Choose Theme");
        drawMenu(cfg->fonts, options, NULL, numOptions, highlighted);
        drawDino(dino);

        al_flip_display();
    }while(!exitLoop);

    destroyDino(dino);

    al_flip_display();

    return highlighted;
}

void rankingScreen(Config *cfg){
    int highlighted=0, i=0, j, exitLoop = 0, selectedRanking=0, redraw = 1, numOptions = 6;
    int offset = SCREEN_WIDTH * 1/3 / numOptions;
    long points[10];
    char names[10][16], entries[10][32], fileBuffer[50], subtitle[30];
    char *options[]={
            "Easy",
            "Challenging",
            "Hard",
            "Expert",
            "Clear",
            "Back"
    };



    al_flush_event_queue(cfg->sys->eventQueue);

    do{
        ALLEGRO_EVENT event;
        al_wait_for_event(cfg->sys->eventQueue, &event);



        if(event.type == ALLEGRO_EVENT_KEY_DOWN){
            al_play_sample(cfg->audio->select, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
            if(event.keyboard.keycode == ALLEGRO_KEY_DOWN) {
                if (highlighted < numOptions - 1)
                    highlighted++;
            }
            else if(event.keyboard.keycode == ALLEGRO_KEY_UP){
                if(highlighted  > 0)
                    highlighted --;
            }
            else if(event.keyboard.keycode == ALLEGRO_KEY_ENTER){
                if(highlighted == 4){
                    sprintf(fileBuffer, "../external/saves/rankings%d.bin", selectedRanking);
                    FILE *rankings = fopen(fileBuffer, "w");

                    for(i=0;i<10;i++)
                        fprintf(rankings, "0 -\n");

                    fclose(rankings);
                }
                else if(highlighted == 5){
                    exitLoop = 1;
                }
                else{
                    selectedRanking = highlighted;
                }
            }

            redraw = 1;

        }

        if(redraw){
            sprintf(fileBuffer, "../external/saves/rankings%d.bin", selectedRanking);
            FILE *rankings = fopen(fileBuffer, "rb");
            fseek(rankings, 0, 0);

            i = 0;
            while(!feof(rankings)){
                fscanf(rankings, "%ld %s", &points[i], names[i]);
                sprintf(entries[i], "%-16s %10ld", names[i], points[i]);
                i ++;
            }
            fclose(rankings);

            sprintf(subtitle, "Ranking - %s", options[selectedRanking]);

            al_clear_to_color(cfg->prefs->bgColour);
            drawCenteredTitle(cfg->fonts);
            drawCenteredSubtitle(cfg->fonts, subtitle);
            for(i=0; i<numOptions; i++)
                al_draw_text(cfg->fonts->smallVt, al_map_rgb(255 * (highlighted == i), 0, 0), CENTERED_X / 3, (TITLE_Y + 350 + i * offset), ALLEGRO_ALIGN_CENTER, options[i]);
            for(i=0;i<10;i++){
                al_draw_text(cfg->fonts->tinyVt, al_map_rgb(0, 0, 0), CENTERED_X * 4 / 3, TITLE_Y + 450 + i * 50, ALLEGRO_ALIGN_CENTER, entries[i]);
            }
            al_flip_display();

            redraw = 0;
        }

    }while(!exitLoop);
}

void youDiedScreen(Config *cfg, GameSession *session){

    long i, step;

    al_clear_to_color(cfg->prefs->bgColour);
    al_draw_text(cfg->fonts->titleArcade, al_map_rgb(255, 0, 0), CENTERED_X, CENTERED_Y - TITLE_SIZE, ALLEGRO_ALIGN_CENTRE, "YOU DIED");
    al_flip_display();

    waitForSomeTime(cfg->sys, 1.5f);

    char pointsBuffer[18], wordScoreBuffer[30], totalWordPointsBuffer[12], totalBuffer[15];
    step = 1 + session->points / 300;

    for(i=1; i<=session->points; i+=step){
        sprintf(pointsBuffer, "%ld", i);
        al_clear_to_color(cfg->prefs->bgColour);
        al_draw_text(cfg->fonts->bigArcade, al_map_rgb(0, 0, 0), CENTERED_X, TITLE_Y, ALLEGRO_ALIGN_CENTRE, "Score");
        al_draw_text(cfg->fonts->bigVt, al_map_rgb(0, 255, 0), CENTERED_X, CENTERED_Y - 100, ALLEGRO_ALIGN_CENTRE, pointsBuffer);
        al_flip_display();
    }

    Word *word;

    long wordScore = 0,totalWordScore = 0, total;

    while(!isStackEmpty(session->typedWords)){
        word = popStack(session->typedWords);

        wordScore = word->value * word->bonus;
        totalWordScore += wordScore;

        sprintf(wordScoreBuffer, "%s  %d  x%d  =  %ld", word->w, word->value, word->bonus, wordScore);
        sprintf(pointsBuffer, "Distance: %ld", session->points);
        sprintf(totalWordPointsBuffer, "%ld", totalWordScore);

        al_clear_to_color(cfg->prefs->bgColour);
        al_draw_text(cfg->fonts->bigArcade, al_map_rgb(0, 0, 0), CENTERED_X, TITLE_Y, ALLEGRO_ALIGN_CENTRE, "Score");
        al_draw_text(cfg->fonts->bigVt, al_map_rgb(0, 0, 0), CENTERED_X, TITLE_Y + 200, ALLEGRO_ALIGN_CENTRE, pointsBuffer);
        al_draw_text(cfg->fonts->bigVt, al_map_rgb(0, 0, 0), CENTERED_X, TITLE_Y + 400, ALLEGRO_ALIGN_CENTRE, totalWordPointsBuffer);
        al_draw_text(cfg->fonts->bigVt, al_map_rgb(0, 255, 0), CENTERED_X, TITLE_Y + 600, ALLEGRO_ALIGN_CENTRE, wordScoreBuffer);

        al_flip_display();
        waitForSomeTime(cfg->sys, 1.0f);

   }

    total = session->points + totalWordScore;

    sprintf(pointsBuffer, "Distance: %ld", session->points);
    sprintf(totalWordPointsBuffer, "Words: %ld", totalWordScore);
    sprintf(totalBuffer, "Total: %ld", total);

    int highlighted = 0, exitLoop=0;

    al_flush_event_queue(cfg->sys->eventQueue);

    do{
        al_clear_to_color(cfg->prefs->bgColour);
        al_draw_text(cfg->fonts->mediumVt, al_map_rgb(255 * (!highlighted), 0, 0), SCREEN_WIDTH * 1 / 3, TITLE_Y + 1000, ALLEGRO_ALIGN_CENTRE, "Save");
        al_draw_text(cfg->fonts->mediumVt, al_map_rgb(255 * (highlighted), 0, 0), SCREEN_WIDTH * 2 / 3, TITLE_Y + 1000, ALLEGRO_ALIGN_CENTRE, "Exit");

        al_draw_text(cfg->fonts->bigArcade, al_map_rgb(0, 0, 0), CENTERED_X, TITLE_Y, ALLEGRO_ALIGN_CENTRE, "Score");
        al_draw_text(cfg->fonts->bigVt, al_map_rgb(0, 0, 0), CENTERED_X, TITLE_Y + 200, ALLEGRO_ALIGN_CENTRE, pointsBuffer);
        al_draw_text(cfg->fonts->bigVt, al_map_rgb(0, 0, 0), CENTERED_X, TITLE_Y + 400, ALLEGRO_ALIGN_CENTRE, totalWordPointsBuffer);
        al_draw_text(cfg->fonts->bigVt, al_map_rgb(0, 0, 255), CENTERED_X, TITLE_Y + 800, ALLEGRO_ALIGN_CENTRE, totalBuffer);
        al_flip_display();

        ALLEGRO_EVENT event;
        al_wait_for_event(cfg->sys->eventQueue, &event);

        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            al_play_sample(cfg->audio->select, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);

            if(event.keyboard.keycode == ALLEGRO_KEY_RIGHT)
                highlighted = 1;
            else if(event.keyboard.keycode == ALLEGRO_KEY_LEFT)
                highlighted = 0;
            else if(event.keyboard.keycode == ALLEGRO_KEY_ENTER)
                exitLoop = 1;
        }
        else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            exit(0);
        }

    } while(!exitLoop);

    session->points = total;

    if(!highlighted)
        saveScreen(cfg, session);

}

void saveScreen(Config *cfg, GameSession *session){

    char name[NAME_SIZE];
    char pointsBuffer[30], fileBuffer[50];
    int exitLoop = 0, pos = 0, i;

    for(i=0; i<NAME_SIZE; i++)
        name[i] = '_';

    sprintf(fileBuffer, "../external/saves/rankings%d.bin", session->difficulty);

    al_flush_event_queue(cfg->sys->eventQueue);

    do{
        ALLEGRO_EVENT event;
        al_wait_for_event(cfg->sys->eventQueue, &event);

        sprintf(pointsBuffer, "Total Points: %ld", session->points);
        al_clear_to_color(cfg->prefs->bgColour);
        al_draw_text(cfg->fonts->bigVt, al_map_rgb(0, 0, 0), CENTERED_X, TITLE_Y, ALLEGRO_ALIGN_CENTRE, "Save Score");
        al_draw_text(cfg->fonts->mediumVt, al_map_rgb(0, 0, 255), CENTERED_X, TITLE_Y + 400, ALLEGRO_ALIGN_CENTRE, pointsBuffer);
        al_draw_text(cfg->fonts->mediumVt, al_map_rgb(0, 0, 255), CENTERED_X, TITLE_Y + 600, ALLEGRO_ALIGN_CENTRE, name);
        al_flip_display();

        if(event.type == ALLEGRO_EVENT_KEY_DOWN){
            al_play_sample(cfg->audio->select, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
            if(event.keyboard.keycode >= ALLEGRO_KEY_A && event.keyboard.keycode <= ALLEGRO_KEY_Z && pos < NAME_SIZE){
                name[pos] = (char)(event.keyboard.keycode + 0x40);
                pos ++;
            }
            else if(event.keyboard.keycode == ALLEGRO_KEY_SPACE && pos){
                name[pos] = ' ';
                pos ++;
            }
            else if(event.keyboard.keycode == ALLEGRO_KEY_BACKSPACE && pos){
                pos --;
                name[pos] = '_';
            }
            else if(event.keyboard.keycode == ALLEGRO_KEY_ENTER && pos){
                name[pos] = '\0';
                exitLoop = 1;
            }
        }
        else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            exit(0);
        }

    }while(!exitLoop);


    char names[10][16];
    long points[10];
    int insertIndex=-1;


    FILE *rankings = fopen(fileBuffer, "rb");
    fseek(rankings, 0, 0);
    i=0;
    while(!feof(rankings)){
        fscanf(rankings, "%ld %s", &points[i], names[i]);
        i ++;
    }
    fclose(rankings);

    for(i=0;i<10;i++)
        if(session->points>points[i]){
            insertIndex = i;
            break;
        }

    if(insertIndex!= -1){
        for(i=9;i>insertIndex;i--){
            strcpy(names[i], names[i - 1]);
            points[i] = points[i-1];
        }
        strcpy(names[i], name);
        points[i] = session->points;

        rankings = fopen(fileBuffer, "w");

        for(i=0;i<10;i++)
            fprintf(rankings, "%ld %s\n", points[i], names[i]);

        fclose(rankings);
    }

    rankingScreen(cfg);

}