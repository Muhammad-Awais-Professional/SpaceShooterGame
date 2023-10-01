#ifndef ENNEMIES_H
#define ENNEMIES_H

#include <SFML/Graphics.hpp>
#include "bomb.h"

using namespace sf;

class Enemies{

    protected:
    Texture enemy_tex;

    public:

    Sprite enemy_sp;

    String name;

    bool move_flag;

    bool destroyed;

    bool bomb_in_air;

    Sprite *beam_sp;

    Texture *beam_tex; 

    int beam_ind;

    int total_beam;

    bool monster_bool;

    bool flag;

    bool monster_uptodown_transition;

    int monster_timer;

    bool monster_right;

    bool monster_done;

    Enemies(){

        total_beam = 0;

        beam_ind = 0;

        beam_sp = NULL;

        beam_sp = NULL;

        bomb_in_air = false;

        destroyed = false;
        
        name = "alpha";

        enemy_sp.setPosition(350,20);

        move_flag = false;

    }

    virtual void moveEnemy(){

        if(enemy_sp.getPosition().x<=780-126 && !move_flag){
            enemy_sp.move(1,0);

            if(enemy_sp.getPosition().x>=780-126)
                move_flag = true;

        }
        else {

            enemy_sp.move(-1,0);

            if(enemy_sp.getPosition().x<=20)
                move_flag = false;
        }
    }

    virtual Bombs* getbomb()=0;

    virtual void firebomb()=0;

    virtual void dragonfire(Sprite sp, int i){
        ;
    }

    virtual ~Enemies(){};

};

#endif