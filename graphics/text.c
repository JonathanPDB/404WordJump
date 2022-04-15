#include "../headers/text.h"


void drawCenteredTitle(Fonts *fonts){
    al_draw_text(fonts->titleArcade, al_map_rgb(0, 0, 0), CENTERED_X, TITLE_Y, ALLEGRO_ALIGN_CENTER, GAME_NAME);
}

void drawCenteredSubtitle(Fonts *fonts, char *subtitle){
    al_draw_text(fonts->bigVt, al_map_rgb(0, 0, 0), CENTERED_X, SUBTITLE_Y, ALLEGRO_ALIGN_CENTER, subtitle);
}

void drawMenu(Fonts *fonts, char *options[], char *descriptions[], int numOptions, int highlighted){
    int i;
    int offset = SCREEN_WIDTH * 1/3 / numOptions;
    for(i=0; i<numOptions; i++){
        al_draw_text(fonts->smallVt, al_map_rgb(255 * (highlighted == i), 0, 0), CENTERED_X, (SCREEN_HEIGHT * 5 / 12 + i * offset), ALLEGRO_ALIGN_CENTER, options[i]);
        if(i == highlighted && descriptions != NULL)
            al_draw_text(fonts->tinyVt, al_map_rgb(0, 0, 0), CENTERED_X, (SCREEN_HEIGHT * 3 / 7 + i * offset) + 80, ALLEGRO_ALIGN_CENTER, descriptions[i]);

    }
}

void drawGUI(Fonts *fonts, GameSession *session, char *currentWord, int isWordValid, int bonus){
    char pointsBuffer[8], backspaceBuffer[3], bonusBuffer[7];

    sprintf(pointsBuffer, "%ld", session->points);
    sprintf(backspaceBuffer, "%d", session->backspaces);
    sprintf(bonusBuffer, "x%d", bonus);

    al_draw_text(fonts->smallVt, al_map_rgb(0, 0, 0), (int)(SCREEN_WIDTH / 2), (int)(SCREEN_HEIGHT * 9 / 10), ALLEGRO_ALIGN_CENTER, pointsBuffer);
    al_draw_text(fonts->mediumVt, al_map_rgb(0, 0, 0), (int)(SCREEN_WIDTH / 6), (int)(SCREEN_HEIGHT / 10), ALLEGRO_ALIGN_CENTER, "Backspaces");
    al_draw_text(fonts->smallVt, al_map_rgb(0, 0, 0), (int)(SCREEN_WIDTH / 6), (int)(SCREEN_HEIGHT / 10) + 100, ALLEGRO_ALIGN_CENTER, backspaceBuffer);
    al_draw_text(fonts->mediumVt, al_map_rgb(0, 0, 0), (int)(SCREEN_WIDTH - SCREEN_WIDTH / 6), (int)(SCREEN_HEIGHT / 10), ALLEGRO_ALIGN_CENTER, "Last word");
    printLastWord(fonts, session);
    if(isWordValid == -1)
        al_draw_text(fonts->bigArcade, al_map_rgb(255, 0, 0), (int)(SCREEN_WIDTH / 2), (int)(SCREEN_HEIGHT / 4), ALLEGRO_ALIGN_CENTER, currentWord);
    else if(!isWordValid)
        al_draw_text(fonts->bigArcade, al_map_rgb(0, 0, 0), (int)(SCREEN_WIDTH / 2), (int)(SCREEN_HEIGHT / 4), ALLEGRO_ALIGN_CENTER, currentWord);
    else{
        al_draw_text(fonts->bigArcade, al_map_rgb(0, 255, 0), (int)(SCREEN_WIDTH / 2), (int)(SCREEN_HEIGHT / 4), ALLEGRO_ALIGN_CENTER, currentWord);
        if(bonus != 1){
            ALLEGRO_TRANSFORM t;
            al_identity_transform(&t);
            int fy = al_get_font_line_height(fonts->bigVt);
            int fx = al_get_text_width(fonts->bigVt, bonusBuffer);

            al_translate_transform(&t, fx, fy);
            al_rotate_transform(&t, 3.1415f * 30 / 180);
            al_translate_transform(&t, (int)(SCREEN_WIDTH * 2/3), (int)(SCREEN_HEIGHT / 10));
            al_use_transform(&t);
            al_draw_text(fonts->bigVt, al_map_rgb(0, 0, 255), 0, 0, ALLEGRO_ALIGN_CENTER, bonusBuffer);
            al_invert_transform(&t);

            al_identity_transform(&t);
            al_use_transform(&t);
        }
    }

}

void printLastWord(Fonts *fonts, GameSession *session){
    StackNode *aux = session->typedWords->top;
    Word *word;

    if(aux == NULL)
        return;

    if(session->difficulty == 3)
        al_draw_text(fonts->tinyVt, al_map_rgb(0, 0, 0), (int)(SCREEN_WIDTH - SCREEN_WIDTH / 6), (int)(SCREEN_HEIGHT / 5.5), ALLEGRO_ALIGN_CENTER, "?");
    else{
        word = aux->data;
        al_draw_text(fonts->tinyVt, al_map_rgb(0, 0, 0), (int)(SCREEN_WIDTH - SCREEN_WIDTH / 6), (int)(SCREEN_HEIGHT / 5.5), ALLEGRO_ALIGN_CENTER, word->w);
    }

}