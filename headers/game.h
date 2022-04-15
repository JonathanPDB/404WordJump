#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <math.h>

#include "config.h"
#include "baseObjects.h"
#include "words.h"
#include "dinosaur.h"
#include "queue.h"
#include "stack.h"
#include "physics.h"
#include "enemy.h"
#include "session.h"
#include "text.h"

#define MAX_SPEED (int)(FPS * 1.2)

void gameLoop(Config *cfg, GameSession *session);

#endif //GAME_GAME_H
