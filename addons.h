#ifndef ADDONS_H
#define ADDONS_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Addons{

protected:

    Texture addons_tex;

public:


    Sprite addons_sp;

    String name;

    int idx;

    bool consumed;

public:

    Addons(){

        idx = 0;

        consumed = false;

        name = "addon";

    }

    void move(){

        if(addons_sp.getPosition().y<=780){
            addons_sp.move(0,2.5);
        }
        else{
            consumed = false;
        }
    }

    void setConsumed(bool set){
        consumed = set;
    }

    bool getConsumed(){
        return consumed;
    }

    String getname(){
        return name;
    }

    Sprite getSprite(){
        return addons_sp;
    }

    void setnames(String n){

        name = n;

    }

    virtual bool collide(Sprite sprite) = 0;

};

class Danger: public Addons{

public:

    Danger(){

        addons_tex.loadFromFile("img/addons/poison.png");

        addons_sp.setTexture(addons_tex);

        name = "danger";

        addons_sp.setScale(0.15,0.15);

    }

    bool collide(Sprite sprite){

		float playerWidth = 103;
		float playerHeight = 107;
		float addonWidth = 512 * addons_sp.getScale().x;
		float addonHeight = 512 * addons_sp.getScale().y;

        if ((sprite.getPosition().x + playerWidth-40 >= addons_sp.getPosition().x &&
				sprite.getPosition().x <= addons_sp.getPosition().x + addonWidth &&
				sprite.getPosition().y + playerHeight >= addons_sp.getPosition().y &&
				sprite.getPosition().y <= addons_sp.getPosition().y + addonHeight-10))
		{
			return true;
		}
		
        return false;

    }

};

class Life: public Addons{

public:

    Life(){

        addons_tex.loadFromFile("img/addons/life.png");

        addons_sp.setTexture(addons_tex);

        name = "life";

    }

    bool collide(Sprite sprite){

		float playerWidth = 103;
		float playerHeight = 107;
		float addonWidth = 100 * addons_sp.getScale().x;
		float addonHeight = 100 * addons_sp.getScale().y;

        if ((sprite.getPosition().x + playerWidth-40 >= addons_sp.getPosition().x &&
				sprite.getPosition().x <= addons_sp.getPosition().x + addonWidth &&
				sprite.getPosition().y + playerHeight >= addons_sp.getPosition().y &&
				sprite.getPosition().y <= addons_sp.getPosition().y + addonHeight-10))
		{
			return true;
		}
		
        return false;

    }

};

class Fire: public Addons{

public: 

    Fire(){
        
        addons_tex.loadFromFile("img/addons/fire.png");

        addons_sp.setTexture(addons_tex);
        
        addons_sp.setScale(0.15,0.15);

        name = "fire";

    }

    bool collide(Sprite sprite){

		float playerWidth = 103;
		float playerHeight = 107;
		float addonWidth = 512 * addons_sp.getScale().x;
		float addonHeight = 512 * addons_sp.getScale().y;

        if ((sprite.getPosition().x + playerWidth-40 >= addons_sp.getPosition().x &&
				sprite.getPosition().x <= addons_sp.getPosition().x + addonWidth &&
				sprite.getPosition().y + playerHeight >= addons_sp.getPosition().y &&
				sprite.getPosition().y <= addons_sp.getPosition().y + addonHeight-10))
		{
			return true;
		}
		
        return false;

    }

};

class Powerup: public Addons{

public:

    Powerup(){
        
        addons_tex.loadFromFile("img/addons/flash.png");

        addons_sp.setTexture(addons_tex);
        
        addons_sp.setScale(0.15,0.15);

        name = "flash";

    }

    bool collide(Sprite sprite){

		float playerWidth = 103;
		float playerHeight = 107;
		float addonWidth = 512 * addons_sp.getScale().x;
		float addonHeight = 512 * addons_sp.getScale().y;

        if ((sprite.getPosition().x + playerWidth-40 >= addons_sp.getPosition().x &&
				sprite.getPosition().x <= addons_sp.getPosition().x + addonWidth &&
				sprite.getPosition().y + playerHeight >= addons_sp.getPosition().y &&
				sprite.getPosition().y <= addons_sp.getPosition().y + addonHeight-10))
		{
			return true;
		}
		
        return false;

    }

};

#endif