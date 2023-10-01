#include "enemies.h"

class Dragon: public Enemies{

public:

    Dragon(){

        enemy_tex.loadFromFile("img/Dragon/dragon.png");

        enemy_sp.setTexture(enemy_tex);

        enemy_sp.setPosition(270,10);

        monster_bool = false;

        monster_done = false;

        beam_tex = new Texture;

        beam_sp = new Sprite[20];

        beam_tex->loadFromFile("img/Dragon/flame.png");

        total_beam = 20;

        beam_ind = 0;

        monster_right = false;

        monster_uptodown_transition = false;

        for(int i=0;i<total_beam;i++){
            beam_sp[i].setTexture(beam_tex[0]);

            beam_sp[i].setScale(0.1,0.1);

            beam_sp[i].setPosition(enemy_sp.getPosition().x+95,enemy_sp.getPosition().y+(240+(i*16)));
        }
        enemy_sp.setPosition(270,-300);

    }

    // void dragonfire(Sprite sp,int i){
        
    //     if(beam_sp[i].getPosition().x<sp.getPosition().x+17 && beam_sp[total_beam-1].getPosition().y<600){

    //         if(beam_sp[i].getPosition().x<=360-i*20)
    //             beam_sp[i].move(2.5,0);
            
    //     }
    //     else if(beam_sp[i].getPosition().x>sp.getPosition().x){
    //         if(beam_sp[i].getPosition().x<=360+i*20)    
    //             beam_sp[i].move(-1,0);
    //     }

    // }    //Re attampting

    void dragonfire(Sprite sp, int i) {
        static int rippleState = 0;
        rippleState = (rippleState + 1) % 100;

        float dragonMouthX = enemy_sp.getPosition().x + 100;
        float dragonMouthY = enemy_sp.getPosition().y + 250;

        float playerX = sp.getPosition().x;
        float playerY = sp.getPosition().y;

        float directionX = playerX - dragonMouthX;
        float directionY = playerY - dragonMouthY;
        float length = sqrt(directionX * directionX + directionY * directionY);
        directionX /= length;
        directionY /= length;

        float distance = i * 25.0f;
        float targetX = dragonMouthX + distance * directionX;
        float targetY = dragonMouthY + distance * directionY;

        if (rippleState < 50) {
            if (i % 2 == 0) {
                targetY += 15.0f;
            } else {
                targetY -= 15.0f;
            }
        }

        float currentX = beam_sp[i].getPosition().x;
        float currentY = beam_sp[i].getPosition().y;

        float moveDirectionX = targetX - currentX;
        float moveDirectionY = targetY - currentY;
        float moveLength = sqrt(moveDirectionX * moveDirectionX + moveDirectionY * moveDirectionY);
        moveDirectionX /= moveLength;
        moveDirectionY /= moveLength;

        float speed = 2.5f;

        beam_sp[i].move(speed * moveDirectionX, speed * moveDirectionY);
    }


    void firebomb(){;}

    Bombs* getbomb(){
        return NULL;
    }

};