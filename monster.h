#include <SFML/Graphics.hpp>
#include "enemies.h"

using namespace sf;

class Monster: public Enemies{

public:

    Monster(){
        
        monster_bool = false;
        monster_right = false;
        monster_timer = 0;
        monster_uptodown_transition = false;
        flag = false;

        total_beam = 6;

        beam_tex = new Texture[total_beam];

        beam_tex[0].loadFromFile("img/Monster/monsterbeam0.png");
        beam_tex[1].loadFromFile("img/Monster/monsterbeam1.png");
        beam_tex[2].loadFromFile("img/Monster/monsterbeam2.png");
        beam_tex[3].loadFromFile("img/Monster/monsterbeam3.png");
        beam_tex[4].loadFromFile("img/Monster/monsterbeam4.png");
        beam_tex[5].loadFromFile("img/Monster/monsterbeam5.png");

        beam_sp = new Sprite[total_beam];

        beam_sp[0].setTexture(beam_tex[0]);
        beam_sp[1].setTexture(beam_tex[1]);
        beam_sp[2].setTexture(beam_tex[2]);
        beam_sp[3].setTexture(beam_tex[3]);
        beam_sp[4].setTexture(beam_tex[4]);
        beam_sp[5].setTexture(beam_tex[5]);

        beam_ind = 0;

        enemy_tex.loadFromFile("img/Monster/monster.png");
        enemy_sp.setTexture(enemy_tex);
        name = "monster";
        enemy_sp.setPosition(200,10);
        enemy_sp.setScale(0.3,0.3);

        for(int i=0;i<total_beam;i++){

            beam_sp[i].setScale(2,2);

        }

        for(int i=0;i<total_beam;i++)
            beam_sp[i].setPosition(enemy_sp.getPosition().x+25,enemy_sp.getPosition().y+115);

    }    

    virtual Bombs* getbomb(){
        return NULL;
    };

    void moveEnemy(){
        
        if(enemy_sp.getPosition().x<=780-420 && !move_flag){
            enemy_sp.move(1,0);

            if(enemy_sp.getPosition().x>=780-420)
                move_flag = true;

        }
        else {

            enemy_sp.move(-1,0);

            if(enemy_sp.getPosition().x<=20)
                move_flag = false;
        }
    }

    virtual void firebomb(){

        beam_sp[beam_ind].setPosition(enemy_sp.getPosition().x+60,enemy_sp.getPosition().y+115);

        if(beam_ind<total_beam-1){
            beam_ind++;
        }
        else{
            beam_ind--;
        }

    }

};