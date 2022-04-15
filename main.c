#include <stdlib.h>
#include <time.h>

#include "headers/screens.h"
#include "headers/game.h"
#include "headers/session.h"
#include "headers/config.h"

int main() {

    int menuOption;

    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_init_primitives_addon();
    al_install_keyboard();
    al_install_audio();
    al_init_acodec_addon();

    srand(time(NULL));

    Config *cfg = createConfig();
    GameSession *gameSession;

    titleScreen(cfg);

    do{
        menuOption = menuScreen(cfg);
        switch (menuOption) {
            case 0:
                gameSession = startGameSession();
                gameSession->difficulty = chooseDifficultyScreen(cfg);
                gameSession->theme = chooseThemeScreen(cfg);
                setThemePreferences(cfg->prefs, gameSession->theme);

                gameLoop(cfg, gameSession);
                youDiedScreen(cfg, gameSession);
                destroyGameSesion(gameSession);
                break;
            case 1:
                howToPlayScreen(cfg);
                break;
            case 2:
                rankingScreen(cfg);
                break;
            case 3:
                creditsScreen(cfg);
                break;
            case 4:
                destroyConfig(cfg);
                break;

        }
    }while(menuOption != 4);

    return 0;
}
