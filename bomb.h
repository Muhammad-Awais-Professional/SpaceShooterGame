#ifndef BOMB_H
#define BOMB_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Bombs{

private:


public:

    Sprite bomb_sp;
    Texture alphabomb, betabomb, gammabomb;
    float speed;
    bool shooted;

    Bombs(){

        shooted = false;

        alphabomb.loadFromFile("img/Enemies/Bomb/alphabomb.png");     
        
        betabomb.loadFromFile("img/Enemies/Bomb/betabomb.png");        
        
        gammabomb.loadFromFile("img/Enemies/Bomb/gammabomb.png");        

        speed = 3;

        bomb_sp.setTexture(alphabomb);

        //bomb_sp.setScale(0.5,0.5);

        bomb_sp.setPosition(-1000,-1000);

    }

    bool KillPlayer(Sprite sp){

        /*//not the best -> *///if(bomb_sp.getPosition().x+13>=sp.getPosition().x && bomb_sp.getPosition().y+57 >=sp.getPosition().y+103 && bomb_sp.getPosition().x<=sp.getPosition().x +107 && bomb_sp.getPosition().y+57<=sp.getPosition().y+103)


        if((bomb_sp.getPosition().x >= sp.getPosition().x||bomb_sp.getPosition().x+13 >= sp.getPosition().x) && bomb_sp.getPosition().y >= sp.getPosition().y && bomb_sp.getPosition().x+13 <= sp.getPosition().x+103 && bomb_sp.getPosition().y+57 <= sp.getPosition().y+107)
        
            return true;

        return false;

    }

    void bombmove(String name, float x, float y){  //send enemy location in x and y.

        if(name=="alpha"){
            bomb_sp.setTexture(alphabomb);
        }

        else if(name=="beta"){
            bomb_sp.setTexture(betabomb);
        }

        else if(name=="gamma"){
            bomb_sp.setTexture(gammabomb);
        }

        if(name == "alpha" ){

            if((bomb_sp.getPosition().x != x+43 && bomb_sp.getPosition().y != y) && !shooted){
                bomb_sp.setPosition(x+43,y);
                shooted = true;
            }
            else
                bomb_sp.move(0,+5);

            if(bomb_sp.getPosition().y>=780){
                shooted = false;
            }

        }
        else if(name == "beta"){

            if((bomb_sp.getPosition().x != x+56 && bomb_sp.getPosition().y != y+20) && !shooted){
                bomb_sp.setPosition(x+56,y+20);
                shooted = true;
            }

            bomb_sp.move(0,+10);

            if(bomb_sp.getPosition().y>=780){
                shooted = false;
            }

        }
        else if(name =="gamma"){

            if((bomb_sp.getPosition().x != x+36 && bomb_sp.getPosition().y != y+27) && !shooted){
                bomb_sp.setPosition(x+36,y+27);
                shooted = true;
            }

            bomb_sp.move(0,+15);

            if(bomb_sp.getPosition().y>=780){
                shooted = false;
            }

        }

    }

};

#endif