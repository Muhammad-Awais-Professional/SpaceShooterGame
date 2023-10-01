#include <SFML/Graphics.hpp>
using namespace sf;

class Bullets{

protected:

public:

    Sprite bullet_sp,UpRightBullet,UpLeftBullet,UpStraightBullet;
    Texture UpStraightBullet_tex,UpRightBullet_tex,UpLeftBullet_tex;

    Sprite Straight_fire_sp, UpRight_fire_sp, UpLeft_fire_sp;
    Texture Straight_fire_tex, UpRight_fire_tex, UpLeft_fire_tex;
    bool Fire_bool;
    bool movebullets;

    Bullets(){
        
        movebullets = false;
        
        UpRightBullet_tex.loadFromFile("img/PNG/Lasers/UpRightLaser.png");
        
        UpLeftBullet_tex.loadFromFile("img/PNG/Lasers/UpLeftLaser.png");

        UpStraightBullet_tex.loadFromFile("img/png/Lasers/laserBlue03.png");

        UpRightBullet.setTexture(UpRightBullet_tex);

        UpLeftBullet.setTexture(UpLeftBullet_tex);

        UpStraightBullet.setTexture(UpStraightBullet_tex);

        bullet_sp = UpStraightBullet;

        bullet_sp.setPosition(780,780);

        Fire_bool = false;

        Straight_fire_tex.loadFromFile("img/PNG/Lasers/firebullet.png");
        UpLeft_fire_tex.loadFromFile("img/PNG/Lasers/UpLeftFire.png");
        UpRight_fire_tex.loadFromFile("img/PNG/Lasers/UpRightFire.png");

        Straight_fire_sp.setTexture(Straight_fire_tex);
        UpLeft_fire_sp.setTexture(UpLeft_fire_tex);
        UpRight_fire_sp.setTexture(UpRight_fire_tex);

    }

    bool KillEnemy(String name,Sprite sp, int &score){

        if(name == "alpha"){
            if((bullet_sp.getPosition().x >= sp.getPosition().x||bullet_sp.getPosition().x+13 >= sp.getPosition().x) && bullet_sp.getPosition().y >= sp.getPosition().y && bullet_sp.getPosition().x+13 <= sp.getPosition().x+(124*sp.getScale().x) && bullet_sp.getPosition().y+57 <= sp.getPosition().y+(106*sp.getScale().y)){
                score+=10;
                return true;
            }
        }
        else if(name == "beta"){
            if((bullet_sp.getPosition().x >= sp.getPosition().x||bullet_sp.getPosition().x+13 >= sp.getPosition().x) && bullet_sp.getPosition().y >= sp.getPosition().y && bullet_sp.getPosition().x+13 <= sp.getPosition().x+(173*sp.getScale().x) && bullet_sp.getPosition().y+57 <= sp.getPosition().y+(132*sp.getScale().y)){
                score+=20;
                return true;
            }
        }
        else if(name == "gamma"){
            if((bullet_sp.getPosition().x >= sp.getPosition().x||bullet_sp.getPosition().x+13 >= sp.getPosition().x) && bullet_sp.getPosition().y >= sp.getPosition().y && bullet_sp.getPosition().x+13 <= sp.getPosition().x+(120*sp.getScale().y) && bullet_sp.getPosition().y+57 <= sp.getPosition().y+(154*sp.getScale().y)){
                score+=30;
                return true;
            }
        }
        else{
            return false;
        }
        return false;
    }

};