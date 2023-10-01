#include "game.h"
// This game was coded on a macbook pro 2011, visial studio code, with mac version of SFML.
int main()
{
    srand(time(0));

    Game* g = new Game;

    while(g->m.getGameStarted()){
        g->start_game(); 
        if(g->m.getGameStarted()){
            delete g;
            g=new Game;
        }
        else{
            delete g;
        }
    }
    return 0;
}
