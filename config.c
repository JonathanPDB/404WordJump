#include "headers/config.h"

Preferences* loadPreferences(){

    Preferences *prefs = (Preferences*) malloc(sizeof(Preferences));

    setThemePreferences(prefs, 0);
    prefs->bgColour = al_map_rgb(255, 220, 255);

    return prefs;
}

Audio* createAudio(){

    Audio *audio = (Audio*)malloc(sizeof(Audio));

    al_reserve_samples(4);

    audio->select = al_load_sample(SELECT_SOUND_PATH);
    audio->jump = al_load_sample(JUMP_SOUND_PATH);
    audio->death = al_load_sample(DEATH_SOUND_PATH);

    ALLEGRO_SAMPLE *megalovaniaSample = al_load_sample(MEGALOVANIA_PATH);
    audio->megalovania = al_create_sample_instance(megalovaniaSample);

    al_set_sample_instance_playmode(audio->megalovania, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(audio->megalovania, al_get_default_mixer());

    return audio;
}

System* createSystem(){

    System *sys = (System*)malloc(sizeof(System));

    sys->eventQueue = al_create_event_queue();
    sys->timer = al_create_timer(1.0 / FPS);
    sys->display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);

    al_register_event_source(sys->eventQueue, al_get_timer_event_source(sys->timer));
    al_register_event_source(sys->eventQueue, al_get_display_event_source(sys->display));
    al_register_event_source(sys->eventQueue, al_get_keyboard_event_source());

    return sys;
}

Fonts* createFonts(){
    Fonts *fonts = (Fonts*) malloc(sizeof(Fonts));

    fonts->titleArcade = al_load_ttf_font("../external/fonts/ARCADECLASSIC.ttf", TITLE_SIZE, 0);
    fonts->bigArcade = al_load_ttf_font("../external/fonts/ARCADECLASSIC.ttf", GAMEWORD_SIZE, 0);
    fonts->bigVt = al_load_ttf_font("../external/fonts/VtRegular.ttf", BIG_TEXT_SIZE, 0);
    fonts->mediumVt = al_load_ttf_font("../external/fonts/VtRegular.ttf", MEDIUM_TEXT_SIZE, 0);
    fonts->smallVt = al_load_ttf_font("../external/fonts/VtRegular.ttf", SMALL_TEXT_SIZE, 0);
    fonts->tinyVt = al_load_ttf_font("../external/fonts/VtRegular.ttf", TINY_TEXT_SIZE, 0);

    return fonts;
}

Config* createConfig(){

    Config *config = (Config*)malloc(sizeof(Config));

    config->sys = createSystem();
    config->prefs = loadPreferences();
    config->fonts = createFonts();
    config->audio = createAudio();

    return config;
}

void setThemePreferences(Preferences *prefs, int theme){
    switch (theme) {
    case 0:
        strcpy(prefs->dinoPath, FRUIT_DINO_PATH);
        strcpy(prefs->enemyPath, ICECREAM_BASE_PATH);
        strcpy(prefs->listPath, FRUITS_PATH);
        prefs->bgColour = al_map_rgb(255, 220, 255);
        break;
    case 1:
        strcpy(prefs->dinoPath, ANIMAL_DINO_PATH);
        strcpy(prefs->enemyPath, PENGUIN_BASE_PATH);
        strcpy(prefs->listPath, ANIMALS_PATH);
        prefs->bgColour = al_map_rgb(220, 255, 255);
        break;
    }
}

void destroyPreferences(Preferences *preferences){
    free(preferences);
}

void destroyAudio(Audio *audio){

    al_destroy_sample(audio->select);
    al_destroy_sample(audio->jump);
    al_destroy_sample(audio->death);
    al_destroy_sample_instance(audio->megalovania);

    free(audio);
}

void destroySystem(System *sys){
    free(sys);
}

void destroyFonts(Fonts *fonts){
    al_destroy_font(fonts->titleArcade);
    al_destroy_font(fonts->bigVt);
    al_destroy_font(fonts->mediumVt);
    al_destroy_font(fonts->smallVt);
    al_destroy_font(fonts->tinyVt);

    free(fonts);
}

void destroyConfig(Config *cfg){
    destroyPreferences(cfg->prefs);
    destroyAudio(cfg->audio);
    destroySystem(cfg->sys);
    destroyFonts(cfg->fonts);
    free(cfg);
}



