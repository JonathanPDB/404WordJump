#include "../headers/utils.h"

int waitKeyPress(Config *cfg){

    al_flush_event_queue(cfg->sys->eventQueue);
    do{
        ALLEGRO_EVENT event;
        al_wait_for_event(cfg->sys->eventQueue, &event);

        if(event.type == ALLEGRO_EVENT_KEY_DOWN){
            al_play_sample(cfg->audio->select, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
            return event.keyboard.keycode;
        }

        else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            exit(0);

    }while(1);

}

void waitForSomeTime(System *sys, float time){
    int exitLoop = 0;

    al_flush_event_queue(sys->eventQueue);

    al_set_timer_speed(sys->timer, time);
    al_start_timer(sys->timer);

    do{
        ALLEGRO_EVENT event;
        al_wait_for_event(sys->eventQueue, &event);

        if(event.type == ALLEGRO_EVENT_TIMER)
            exitLoop = 1;

        else if(event.type == ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode == ALLEGRO_KEY_ENTER)
            exitLoop = 1;

        else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            exit(0);

    }while(!exitLoop);

    al_stop_timer(sys->timer);
    al_set_timer_speed(sys->timer, 1.0 / FPS);

}

