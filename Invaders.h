#include "enemies.h"

class Invaders: public Enemies{

public:

    Bombs* bomb;

    Invaders(Bombs* bomb){

        this->bomb = bomb;

        bomb->bomb_sp.setPosition(enemy_sp.getPosition().x+43,enemy_sp.getPosition().y-5);

    }
    
    virtual Bombs* getbomb(){
        return bomb;
    }

    virtual void firebomb()=0;
    
    virtual ~Invaders(){};

};

class Alpha: public Invaders{

public:

    Alpha(Bombs* bomb):Invaders(bomb){

        bomb->bomb_sp.setTexture(bomb->alphabomb);

        enemy_tex.loadFromFile("img/Enemies/Alpha.png");

        enemy_sp.setTexture(enemy_tex);

        enemy_sp.setScale(0.8,0.8);

        enemy_sp.setPosition(350,20);
        
        bomb->bomb_sp.setPosition(enemy_sp.getPosition().x+43,enemy_sp.getPosition().y);

        name = "alpha";

    }

    void firebomb(){

        if(!bomb_in_air){
            bomb->bomb_sp.setPosition(enemy_sp.getPosition().x+43,enemy_sp.getPosition().y);
            bomb_in_air = true;
        }
        else
            bomb->bomb_sp.move(0,+5);
        

        if(bomb->bomb_sp.getPosition().y>=750 && !destroyed){
            bomb_in_air = false;
        }

    }    

    ~Alpha(){}

};

class Beta: public Invaders{

public:

    Beta(Bombs* bomb):Invaders(bomb){

        bomb->bomb_sp.setTexture(bomb->betabomb);

        enemy_tex.loadFromFile("img/Enemies/Beta.png");

        enemy_sp.setTexture(enemy_tex);

        enemy_sp.setPosition(100,20);

        name = "beta";

        enemy_sp.setScale(0.7,0.7);
        
        bomb->bomb_sp.setPosition(enemy_sp.getPosition().x+56,enemy_sp.getPosition().y+20);

    }

    void firebomb(){

        if(!bomb_in_air){
            bomb->bomb_sp.setPosition(enemy_sp.getPosition().x+56,enemy_sp.getPosition().y+20);
            bomb_in_air = true;
        }
        else
            bomb->bomb_sp.move(0,+10);

        if(bomb->bomb_sp.getPosition().y>=750 && !destroyed){
            bomb_in_air = false;
        }

    }    
   
    ~Beta(){}

};

class Gamma: public Invaders{

public:

    Gamma(Bombs* bomb):Invaders(bomb){

        bomb->bomb_sp.setTexture(bomb->gammabomb);

        enemy_tex.loadFromFile("img/Enemies/Gamma.png");

        enemy_sp.setTexture(enemy_tex);

        name = "gamma";
        
        enemy_sp.setPosition(600,20);

        enemy_sp.setScale(0.7,0.7);

        bomb->bomb_sp.setPosition(enemy_sp.getPosition().x+36,enemy_sp.getPosition().y+27);

    }

    void firebomb(){

        if(!bomb_in_air){
            bomb->bomb_sp.setPosition(enemy_sp.getPosition().x+36,enemy_sp.getPosition().y+27);
            bomb_in_air = true;
        }
        else
            bomb->bomb_sp.move(0,+15);

        if(bomb->bomb_sp.getPosition().y>=750 &&!destroyed ){
            bomb_in_air = false;
        }

    }    

    ~Gamma(){}

};