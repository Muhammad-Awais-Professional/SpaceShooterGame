#include <SFML/Graphics.hpp>
#include <string.h>
#include "bullets.h"
#include "addons.h"
using namespace sf;
class Player
{

protected:

public:
	Texture tex;
	Texture UpLeft, UpRight;
	Texture UpLeft_flash_tex, UpRight_flash_tex;
	Sprite UpLeft_flash_sp, UpRight_flash_sp;
	Sprite flash_sp;
	Texture flash_tex;
	bool flash;
	Sprite sprite;
	float speed;
	int x, y;
	Bullets* b;
	int lives;
	Texture* Explosion_tex;
	Sprite* Explosion_sprite;
	bool explosion;
	int exp_ind;
	Addons* powerups;

	Player(std::string png_path, Bullets* bs, Addons* powerups)
	{
		flash = false;
		UpLeft_flash_tex.loadFromFile("img/UpLeft_flash.png");
		UpRight_flash_tex.loadFromFile("img/UpRight_flash.png");
		flash_tex.loadFromFile("img/player_ship_flash.png");
		flash_sp.setTexture(flash_tex);
		UpLeft_flash_sp.setTexture(UpLeft_flash_tex);
		UpRight_flash_sp.setTexture(UpRight_flash_tex);
		explosion = false;
		speed = 5;
		lives = 3;
		UpLeft.loadFromFile("img/UpLeft.png");
		UpRight.loadFromFile("img/UpRight.png");

		exp_ind = 0;

		this->powerups = powerups;

		Explosion_tex = new Texture[4];

		Explosion_sprite = new Sprite[4];

		Explosion_tex[0].loadFromFile("img/explosion/explosion0.png");
		Explosion_tex[1].loadFromFile("img/explosion/explosion1.png");
		Explosion_tex[2].loadFromFile("img/explosion/explosion2.png");
		Explosion_tex[3].loadFromFile("img/explosion/explosion3.png");

		Explosion_sprite[0].setTexture(Explosion_tex[0]);
		Explosion_sprite[1].setTexture(Explosion_tex[1]);
		Explosion_sprite[2].setTexture(Explosion_tex[2]);
		Explosion_sprite[3].setTexture(Explosion_tex[3]);

		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		x = 340;
		y = 780;
		//y = 550;
		sprite.setPosition(x, y);
		sprite.setScale(0.75, 0.75);
		b = bs;
        b[0].bullet_sp.setPosition(sprite.getPosition().x + 32, sprite.getPosition().y - 30);
	}
	void fire(int i){

		if((b[i].bullet_sp.getTexture() == b[i].UpRightBullet.getTexture()) || (b[i].bullet_sp.getTexture()==b[i].UpRight_fire_sp.getTexture())){
	        b[i].bullet_sp.move(-2*5,-2*5);
		}
		else if((b[i].bullet_sp.getTexture() == b[i].UpLeftBullet.getTexture()) || (b[i].bullet_sp.getTexture()==b[i].UpLeft_fire_sp.getTexture())){
	        b[i].bullet_sp.move(+2*5,-2*5);
		}else{
	        b[i].bullet_sp.move(0,-2*5);
		}

	}
	
	void move(std::string s)
	{
		
		float delta_x = 0, delta_y = 0;
		if(s=="l")
			delta_x=-1;
		else if(s=="r")
			delta_x=1;
		if (s == "u")
			delta_y = -1;
		else if (s == "d")
			delta_y = 1;

		delta_x *= speed;
		delta_y *= speed;

		sprite.move(delta_x, delta_y);
	}

    bool PlayerCollideWithEnemy(String name, Sprite sp){
		
		float playerWidth = 103;
		float playerHeight = 107;
		float enemyWidth = 110 * sp.getScale().x;
		float enemyHeight = 106 * sp.getScale().y;

        if(name == "alpha"){

			enemyWidth = 110 * sp.getScale().x;
			enemyHeight = 106 * sp.getScale().y;

        }
        else if(name == "beta"){
            enemyWidth = 153 * sp.getScale().x;
			enemyHeight = 132 * sp.getScale().y;
        }
        else if(name == "gamma"){
            enemyWidth = 110 * sp.getScale().x;
			enemyHeight = 154 * sp.getScale().y;
        }
        else if(name == "monster"){
			enemyWidth = 1331 * sp.getScale().x;
			enemyHeight = 1463 * sp.getScale().y;
        }
		else if(name == "laser"){
			enemyWidth = 130;
			enemyHeight = 250 * 1.87;
		}
		else if(name == "dragon"){
			enemyWidth = 239*sp.getScale().x;
			enemyHeight = 236*sp.getScale().y;
		}

        if ((sprite.getPosition().x + playerWidth-40 >= sp.getPosition().x &&
				sprite.getPosition().x <= sp.getPosition().x + enemyWidth &&
				sprite.getPosition().y + playerHeight >= sp.getPosition().y &&
				sprite.getPosition().y <= sp.getPosition().y + enemyHeight-10))
		{
			return true;
		}
		
        return false;

    }

	// bool PlayerCollidesWithLaser(int i, Sprite player, Sprite *beam) {
	// 	i=5;
	// 	float playerCenterX = player.getPosition().x + (player.getGlobalBounds().width / 2);
	// 	float playerCenterY = player.getPosition().y + (player.getGlobalBounds().height / 2);

	// 	float beamWidth = beam[i].getGlobalBounds().width;
	// 	float beamHeight = beam[i].getGlobalBounds().height;
	// 	float beamLeft = beam[i].getPosition().x - (beamWidth / 2);
	// 	float beamTop = beam[i].getPosition().y - (beamHeight / 2);

	// 	// Approximate the laser as a triangle
	// 	float beamTopCenterX = beam[i].getPosition().x;
	// 	float beamTopCenterY = beamTop;
	// 	float beamBottomLeftX = beamLeft;
	// 	float beamBottomLeftY = beamTop + beamHeight;
	// 	float beamBottomRightX = beamLeft + beamWidth;
	// 	float beamBottomRightY = beamTop + beamHeight;

	// 	// Check if player's center is within the approximated laser triangle
	// 	bool b1 = (playerCenterX - beamBottomRightX) * (beamTopCenterY - beamBottomRightY) - 
	// 			(beamTopCenterX - beamBottomRightX) * (playerCenterY - beamBottomRightY) < 0.0f;
	// 	bool b2 = (playerCenterX - beamBottomLeftX) * (beamBottomRightY - beamBottomLeftY) - 
	// 			(beamBottomRightX - beamBottomLeftX) * (playerCenterY - beamBottomLeftY) < 0.0f;
	// 	bool b3 = (playerCenterX - beamTopCenterX) * (beamBottomLeftY - beamTopCenterY) - 
	// 			(beamBottomLeftX - beamTopCenterX) * (playerCenterY - beamTopCenterY) < 0.0f;

	// 	return ((b1 == b2) && (b2 == b3));
	// }

};
