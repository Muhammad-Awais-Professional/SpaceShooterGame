#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <iostream>
#include "player.h"
#include "menu.h"
#include "enemies.h"
#include "Invaders.h"
#include <ctime>
#include <cmath>
#include <cstdlib>
#include "addons.h"
#include "monster.h"
#include "dragon.h"
#define height 780
#define width 780
const char title[] = "OOP-Project, Spring-2023";
using namespace sf;
using namespace std;


class Shooting_random{

public:

    int index;

    String name;

    float x;

    float y;

    Shooting_random(){

        int index=0;

        name ="";

        float x=0;

        float y=0;

    }

};

class Explosion{

public:

	Texture* Explosion_tex;

    Sprite* Explosion_sprite;

    bool explosion_flag;

    int exp_ind;

    Explosion(){

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
        
    }

};

class Game
{
public:
    //bool movebullets;
    Sprite background;     // Game background sprite
    Sprite background_too; // to move background
    Sprite Stars;
    Sprite Stars_too;
    Texture star_tex;
    Texture bg_texture;
    Player *p; // player
    Bullets *b;
    Enemies **en;
    Menu m;
    bool escape;
    Sprite escape_menu;
    int i ;
    Texture escape_menu_tex;
    RectangleShape rect;
    int count;
    Texture lives_hud_tex;
    Sprite lives_hud_sprite;
    Sprite life1,life2,life3;
    float current_time, timer;
    int numen;
    Bombs* bombs;
    // int random_shoot;
    Explosion explosion;
    bool rect_cleared, cross_cleared, triangle_cleared;
    bool position_set, transition_done;
    bool stage_one_flag;
    bool all_des;
    Addons** powerups;
    int random_powerup;
    Font lives_font;
    Text lives_text;
    String lives_string;
    bool life2_moves_up;
    bool life3_moves_up;
    float flash_time;
    float fire_bool_time;
    Shooting_random* random_shoot;
    int total_shoot;
    Enemies** boss;
    bool triangle_skipped, cross_skipped;
    bool Stage_one_completed;
    int Score;
    Text score_text;
    int random_boss;

    Texture meteors_tex;
    Sprite meteor_sp;
    bool meteor_flag;

    bool stage_two_initialized_flag;
    bool circle_cleared, diamond_cleared, heart_cleared;
    bool stage_two_flag;
    bool diamond_skipped, heart_skipped;
    bool Stage_two_completed;
    bool diamond_called;
    int transitionStep;

    bool stage_three_initialized_flag;
    bool filledcircle_cleared, filledrect_cleared, filledtriangle_cleared;
    bool stage_three_flag;
    bool filledcircle_skipped, filledrect_skipped, filledtriangle_skipped;
    bool Stage_three_completed;
    bool filledtriangle_called;

    bool meteor_transition_flag;
    bool draw_meteor;
    bool game_completed;

    Texture game_done_tex;
    Sprite game_done_sp;

    Music music;

    // add other game attributes

    Game()
    {
        if(!music.openFromFile("Sound/ES_Sosso - Magnus Ludvigsson.wav"))
            cout<<"Error Opening ES_Sosso - Magnus Ludvigsson.wav"<<endl;

        music.play();
        
        game_done_tex.loadFromFile("img/Endscreen.png");
        game_done_sp.setTexture(game_done_tex);
        filledrect_cleared = false;
        filledcircle_cleared = false;
        filledtriangle_cleared = false;
        filledcircle_skipped = false;
        filledtriangle_skipped = false;
        filledrect_skipped = false;
        draw_meteor = false;
        meteor_sp.setScale(1.5,1.5);
        meteor_transition_flag = false;
        transitionStep = 0;
        stage_three_initialized_flag = false;
        Stage_three_completed = false;
        game_completed = false;
        filledtriangle_called = false;
        diamond_called = false;
        stage_two_initialized_flag = false;
        Stage_two_completed = false;
        diamond_skipped = false;
        heart_skipped = false;
        stage_two_flag = true;
        meteor_flag = true;
        meteors_tex.loadFromFile("img/meteortransition.png");
        meteor_sp.setTexture(meteors_tex);
        circle_cleared = false;
        diamond_cleared = false;
        heart_cleared = false;
        score_text.setFont(lives_font);
        Score = 0;
        random_boss = 0;
        Stage_one_completed = false;
        cross_skipped = false;
        triangle_skipped = false;
        boss = new Enemies*[2];
        boss[0] = new Monster;
        boss[1] = new Dragon;
        //dragon_bool = false;
        random_shoot = NULL;
        total_shoot = 0;
        bombs = NULL;
        flash_time = 0;
        fire_bool_time = 0;
        life2_moves_up = false;
        life3_moves_up = false;
        lives_font.loadFromFile("Fonts/decent.otf");
        lives_text.setFont(lives_font);
        lives_text.setFillColor(Color::Yellow);
        lives_text.setStyle(Text::Bold);
        lives_text.setOutlineThickness(2.0);
        lives_text.setOutlineColor(Color::Black);
        random_powerup = rand()%(4);
        powerups = new Addons*[3];
        powerups[0] = new Danger;
        powerups[1] = new Life;
        powerups[2] = new Fire;
        powerups[3] = new Powerup;
        all_des = false;
        stage_one_flag = false;
        position_set = false;
        transition_done = true;
        rect_cleared = false;
        cross_cleared = false;
        triangle_cleared = false;
        en = NULL;
        // random_shoot = 0;
        numen = 3;
        timer = 0;
        current_time = 0;
        lives_hud_tex.loadFromFile("img/liveshud.png");
        lives_hud_sprite.setTexture(lives_hud_tex);
        count = 0;
        escape = false;
        //movebullets = false;
        background_too.setPosition(0, -height * 2);
        // en = new Enemies*[3];
        // en[0] = new Alpha(bomba);
        // en[1] = new Beta(bombb);
        // en[2] = new Gamma(bombg);
        b = new Bullets[7];
        p = new Player("img/player_ship.png", &b[0], powerups[0]);
        bg_texture.loadFromFile("img/backgrounds.png");
        star_tex.loadFromFile("img/stars.png");
        escape_menu_tex.loadFromFile("img/Menu/Escape.png");
        escape_menu.setTexture(escape_menu_tex);
        Stars.setTexture(star_tex);
        Stars_too.setTexture(star_tex);
        Stars_too.setPosition(0, -height);
        Stars.setPosition(0, -height);
        rect.setSize(Vector2f(780.f, 780.f));   //Used just for the fading effect while escaoe is pressed.
        rect.setFillColor(Color(0, 0, 0, 150));
        background.setTexture(bg_texture);
        background_too.setTexture(bg_texture);
        i = 0;
        // background.setScale(1.5, 1.5);
        // background_too.setScale(1.5, 1.5);
        m.display_menu();
        
        life1 = p->sprite;
        life2 = p->sprite;
        life3 = p->sprite;

        life1.setScale(0.5, 0.5);
        life2.setScale(0.5, 0.5);
        life3.setScale(0.5, 0.5);

        life1.setPosition(11,625);
        life2.setPosition(82,625);
        life3.setPosition(151,625);
        lives_text.setPosition(231,635);
    }

    void moveStars()
    {

        if (Stars.getPosition().y == 0)
            Stars_too.setPosition(0, -height);

        Stars.move(5, 5);

        if (Stars_too.getPosition().y == 0)
            Stars.setPosition(0, -height);

        Stars_too.move(5, 5);
    }

    void moveBackground()
    {

        if (background.getPosition().y == 2)
            background_too.setPosition(0, -height - height + 6);

        background.move(0, 2);

        if (background_too.getPosition().y == 2)
            background.setPosition(0, -height - height + 8);

        background_too.move(0, 2);
    }

    void wrapAroundSpace()
    {

        if (p->sprite.getPosition().x > width)
        {

            p->sprite.setPosition(0, p->sprite.getPosition().y);
        }

        else if (p->sprite.getPosition().x < 0)
        {

            p->sprite.setPosition(width, p->sprite.getPosition().y);
        }

        if (p->sprite.getPosition().y > height)
        {

            p->sprite.setPosition(p->sprite.getPosition().x, 0);
        }

        else if (p->sprite.getPosition().y < 0)
        {

            p->sprite.setPosition(p->sprite.getPosition().x, height);
        }
    }

    void start_game()
    {

        // random_shoot = rand()%(numen);
        // cout<<"Cp0"<<endl;
        // stage_one_flag = true;

        if(!Stage_one_completed){
            random_boss = rand()%2;
            // random_boss = 1;
            Stage_one();
        }
        else{
            en = new Enemies*[1];
            Bombs* abomb = new Bombs;
            en[0] = new Alpha(abomb);
            en[0]->destroyed = true;
            numen = 0;
        }

        float mute_delay = 0;

        // boss[1]->monster_bool = true;
        if (m.getGameStarted())
        {
            RenderWindow window(VideoMode(height, width), title, Style::Titlebar | Style::Close);
            Clock clock;
            window.setMouseCursorVisible(true);
            // RenderWindow w(VideoMode(0, 0), "Space Bubble - Dobule Trouble");
            // m.cursor.loadFromPixels(m.cursor_tex.copyToImage().getPixelsPtr(), m.cursor_tex.getSize(), w.getSize());
            
            // cout<<"Cp0.5"<<endl;
            
            while (window.isOpen()) //main game loop
            {

                // cout<<"Cp1"<<endl;

                if(Keyboard::isKeyPressed(Keyboard::M) && music.getVolume()==100 && timer >= mute_delay+2){
                    music.setVolume(0);
                    mute_delay = timer;
                }

                if(Keyboard::isKeyPressed(Keyboard::M) && music.getVolume()==0){
                    music.setVolume(100);
                }

                if(numen!=0)
                {
                    if(!powerups[random_powerup]->getConsumed())
                        random_powerup = rand()%(4);
                    int random = rand()%numen;
                    //random_powerup=3;
                    if(en[random]==NULL){
                        //cout<<"en[random] does not exisit"<<endl;
                        for(int i=0;i<numen;i++){
                            if(en[i]){
                                random = i;
                            }
                        }
                    }else{
                        //cout<<"en[random] does exisit"<<endl;
                    }

                    if(en[random]->destroyed && !powerups[random_powerup]->getConsumed()){
                        powerups[random_powerup]->addons_sp.setPosition(en[random]->enemy_sp.getPosition());
                        powerups[random_powerup]->setConsumed(true);
                    }
                }
                // cout<<"Mouse position :- "<<Mouse::getPosition(window).x<<" , "<<Mouse::getPosition(window).y<<endl;
                //cout << "Rebalancing" << endl;
                //cout << "cp6" << endl;
                // cout<<"Cp2"<<endl;

                //cout << "Rebalancing1" << endl;

                // cout<<"Cp3"<<endl;
                
                if(powerups[random_powerup]->collide(p->sprite) && powerups[random_powerup]->getname()=="fire"){
                    if(!p->flash){
                        p->b->Fire_bool = true;
                    }
                    else{
                        for(int i=0;i<7;i++){
                            p->b[i].Fire_bool = true;
                        }
                    }
                    fire_bool_time = timer;
                    powerups[random_powerup]->setConsumed(false);
                }
                // cout<<"Cp4"<<endl;

                if(timer>=fire_bool_time+5){
                    if(!p->flash){
                        p->b->Fire_bool = false;
                    }
                    else{
                        for(int i=0;i<7;i++){
                            p->b[i].Fire_bool = false;
                        }
                    }
                }
                // cout<<"Cp5"<<endl;

                // if(p->b->Fire_bool == true){
                //     cout<<"Fire bool true"<<endl;
                // }else{
                //     cout<<"Fire bool false"<<endl;
                // }
                if(!Stage_one_completed)
                {
                    rebalancing();    

                    callStageone();   
                }
                else if(!stage_two_initialized_flag){
                    rebalancing();
                    // cout<<"Stage one completed!"<<endl;
                }

                if(Stage_one_completed && !Stage_two_completed && !stage_two_initialized_flag){
                    
                    random_boss = rand()%2;

                    boss[0]->monster_done = false;

                    boss[1]->monster_done = false;

                    stage_two_flag = true;

                    transition_done = false;
                    Stage_two();
                    stage_two_initialized_flag = true;
                }

                if(!Stage_two_completed && Stage_one_completed){
                    if(!transition_done && !boss[random_boss]->monster_bool){
                        meteor_transition();
                    }
                    callStagetwo();
                    rebalancing();
                }
                else if(!stage_three_initialized_flag){
                    rebalancing();
                    // cout<<"Stage two is done! "<<endl;
                }

                if(Stage_one_completed && Stage_two_completed && !Stage_three_completed && !stage_three_initialized_flag){
                    
                    // cout<<"IN if cond iii"<<endl;

                    random_boss = rand()%2;

                    boss[0]->monster_done = false;

                    boss[1]->monster_done = false;

                    stage_three_flag = true;

                    transition_done = false;
                    Stage_three();
                    stage_three_initialized_flag = true;
                }

                if(!Stage_three_completed && Stage_one_completed && Stage_two_completed){
                    if(!transition_done && !boss[random_boss]->monster_bool){
                        meteor_transition();
                    }
                    callStagethree();
                    rebalancing();
                }
                else {
                    rebalancing();
                    // cout<<"Stage three is done! "<<endl;
                }

                //cout << "Rebalancing2" << endl;

                if(Stage_one_completed && Stage_two_completed && Stage_three_completed){

                    p->move("u");

                    if(p->sprite.getPosition().y<=-100){
                        game_completed = true;
                    }

                }

                //cout << "Rebalancing3 << " << random_shoot << endl;
                //rebalancing();    

                // if(en[random_shoot]!=NULL && en[random_shoot]->getbomb()->bomb_sp.getPosition().y>750){
                //     //cout << "--------------\n";
                //     random_shoot = rand()%numen;

                //     if(en[random_shoot]->name == "alpha")    
                //             en[random_shoot]->getbomb()->bomb_sp.setPosition(en[random_shoot]->enemy_sp.getPosition().x+43,en[random_shoot]->enemy_sp.getPosition().y);
                //     else if(en[random_shoot]->name == "beta")
                //             en[random_shoot]->getbomb()->bomb_sp.setPosition(en[random_shoot]->enemy_sp.getPosition().x+56,en[random_shoot]->enemy_sp.getPosition().y+20);
                //     else if(en[random_shoot]->name == "gamma")
                //             en[random_shoot]->getbomb()->bomb_sp.setPosition(en[random_shoot]->enemy_sp.getPosition().x+36,en[random_shoot]->enemy_sp.getPosition().y+27);
                // }

                // if(en[random_shoot]==NULL){
                //     for(int m=0;m<numen;m++){
                //         if(en[m]!=NULL && !en[m]->destroyed){
                //             random_shoot = m;
                //         }
                //     }
                // }

                //cout << "NM EN: " << numen << endl;
                //cout << "Rebalancing3.5 << " << random_shoot << endl;

                int mouseposwindow_x = Mouse::getPosition(window).x;

                int mouseposwindow_y = Mouse::getPosition(window).y;

                if (Keyboard::isKeyPressed(Keyboard::Escape) && !escape)
                {
                    escape = true;
                    window.setMouseCursorVisible(true);
                }
                //cout << "Rebalancing4" << endl;
                // cout<<"Cp8"<<endl;

                if (Mouse::isButtonPressed(Mouse::Left))
                    if (mouseposwindow_x > 235 && mouseposwindow_x < 547 && mouseposwindow_y > 297 && mouseposwindow_y < 392)
                    {
                        escape = false;
                        window.setMouseCursorVisible(false);
                    }

                if (Mouse::isButtonPressed(Mouse::Left))
                    if (mouseposwindow_x > 235 && mouseposwindow_x < 547 && mouseposwindow_y > 422 && mouseposwindow_y < 515)
                    {
                        window.close();
                        //m.display_menu();
                    }
                // cout<<"Cp9"<<endl;

                float time = clock.getElapsedTime().asSeconds();
                clock.restart();
                if(!escape)    
                    timer += time;
                //cout<<timer<<endl;
                Event e;
                while (window.pollEvent(e))
                {
                    if (e.type == Event::Closed)
                    {                   // If cross/close is clicked/pressed
                        m.setGameStarted(false);
                        window.close(); // close the game
                    }
                }
                // cout<<"Cp10"<<endl;

                if(powerups[random_powerup]->collide(p->sprite) && powerups[random_powerup]->getname()=="flash"){
                    p->flash = true;
                    flash_time = timer;
                    powerups[random_powerup]->setConsumed(false);
                }

                if(timer>=flash_time+5){
                    p->flash = false;
                }
                // cout<<"Cp11"<<endl;

                if (!escape)
                {
                    if (Keyboard::isKeyPressed(Keyboard::Left))  // If left key is pressed
                        p->move("l");                            // Player will move to left
                    if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
                        p->move("r");                            // player will move to right
                    if (Keyboard::isKeyPressed(Keyboard::Up))    // If up key is pressed
                        p->move("u");                            // playet will move upwards
                    if (Keyboard::isKeyPressed(Keyboard::Down))  // If down key is pressed
                        p->move("d");                            // player will move downwards

                    if (Keyboard::isKeyPressed(Keyboard::Left) && Keyboard::isKeyPressed(Keyboard::Up))
                    {
                        if(!p->flash){
                            p->sprite.setTexture(p->UpLeft);
                        }
                        else{
                            p->sprite.setTexture(p->UpLeft_flash_tex);
                        }

                        if(!p->flash){
                            if (!p->b->movebullets){
                                if(!p->b->Fire_bool){
                                    p->b->bullet_sp = p->b->UpLeftBullet;
                                }
                                else{
                                    p->b->bullet_sp = p->b->UpLeft_fire_sp;
                                }
                            }
                        }else{
                            for(int i=0;i<7;i++){
                                if (!p->b[i].movebullets){
                                    if(!p->b[i].Fire_bool){
                                        p->b[i].bullet_sp = p->b[i].UpLeftBullet;
                                    }
                                    else{
                                        p->b[i].bullet_sp = p->b[i].UpLeft_fire_sp;
                                    }
                                }
                            }
                        }
                        p->sprite.setScale(1, 1);
                        if(!p->flash){
                            p->b->bullet_sp.setScale(1.5, 1.5);
                        }
                        else{
                            for(int i=0;i<7;i++){
                                p->b[i].bullet_sp.setScale(1.5, 1.5);
                            }
                        }
                    }
                    else if (Keyboard::isKeyPressed(Keyboard::Right) && Keyboard::isKeyPressed(Keyboard::Up))
                    {
                        if(!p->flash){
                            p->sprite.setTexture(p->UpRight);
                        }
                        else{
                            p->sprite.setTexture(p->UpRight_flash_tex);
                        }
                        if(!p->flash){
                            if (!p->b->movebullets){
                                if(!p->b->Fire_bool){
                                    p->b->bullet_sp = p->b->UpRightBullet;
                                }else{
                                    p->b->bullet_sp = p->b->UpRight_fire_sp;
                                }
                            }
                        }else{
                            for(int i=0;i<7;i++){
                                if (!p->b[i].movebullets){
                                    if(!p->b[i].Fire_bool){
                                        p->b[i].bullet_sp = p->b[i].UpRightBullet;
                                    }
                                    else{
                                        p->b[i].bullet_sp = p->b[i].UpRight_fire_sp;
                                    }
                                }
                            }
                        }
                        if(!p->flash){
                            p->b->bullet_sp.setScale(1.5, 1.5);
                        }
                        else{
                            for(int i=0;i<7;i++){
                                p->b[i].bullet_sp.setScale(1.5, 1.5);
                            }
                        }
                        p->sprite.setScale(1, 1);
                    }
                    else
                    {
                        p->sprite.setScale(0.75, 0.75);
                        if(!p->flash){
                            p->sprite.setTexture(p->tex);
                        }
                        else{
                            p->sprite.setTexture(p->flash_tex);
                        }

                        if(!p->flash){
                            if (!p->b->movebullets)
                            {   
                                if(!p->b->Fire_bool){
                                    p->b->bullet_sp = p->b->UpStraightBullet;
                                }
                                else{
                                    p->b->bullet_sp = p->b->Straight_fire_sp;
                                }
                                p->b->bullet_sp.setScale(1.5, 1.5);
                            }
                        }else{
                            for(int i=0;i<7;i++){
                                if (!p->b[i].movebullets)
                                {   
                                    if(!p->b[i].Fire_bool){
                                        p->b[i].bullet_sp = p->b[i].UpStraightBullet;
                                    }
                                    else{
                                        p->b[i].bullet_sp = p->b[i].Straight_fire_sp;
                                    }
                                    p->b[i].bullet_sp.setScale(1.5, 1.5);
                                }
                            }
                        }
                    }
                }
                // cout<<"Cp12"<<endl;


                // if(en[random_shoot]->destroyed || random_shoot>=numen){

                //     for(int l=0;l<numen;l++){
                //         if(!en[l]->destroyed )
                //         {
                //             random_shoot = l;
                //             break;
                //         }
                //     }

                // }

                ////////////////////////////////////////////////
                /////  Call your functions here            ////
                //////////////////////////////////////////////

                if(life2_moves_up && !escape){
                    if(life2.getPosition().y>=625 &&!escape){
                        life2.move(0,-3);
                        if(p->lives==1){
                            life2_moves_up = false;
                        }    
                    }
                    else{
                        life2_moves_up = false;
                    }
                }
                else if(life3_moves_up && !escape){
                    if(life3.getPosition().y>=625 &&!escape){
                        life3.move(0,-3);    
                        if(p->lives == 2 || p->lives==1){
                            life3_moves_up = false;
                        }
                    }
                    else{
                        life3_moves_up = false;
                    }
                }
                // cout<<"Cp13"<<endl;

                if(powerups[random_powerup]->collide(p->sprite) && powerups[random_powerup]->getname()=="life" && powerups[random_powerup]->getConsumed()){
                    powerups[random_powerup]->setConsumed(false);
                    int y=p->lives;
                    p->lives++;
                    int z = p->lives;

                    if((y==1 && z==2) ){
                        life2_moves_up = true;
                    }
                    else if((y==2 && z==3)){
                        life3_moves_up = true;
                    }
                    if(p->lives>3){
                        int x = (p->lives-3);
                        lives_string ="+" + to_string(x);
                        lives_text.setString(lives_string);
                    }
                }
                // cout<<"Cp14"<<endl;

                wrapAroundSpace();
                window.clear(Color::Black); // clears the screen
                window.draw(background);    // setting background
                window.draw(background_too);
                if (!escape)
                    moveBackground();
                window.draw(Stars);
                if (!escape)
                    moveStars();
                window.draw(Stars_too);
                // window.draw(background_too);
                // cout<<"Cp15"<<endl;

                if (Keyboard::isKeyPressed(Keyboard::Space) && !p->b->movebullets && !escape)
                {
                    if(!p->flash){
                        p->b->movebullets = true;
                    }
                    else{
                        for(int i=0;i<7;i++){
                            p->b[i].movebullets = true;
                        }
                    }
                    
                    if(!p->flash)    
                        p->b[0].bullet_sp.setPosition(p->sprite.getPosition().x + 32, p->sprite.getPosition().y - 30);
                    else{
                        for(int i=0;i<7;i++){
                            p->b[i].bullet_sp.setPosition(p->sprite.getPosition().x - 118+(i*50), p->sprite.getPosition().y - 30);
                        }
                    }
                }
                // cout<<"Cp16"<<endl;

                if(!p->flash){ 
                    if (p->b->movebullets)
                    {
                        if (p->b[0].bullet_sp.getPosition().y > 0)
                        {
                            if(!escape)
                                p->fire(0);
                            window.draw(p->b[0].bullet_sp);

                            // if(p->b[0].bullets.getPosition().y>p->sprite.getPosition().y+15){
                            //     p->fire(1);
                            //     window.draw(p->b[1].bullets);
                            // }
                        }
                        else{
                            p->b->movebullets = false;
                        }
                    
                    }
                }
                else{
                    for(int i=0;i<7;i++){
                        if (p->b[i].movebullets){

                            if (p->b[i].bullet_sp.getPosition().y > 0)
                            {
                                p->fire(i);
                                window.draw(p->b[i].bullet_sp);

                                // if(p->b[0].bullets.getPosition().y>p->sprite.getPosition().y+15){
                                //     p->fire(1);
                                //     window.draw(p->b[1].bullets);
                                // }
                            }
                            else{
                                p->b[i].movebullets = false;
                            }
                        }
                    }
                }
                if (p->sprite.getPosition().y >= 550 && timer<3+current_time &&!escape)
                {
                    if(p->lives<3)    
                        p->speed = 3;
                    p->move("u");
                }
                else{
                    p->speed = 5;
                }

                playerHit();

                if(p->explosion && p->sprite.getPosition().y>=606 &&!escape){
                    
                    if(p->exp_ind<4)
                        window.draw(p->Explosion_sprite[p->exp_ind++]);
                }
                else{
                    p->explosion = false;
                    p->exp_ind = 0;
                }
                // cout<<"Cp17"<<endl;


                //cout << "Check hit" << endl;
                for(int j=0;j<numen;j++){
                    if(!p->flash){
                        if(p->b->KillEnemy(en[j]->name,en[j]->enemy_sp, Score) || en[j]->destroyed){
                        
                            //en[j]->setExplosionPos(en[i]->enemy_sp.getPosition().x, en[i]->enemy_sp.getPosition().y );
                            // cout<<"En pos "<<en->enemy_sp.getPosition().x <<" , "<<en->enemy_sp.getPosition().y<<endl;
                            // cout<<"Exp  "<<en->xExplosion_sprite[i].getPosition().x <<" , "<<en->Explosion_sprite[i].getPosition().y<<endl;
                    
                        
                            //cout<<"enemy hit!!!"<<endl;
                            en[j]->destroyed = true;

                            if((p->b->KillEnemy(en[j]->name,en[j]->enemy_sp, Score)) && !p->b->Fire_bool){    
                                p->b[0].bullet_sp.setPosition(p->sprite.getPosition().x + 32, p->sprite.getPosition().y - 30);
                                p->b->movebullets = false;
                            }
                            
                        }
                    }else{
                        for(int i=0;i<7;i++){
                            if(p->b[i].KillEnemy(en[j]->name,en[j]->enemy_sp, Score) || en[j]->destroyed){
                            
                                //en[j]->setExplosionPos(en[i]->enemy_sp.getPosition().x, en[i]->enemy_sp.getPosition().y );
                                // cout<<"En pos "<<en->enemy_sp.getPosition().x <<" , "<<en->enemy_sp.getPosition().y<<endl;
                                // cout<<"Exp  "<<en->xExplosion_sprite[i].getPosition().x <<" , "<<en->Explosion_sprite[i].getPosition().y<<endl;
                        
                            
                                //cout<<"enemy hit!!!"<<endl;
                                en[j]->destroyed = true;

                                if((p->b[i].KillEnemy(en[j]->name,en[j]->enemy_sp, Score)) && !p->b[i].Fire_bool){    
                                    p->b[i].bullet_sp.setPosition(p->sprite.getPosition().x + 32, p->sprite.getPosition().y - 30);
                                    p->b[i].movebullets = false;
                                }
                            }
                        }
                    }
                }
                //cout << "Checked hit" << endl; 
                // cout<<"Cp18"<<endl;

                if(explosion.explosion_flag && explosion.exp_ind<4){
                    if(explosion.exp_ind>=4){
                        explosion.exp_ind = 0;
                    }

                    window.draw(explosion.Explosion_sprite[explosion.exp_ind++]);
                }

                // if(en[random_shoot]->getbomb()->bomb_sp.getPosition().y<780 && !(p->lives<1))
                //     if(!en[random_shoot]->destroyed)
                //         window.draw(en[random_shoot]->getbomb()->bomb_sp);

                //cout << "Check hit2" << endl;

                //testing
                //en->getbomb()->bomb_sp.setPosition(0,0);
                //window.draw(en->getbomb()->bomb_sp);
                //testing
                // cout<<"Cp18.1"<<endl;

                // if (!escape && (en[random_shoot]->getbomb()->bomb_sp.getPosition().y<780 ) && !(p->lives<1))
                //     if(!en[random_shoot]->destroyed)
                //         en[random_shoot]->firebomb();

                window.draw(lives_hud_sprite);

                window.draw(life1);

                window.draw(life2);

                window.draw(life3);

                // cout<<"Cp18.2"<<endl;
                
                if(p->lives == 6){
                    lives_string="+3";
                    lives_text.setString(lives_string);
                }
               
                // cout<<"Cp18.3"<<endl;

                if(p->lives>3){
                    window.draw(lives_text);
                }

                
                // cout<<"Cp18.4"<<endl;
                
                if(!escape && !meteor_transition_flag)
                    shootbombs();

                // cout<<"Cp18.5"<<endl;

                for(int i=0;i<total_shoot;i++)
                    if(numen>0 && !meteor_transition_flag)    
                        window.draw(bombs[random_shoot[i].index].bomb_sp);
                
                // cout<<"Cp18.6"<<endl;

                window.draw(p->sprite); // setting player on screen

                /*if(!en[i]->destroyed)*/
                for(int j=0;j<numen;j++){
                    if(!en[j]->destroyed && !meteor_transition_flag)    
                        window.draw(en[j]->enemy_sp);


                    if(!escape && transition_done)
                        en[j]->moveEnemy();
                }
                // cout<<"Cp19"<<endl;

                if(powerups[random_powerup]->getConsumed() ){
                    window.draw(powerups[random_powerup]->getSprite());
                    if(!escape)    
                        powerups[random_powerup]->move();
                }
                
                if(!powerups[random_powerup]->getConsumed()){
                    powerups[random_powerup]->addons_sp.setPosition(-1000,-1000);
                }

                if(!boss[0]->monster_done){

                    if(timer >=boss[0]->monster_timer+12){
                        boss[0]->monster_right = true;
                    }

                    if(boss[0]->monster_right && boss[0]->monster_bool){
                        monsterTransitionRight(boss,boss[0]->monster_right);
                    }

                    if(boss[0]->monster_bool && boss[0]->enemy_sp.getPosition().x>=780){
                        boss[0]->monster_bool = false;
                        boss[0]->monster_done = true;
                        Score+=40;
                        boss[0]->enemy_sp.setPosition(200,-1000);
                        stage_one_flag = true;
                    }

                    if(boss[0]->monster_bool){        //monster draw

                        callMonster();
                        
                        if(boss[0]->monster_uptodown_transition){
                            if(boss[0]->flag){   
                                boss[0]->monster_timer = timer;
                                boss[0]->flag = false;

                            }
                            if(!boss[0]->monster_right)
                                window.draw(boss[0]->beam_sp[boss[0]->beam_ind]);
                            //cout<<"Flag flag"<<endl;
                        }
                        window.draw(boss[0]->enemy_sp);
                    
                    }
                }
                
                // cout<<"Cp19.5"<<endl;

                // if(!boss[1]->monster_done)
                //     boss[1]->monster_bool = true;

                // cout<<"Cp19.6"<<endl;

                if(boss[1]->monster_bool ){      //dragon draw
                    if(!escape)   
                        calldragon();
                    window.draw(boss[1]->enemy_sp);

                    for(int i=0;i<boss[1]->beam_ind;i++){    
                        if(i>=0){
                            if(!escape)    
                                boss[1]->dragonfire(p->sprite,i);
                            
                        }
                        window.draw(boss[1]->beam_sp[i]);
                    }
                    if(boss[1]->monster_done){
                        boss[1]->monster_bool = false;
                    }
                }
                // cout<<"Cp19.7"<<endl;

                score_text.setString("Score: "+to_string(Score));

                window.draw(score_text);

                if(!transition_done && draw_meteor)
                    window.draw(meteor_sp);

                if (escape)
                {
                    window.draw(rect);
                    window.draw(escape_menu);
                }
                // cout<<"Cp20"<<endl;
                if(game_completed){
                    window.draw(game_done_sp);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        if(mouseposwindow_x > 90 && mouseposwindow_x<657 && mouseposwindow_y>494 && mouseposwindow_y< 625)
                        {
                            m.setGameStarted(false);
                            window.close();
                        }
                        else if(mouseposwindow_x >90 && mouseposwindow_x < 657 && mouseposwindow_y > 311 && mouseposwindow_y< 455 ){
                            m.setGameStarted(true);
                            window.close();
                        }
                    }
                }

                window.display(); // Displying all the sprites

                if(p->lives==0){
                    
                    m.setGameStarted(true);

                    game_completed = true;

                }
                if(i<numen)
                    i++;
                if(i==numen)
                    i=0;
                // cout<<"Cp21"<<endl;
                // for(int i=0;i<1000;i++)    
                    // cout<<" Mouse x "<<mouseposwindow_x<<" " <<" Mouse y "<<mouseposwindow_y<<endl;

            }
        }
    }

    void lives_transition(){

        if(p->lives<1){
            if(life1.getPosition().y<=780 &&!escape){
                life1.move(0,3);    
            }
        }

        if(p->lives<2){
            if(life2.getPosition().y<=780 &&!escape){
                life2.move(0,3);    
            }
        }

        if(p->lives<3){
            if(life3.getPosition().y<=780&&!escape){
                life3.move(0,3);    
            }
        }
        
    }
 
    void dragon_coming_transition(){
        float speed = 5;
        float targetY = 10;
        if(!boss[1]->flag){
            boss[1]->enemy_sp.setPosition(270,10);

            for(int i=0;i<boss[1]->total_beam;i++){
                boss[1]->beam_sp[i].setPosition(boss[1]->enemy_sp.getPosition().x+95,boss[1]->enemy_sp.getPosition().y+(240+(i*16)));
            }
            boss[1]->enemy_sp.setPosition(boss[1]->enemy_sp.getPosition().x, -300);

            boss[1]->flag = true;
        }

        if(boss[1]->enemy_sp.getPosition().y <= targetY){
            boss[1]->enemy_sp.move(0, speed); 
        }
        else{
            boss[1]->monster_uptodown_transition = true;
        }
    }

    void dragon_goesback(){
        float speed = -5;
        float targetY = -300;
        
        if(boss[1]->enemy_sp.getPosition().y >= targetY){
            boss[1]->enemy_sp.move(0, speed); 
        }
        else{
            boss[1]->monster_uptodown_transition = true;
        }
    }

    void calldragon(){
        if(!boss[1]->monster_uptodown_transition && !boss[1]->monster_done )
            dragon_coming_transition();
        else if(boss[1]->flag){
            boss[1]->monster_timer = timer; 
            boss[1]->flag = false;   
        }

        if(timer>=boss[1]->monster_timer+9){
            boss[1]->monster_right = true;
        }

        if(timer>=boss[1]->monster_timer+10){
            dragon_goesback();
            if(boss[1]->enemy_sp.getPosition().y<=-300){
                boss[1]->monster_done = true;
                Score+=50;
                boss[1]->monster_bool = false;
            }

        }
        if(boss[1]->monster_right)
            boss[1]->beam_ind--;
        if(boss[1]->monster_uptodown_transition){
            if(!boss[1]->monster_right)    
                boss[1]->beam_ind++;
                
            if(boss[1]->beam_ind>=boss[1]->total_beam){
                boss[1]->beam_ind = boss[1]->total_beam;
            }
            
        }
    }

    void playerHit(){
        
        bool poisoned = false;
        
        bool kill = false;

        if(boss[1]->monster_bool && !boss[1]->monster_right && boss[1]->monster_uptodown_transition){
            for(int i=0;i<boss[1]->total_beam;i++){
                if(p->PlayerCollideWithEnemy("dragon fire", boss[1]->beam_sp[i])){
                    kill = true;
                }
            }
        }

        if(kill*!p->flash || (powerups[random_powerup]->collide(p->sprite) && powerups[random_powerup]->getConsumed() && powerups[random_powerup]->name=="danger" &&!p->flash) || !p->flash * ( boss[0]->monster_bool && ( (p->PlayerCollideWithEnemy("monster",boss[0]->enemy_sp)&&!p->flash) || (p->PlayerCollideWithEnemy("laser",boss[0]->beam_sp[boss[0]->beam_ind]) ) )  ) || !p->flash * (p->PlayerCollideWithEnemy("dragon",boss[1]->enemy_sp)) ){
            powerups[random_powerup]->addons_sp.setPosition(1000,1000);
            
            int y = p->lives;
            p->lives--;
            int x=p->lives;

            if(y-x==1){

                int z = x-3;
                lives_string ="+" + to_string(z);
                lives_text.setString(lives_string);
            }

            poisoned = true;
            
            for(int i=0;i<4;i++){
                p->Explosion_sprite[i].setPosition(p->sprite.getPosition());
            }
            p->explosion = true;
            p->sprite.setPosition(p->x,p->y);
            current_time = timer;
        }

        for(int j=0;j<numen;j++)
        {
            if((/*en[j]->getbomb()->KillPlayer(p->sprite))*!en[j]->destroyed || */ (p->PlayerCollideWithEnemy(en[j]->name,en[j]->enemy_sp))*!en[j]->destroyed)){
                for(int i=0;i<4;i++)
                    p->Explosion_sprite[i].setPosition(p->sprite.getPosition());

                //cout<<"player hit!!!"<<endl;
                int y = p->lives;
                if(!p->flash)    
                    p->lives--;
                int x=p->lives;

                if(y-x==1){

                    int z = x-3;
                    lives_string ="+" + to_string(z);
                    lives_text.setString(lives_string);
                }

                if(p->PlayerCollideWithEnemy(en[j]->name,en[j]->enemy_sp) && !p->flash)
                    en[j]->destroyed = true;
                
                if(!p->flash)
                    p->sprite.setPosition(p->x, p->y);    
                count = 0;
                // if(en[j]->name == "alpha")    
                //     en[j]->getbomb()->bomb_sp.setPosition(en[j]->enemy_sp.getPosition().x+43,en[j]->enemy_sp.getPosition().y);
                // else if(en[j]->name == "beta")
                //     en[j]->getbomb()->bomb_sp.setPosition(en[j]->enemy_sp.getPosition().x+56,en[j]->enemy_sp.getPosition().y+20);
                // else if(en[j]->name == "gamma")
                //     en[j]->getbomb()->bomb_sp.setPosition(en[j]->enemy_sp.getPosition().x+36,en[j]->enemy_sp.getPosition().y+27);
                
                // if(en[j]->destroyed){
                //     en[j]->getbomb()->bomb_sp.setPosition(0,780+80);
                // }
                current_time = timer;
                if(!p->flash)    
                    p->explosion = true;
                // cout<<"Timer "<<timer<<endl<<"Ctm "<<current_time<<endl;
                // cout<<"Ctm +3 "<<ctm+3<<endl;
            }
        }        
        lives_transition();

    }

    void Stage_one(){
       
        // cout<<"S1 - Cp1"<<endl;

        if(en)
            for(int i=0;i<numen;i++){
                if(en[i])
                    delete en[i];
            }

        if(en)
            delete[] en;

        en=new Enemies*[14];    
       
        if(bombs){
            delete[] bombs;
        }

        // cout<<"S1 - Cp2"<<endl;

        numen = 14;
        
        total_shoot = 2;

        if(random_shoot){
            delete[] random_shoot;
        }

        random_shoot = new Shooting_random[total_shoot];

        for(int i=0;i<total_shoot;i++){
            random_shoot[i].index = 0;
        }

        bombs = new Bombs[numen];

        for(int j=0;j<numen;j++){

            int random_enemy = rand()%3;

            switch (random_enemy)
            {
            case 0:
                // cout<<"S1 - Cp2.1"<<endl;
                
                en[j]= new Alpha(&bombs[j]);
                break;
            case 1:
                // cout<<"S1 - Cp2.2"<<endl;

                en[j] = new Beta(&bombs[j]);

                // cout<<"S1 - Cp2.21"<<endl;
                break;
            case 2:
                // cout<<"S1 - Cp2.3"<<endl;

                en[j] = new Gamma(&bombs[j]);
                break;
            default:
                // cout<<"S1 - Cp2.4"<<endl;

                en[j]= new Alpha(&bombs[j]);
                break;
            }

        }
        // cout<<"S1 - Cp3"<<endl;

        if(!rect_cleared)
            Hollow_rectangle();
        else if(!triangle_cleared)
            triangle();
        else if(!cross_cleared)
            Cross();
        
        // cout<<"S1 - Cp4"<<endl;

        all_des = false;
    }

    void Stage_two(){
               
        // cout<<"S2 - Cp1"<<endl;

        if(en)
            for(int i=0;i<numen;i++){
                if(en[i])
                    delete en[i];
            }

        if(en)
            delete[] en;

        numen = 14;

        en=new Enemies*[numen];    
       
        if(bombs){
            delete[] bombs;
        }

        // cout<<"S2 - Cp2"<<endl;
        
        total_shoot = 4;

        if(random_shoot){
            delete[] random_shoot;
        }

        random_shoot = new Shooting_random[total_shoot];

        for(int i=0;i<total_shoot;i++){
            random_shoot[i].index = 0;
        }

        bombs = new Bombs[numen];

        for(int j=0;j<numen;j++){

            int random_enemy = rand()%3;

            switch (random_enemy)
            {
            case 0:
                // cout<<"S2 - Cp2.1"<<endl;
                
                en[j]= new Alpha(&bombs[j]);
                break;
            case 1:
                // cout<<"S2 - Cp2.2"<<endl;

                en[j] = new Beta(&bombs[j]);

                // cout<<"S2 - Cp2.21"<<endl;
                break;
            case 2:
                // cout<<"S2 - Cp2.3"<<endl;

                en[j] = new Gamma(&bombs[j]);
                break;
            default:
                // cout<<"S2 - Cp2.4"<<endl;

                en[j]= new Alpha(&bombs[j]);
                break;
            }

        }
        // cout<<"S2 - Cp3"<<endl;

        if(!circle_cleared)
            circle();
        else if(!diamond_cleared)
            diamond();
        else if(!heart_cleared)
            heart();
        
        // cout<<"S2 - Cp4"<<endl;

        all_des = false;
    }

    void circle(){

        // for(int i=0;i<numen;i++){
        //     en[i]->enemy_sp.setPosition(10*(i+1),10);
        // }
        float centerX = 330; 
        float centerY = 200; 
        float radius = 210;  
        float numEnemies = numen; 
        float angleStep = 2 * 3.14159 / numEnemies;

        for (int j = 0; j < numen; j++) {
            float angle = j * angleStep; 
            float x = centerX + radius * cos(angle); 
            float y = centerY + radius * sin(angle); 

            en[j]->enemy_sp.setPosition(x, y); 
        }
        // for(int i=0;i<numen;i++){
        //     en[i]->enemy_sp.setPosition(en[i]->enemy_sp.getPosition().x, en[i]->enemy_sp.getPosition().y-700);
        // }
    }

    void Hollow_Circle_Transition() {
        
        if(!transition_done){
            for(int i=0;i<numen;i++){
                en[i]->enemy_sp.move(0,10);
                if(en[i]->enemy_sp.getPosition().y>=500){
                    transition_done = true;
                }
            }
        }
    }

    void diamond() {

        diamond_called = true;

        int centerX = 400; 
        int centerY = 240; 
        int diamondSize = 170; 

        for (int i = 0; i < 3; i++) {
            en[i]->enemy_sp.setPosition(centerX - diamondSize / 2 + i * diamondSize / 2, centerY - diamondSize / 2);
        }

        for (int i = 3; i < 7; i++) {
            en[i]->enemy_sp.setPosition(centerX + diamondSize / 2, centerY - diamondSize / 2 + (i - 2) * diamondSize / 2);
        }

        for (int i = 7; i < 10; i++) {
            en[i]->enemy_sp.setPosition(centerX + diamondSize / 2 - (i - 6) * diamondSize / 2, centerY + diamondSize / 2);
        }

        for (int i = 10; i < 14; i++) {
            en[i]->enemy_sp.setPosition(centerX - diamondSize / 2, centerY + diamondSize / 2 - (i - 9) * diamondSize / 2);
        }

        // for(int i=0;i<numen;i++){
        //     en[i]->enemy_sp.setPosition(en[i]->enemy_sp.getPosition().x,en[i]->enemy_sp.getPosition().y-500);
        // }

    }

    void diamondTransition() {
        int centerX = 400; 
        int centerY = 240; 
        float speed = 2.0f;

        if (!transition_done) {
            for (int i = 0; i < numen; i++) {
                float pos_x = en[i]->enemy_sp.getPosition().x;
                float pos_y = en[i]->enemy_sp.getPosition().y;

                float dir_x = centerX - pos_x;
                float dir_y = centerY - pos_y;

                float len = sqrt(dir_x*dir_x + dir_y*dir_y);

                if (len > speed) { 
                    dir_x /= len; 
                    dir_y /= len; 
                    en[i]->enemy_sp.move(dir_x * speed, dir_y * speed);
                } else { 
                    diamond();
                    if(i == numen-1)
                        transition_done = true;
                }
            }
        }
    }
    
    void heart() {

        en[0]->enemy_sp.setPosition(340,220);//
        en[1]->enemy_sp.setPosition(480,175);//
        en[2]->enemy_sp.setPosition(590,225);//
        en[3]->enemy_sp.setPosition(550,345);//
        en[4]->enemy_sp.setPosition(510,420);//5
        en[5]->enemy_sp.setPosition(435,490);//6
        en[6]->enemy_sp.setPosition(200,175);//
        en[7]->enemy_sp.setPosition(90,225);//
        en[8]->enemy_sp.setPosition(130,345);//
        en[9]->enemy_sp.setPosition(170,420);//10
        en[10]->enemy_sp.setPosition(245,490);//11
        en[11]->enemy_sp.setPosition(340,320);
        en[12]->enemy_sp.setPosition(340,420);
        en[13]->enemy_sp.setPosition(340,540);

        for(int i=0;i<numen;i++){
            en[i]->enemy_sp.setPosition(en[i]->enemy_sp.getPosition().x,en[i]->enemy_sp.getPosition().y-100);
        }

    }


    void meteor_transition(){

        draw_meteor = true;

        if(meteor_flag){
            meteor_sp.setPosition(780,-500);
            meteor_flag = false;
        }
        else{
            meteor_sp.move(-5,3);
        }

        if(meteor_sp.getPosition().x<=120){
            meteor_transition_flag = false;
        }
        else{
            meteor_transition_flag = true;  
        }
        if(meteor_sp.getPosition().x<=-750){
            transition_done = true;
            draw_meteor = false;
            meteor_flag = true;
        }
    }

    void transition_up_to_down(){

        float current_y = 0;

        if(!position_set){
            for(int i=0;i<numen;i++){

                current_y = en[i]->enemy_sp.getPosition().y;

                en[i]->enemy_sp.setPosition(en[i]->enemy_sp.getPosition().x,current_y-400);

                // en[i]->getbomb()->bomb_sp.setPosition(en[i]->enemy_sp.getPosition());

            }
            position_set = true;
        }

        if(!transition_done){
            for(int i=0;en[numen-1]->enemy_sp.getPosition().y<10 && i<numen;i++){
                //if(en[i]->enemy_sp.getPosition().y==-5)
                    //en[i]->enemy_sp.setPosition(en[i]->enemy_sp.getPosition().x,5);
                //else
                en[i]->enemy_sp.move(0,5);
                //cout<<en[4]->enemy_sp.getPosition().y<<endl;
            }        

            if(en[numen-1]->enemy_sp.getPosition().y>=10){
                transition_done = true;
            }
        
        }
    }

    void Hollow_rectangle(){

        for(int j=0;j<numen;j++){

            if(j==0)
                en[j]->enemy_sp.setPosition(115,10);

            if(j==5)
                en[5]->enemy_sp.setPosition(115,300);

            if(j==10)
                en[10]->enemy_sp.setPosition(115,100);

            if(j==12)
                en[12]->enemy_sp.setPosition(625,100);

            if(j==13)
                en[13]->enemy_sp.setPosition(625,200);

            if(j>0 && j<5)
                en[j]->enemy_sp.setPosition((j+1)*125,10);
            else if(j>5 && j<10)
                en[j]->enemy_sp.setPosition((j-4)*125,300);

            else if(j>10 && j<12)
                en[j]->enemy_sp.setPosition(115,(j-9)*100);

        }

    }

    void triangle(){

        int i=1;

        for(int j=0;j<numen;j++){

            if(j==0){
                en[j]->enemy_sp.setPosition(10,10);
            }
            else if(j>0&&j<5){
                en[j]->enemy_sp.setPosition((j+1)*65,j*95);
            }

            if(j==5){
                en[j]->enemy_sp.setPosition(680,10);

            }

            if(j>5&&j<9){

                en[j]->enemy_sp.setPosition(660-(i*85),i*95);
                i++;
            }

            if(j==9){
                en[j]->enemy_sp.setPosition(120,10);

            }

            if(j>9&&j<numen){
                en[j]->enemy_sp.setPosition((j-8)*120,10);
            }

        }

    }
    
    void crossTransition(float speed) {
        int i = 1;
        bool allReached = true; 

        for (int j = 0; j < numen; j++) {
            float currentPosX = en[j]->enemy_sp.getPosition().x;
            float currentPosY = en[j]->enemy_sp.getPosition().y;
            float targetPosX, targetPosY;

            if (j == 0) {
                targetPosX = 10.0f;
                targetPosY = 10.0f;
            } else if (j > 0 && j < 7) {
                targetPosX = j * 100.0f;
                targetPosY = j * 91.0f;
            } else if (j == 7) {
                targetPosX = 680.0f;
                targetPosY = 10.0f;
            } else if (j > 7 && j < numen) {
                targetPosX = 680.0f - (i * 100.0f);
                targetPosY = i * 91.0f;
                i++;
            }

            float dirX = targetPosX - currentPosX;
            float dirY = targetPosY - currentPosY;

            float length = sqrt(dirX * dirX + dirY * dirY);
            if (length > 0.01f) { 
                dirX /= length;
                dirY /= length;

                en[j]->enemy_sp.setPosition(currentPosX + dirX * speed, currentPosY + dirY * speed);

                allReached = false;
            }
        }

        if (allReached) {
            transition_done = true;
        }
    }

    void Cross(){

        int i=1;

        for(int j=0;j<numen;j++){

            if(j==0)
                en[j]->enemy_sp.setPosition(10,10);

            else if(j>0&&j<7 ){
                en[j]->enemy_sp.setPosition(j*100,j*91);
            }

            if(j==7)
                en[j]->enemy_sp.setPosition(680,10);
            else if(j>7&&j<numen){
                en[j]->enemy_sp.setPosition(680-(i*100),i*91);
                i++;
            }

        }

        for (int j = 0; j < numen; j++) {
            if (j < numen / 2) {
                en[j]->enemy_sp.setPosition(0, 0);  // Top left corner
            } else {
                en[j]->enemy_sp.setPosition(680, 0);  // Top right corner
            }
        }
    }

    void Stage_three(){
               
        // cout<<"S2 - Cp1"<<endl;

        if(en)
            for(int i=0;i<numen;i++){
                if(en[i])
                    delete en[i];
            }

        if(en)
            delete[] en;

        numen = 15;

        en=new Enemies*[numen];    
       
        if(bombs){
            delete[] bombs;
        }

        // cout<<"S2 - Cp2"<<endl;
        
        total_shoot = 6;

        if(random_shoot){
            delete[] random_shoot;
        }

        random_shoot = new Shooting_random[total_shoot];

        for(int i=0;i<total_shoot;i++){
            random_shoot[i].index = 0;
        }

        bombs = new Bombs[numen];

        for(int j=0;j<numen;j++){

            int random_enemy = rand()%3;

            switch (random_enemy)
            {
            case 0:
                // cout<<"S2 - Cp2.1"<<endl;
                
                en[j]= new Alpha(&bombs[j]);
                break;
            case 1:
                // cout<<"S2 - Cp2.2"<<endl;

                en[j] = new Beta(&bombs[j]);

                // cout<<"S2 - Cp2.21"<<endl;
                break;
            case 2:
                // cout<<"S2 - Cp2.3"<<endl;

                en[j] = new Gamma(&bombs[j]);
                break;
            default:
                // cout<<"S2 - Cp2.4"<<endl;

                en[j]= new Alpha(&bombs[j]);
                break;
            }

        }
        // cout<<"S2 - Cp3"<<endl;

        if(!filledrect_cleared)
            filledrect();
        else if(!filledtriangle_cleared)
            filledtriangle();
        else if(!filledcircle_cleared)
            filledcircle();
        
        // cout<<"S2 - Cp4"<<endl;

        all_des = false;
    }
        
    void filledrect(){
        int numEnemiesInRow = 5;  
        int numEnemiesInColumn = 3;  
        int startX = 115; 
        int startY = 10;  
        int spacing = 125;  

        numen = numEnemiesInRow * numEnemiesInColumn; 

        for(int j=0;j<numen;j++){
            int i = j / numEnemiesInRow;  
            int k = j % numEnemiesInRow;  

            int x = startX + k * spacing;  
            int y = startY + i * spacing;  

            en[j]->enemy_sp.setPosition(x, y);  
        }
    }

    void filledtriangle() {
        // filledtriangle_cleared = true;
        // filledcircle_cleared = false;
        int baseY = 10;  
        int rowHeight = 100; 
        int enemyWidth = 780 / 5;  

        int enemyIndex = 0;

        for (int row = 5; row >= 1; row--) {

            int baseX = (780 - (row * enemyWidth)) / 2;

            for (int i = 0; i < row; i++) {
                en[enemyIndex]->enemy_sp.setPosition(baseX + i * enemyWidth, baseY);
                enemyIndex++;
            }

            baseY += rowHeight;
        }
    }
    void filledcircle() {
        int centerX = 340; 
        int centerY = 200;
        int numEnemiesPerCircle = 5; 
        float angleStep = 2 * 3.14159 / numEnemiesPerCircle; 

        int radii[3] = {70, 140, 210}; 

        for (int i = 0; i < 3; i++) { 
            float angleOffset = i * (angleStep / 3); 
            for (int j = 0; j < numEnemiesPerCircle; j++) { 
                float angle = angleOffset + j * angleStep; 
                float x = centerX + radii[i] * cos(angle); 
                float y = centerY + radii[i] * sin(angle); 

                en[i*numEnemiesPerCircle + j]->enemy_sp.setPosition(x, y);
            }
        }
    }



    void rebalancing(){

        // cout<<"Reb - Cp1"<<endl;

        //cout << "cp1" << endl;
        for(int p=0;p<numen;p++){
            
            //cout << "cp2" << endl;
            // cout<<"Reb - Cp1.1"<<endl;

            if(!transition_done && en[0]->destroyed && !triangle_cleared && rect_cleared){
                en[0]->destroyed = false;
            }
            // cout<<"Reb - Cp1.2"<<endl;

            if(en[p]->destroyed){
                
                // if(en[p]->getbomb()->bomb_sp.getPosition().y<750){
                    
                // }
                for(int i=0;i<4;i++)    
                    explosion.Explosion_sprite[i].setPosition(en[p]->enemy_sp.getPosition());

                explosion.explosion_flag = true;

                explosion.exp_ind = 0;

                en[p] = NULL;

                numen--;

                //total_shoot--;

                for(int o=p;o<numen && numen >= 0;o++){
                    //cout<<"moving "<<o<<endl;
                    en[o] = en[o+1]; 
                    //cout<<"to "<<o+1<<endl;
                }
                //cout << "cp4" << endl;
 
            }
            // cout<<"Reb - Cp1.3"<<endl;

        }
        // cout<<"Reb - Cp2"<<endl;

        //cout<<"Numen "<<numen<<endl;
        //cout << "cp5" << endl;  

        if(numen<=0 && !all_des){
            // cout<<"Reb - Cp2.1"<<endl;

            if(en){
                delete[] en;
            }

            // cout<<"Reb - Cp2.1.1"<<endl;

            en = new Enemies*[1];
            // cout<<"Reb - Cp2.1.2"<<endl;

            Bombs* b = new Bombs;

            en[0] = new Alpha(b);
            // cout<<"Reb - Cp2.1.3"<<endl;

            en[0]->destroyed = true;
            // cout<<"Reb - Cp2.1.4"<<endl;

            all_des = true;

            // cout<<"Reb - Cp2.2"<<endl;

        }

        // cout<<"Reb - Cp3"<<endl;

        if(!Stage_one_completed){

            if(numen == 0){

                if(!rect_cleared){
                    rect_cleared = true;
                    stage_one_flag=true;
                }
                else if(!triangle_cleared){
                    triangle_cleared = true;
                    stage_one_flag=true;
                }
                else if(!cross_cleared && !triangle_skipped){
                    cross_cleared = true;
                    if(boss[random_boss]->monster_done){
                        ;
                    }else{
                        stage_one_flag=true;
                    }
                }
                else if(boss[random_boss]->monster_done && !cross_skipped && !triangle_skipped){
                    Stage_one_completed = true;
                }
            }
            // cout<<"Reb - Cp4"<<endl;
        }
        else if(!Stage_two_completed && stage_two_initialized_flag){

            if(numen == 0){

                if(!circle_cleared){
                    circle_cleared = true;
                    transition_done = false;
                    stage_two_flag=true;
                }
                else if(!diamond_cleared && diamond_called){
                    diamond_cleared = true;
                    stage_two_flag=true;
                }
                else if(!heart_cleared && !diamond_skipped){
                    heart_cleared = true;
                    if(boss[random_boss]->monster_done){
                        ;
                    }else{
                        stage_two_flag=true;
                    }
                }
                else if(boss[random_boss]->monster_done && !heart_skipped && !diamond_skipped){
                    Stage_two_completed = true;
                }
            }
            // cout<<"Reb - Cp4"<<endl;
        }
        else if(!Stage_three_completed && stage_three_initialized_flag){

            if(numen == 0){

                if(!filledrect_cleared){
                    filledrect_cleared = true;
                    stage_three_flag=true;
                }
                else if(!filledtriangle_cleared && filledtriangle_called){
                    filledtriangle_cleared = true;
                    if(filledcircle_cleared == true){
                        filledcircle_cleared = false;
                    }
                    stage_three_flag=true;
                }
                else if(!filledcircle_cleared && !filledtriangle_skipped){
                    filledcircle_cleared = true;
                    if(boss[random_boss]->monster_done){
                        ;
                    }else{
                        stage_three_flag=true;
                    }
                }
                else if(boss[random_boss]->monster_done && !filledcircle_skipped && !filledtriangle_skipped){
                    Stage_three_completed = true;
                }
            }
            // cout<<"Reb - Cp4"<<endl;
        }
    }

    void shootbombs(){

        // cout<<"Sb - Cp1"<<endl;

        // if(total_shoot == numen){
        //     total_shoot--;
        // }

        if(numen == 1){
            total_shoot = 1;
        }else if(numen==0){
            total_shoot = 0;
        }
        
        // cout<<"Sb - Cp2"<<endl;

        if(numen!=0)
        {
            // cout<<"Sb - Cp2.1"<<endl;   
            for(int i = 0; i < total_shoot; i++) {
                
                int randomIndex;
                int attempts = 0;

                if(bombs[random_shoot[i].index].shooted && bombs[random_shoot[i].index].bomb_sp.getPosition().y>=780){
                    bombs[random_shoot[i].index].bomb_sp.setPosition(-100,-100);
                    bombs[random_shoot[i].index].shooted = false;
                }

                if(!bombs[random_shoot[i].index].shooted){
                    do {
                        randomIndex = rand() % numen;
                        attempts++;
                    } while((bombs[randomIndex].shooted || !en[randomIndex] || en[randomIndex]->destroyed) && attempts<numen);

                    random_shoot[i].index = randomIndex;
                    random_shoot[i].name = en[random_shoot[i].index]->name;
                    random_shoot[i].x = en[randomIndex]->enemy_sp.getPosition().x;
                    random_shoot[i].y = en[randomIndex]->enemy_sp.getPosition().y;  
                }

                bombs[random_shoot[i].index].bombmove(random_shoot[i].name, random_shoot[i].x, random_shoot[i].y);
                
                if((bombs[random_shoot[i].index].KillPlayer(p->sprite))&&!p->flash){
                    for(int i=0;i<4;i++)
                        p->Explosion_sprite[i].setPosition(p->sprite.getPosition());

                    //cout<<"player hit!!!"<<endl;
                    int y = p->lives;
                    if(!p->flash)    
                        p->lives--;
                    int x=p->lives;

                    if(y-x==1){

                        int z = x-3;
                        lives_string ="+" + to_string(z);
                        lives_text.setString(lives_string);
                    }

                    if(!p->flash)
                        p->sprite.setPosition(p->x, p->y);    
                        
                    
                    current_time = timer;
                    if(!p->flash)    
                        p->explosion = true;

                    bombs[random_shoot[i].index].shooted = false;
                }
            }
            // cout<<"Sb - Cp2.2"<<endl;   
        }
        // cout<<"Sb - Cp3"<<endl;

    }

    void monsterTransitionRight(Enemies** boss, bool& transition_done) {
        static const float targetX = -1200.0f;
        static const float targetY = 10.0f;
        static const float transitionSpeed = 5.0f;

        if (!transition_done && !boss[0]->flag) {
            float monsterHeight = boss[0]->enemy_sp.getTexture()->getSize().y * boss[0]->enemy_sp.getScale().y;
            boss[0]->enemy_sp.setPosition(targetX, monsterHeight);
            
            for(int i=0;i<boss[0]->total_beam;i++)
                boss[0]->beam_sp[i].setPosition(boss[0]->enemy_sp.getPosition().x+25,boss[0]->enemy_sp.getPosition().y+115);
            boss[0]->flag = true;
        }

        float currentX = boss[0]->enemy_sp.getPosition().x;
        float currentY = boss[0]->enemy_sp.getPosition().y;

        if (currentY <= targetY) {

            float directionX = targetX - currentX;
            float directionY = targetY - currentY;

            float length = sqrt((directionX * directionX) + (directionY * directionY));
            directionX /= length;
            directionY /= length;

            boss[0]->enemy_sp.move(-(directionX * transitionSpeed), -(directionY * transitionSpeed));
        } else {

            boss[0]->enemy_sp.setPosition(targetX, targetY);
            transition_done = false;
        }
    }

    void monsterTransition(Enemies** boss, bool& transition_done) {
        static const float targetX = 200.0f;
        static const float targetY = 10.0f;
        static const float transitionSpeed = 5.0f;

        if (!transition_done && !boss[0]->flag) {
            float monsterHeight = boss[0]->enemy_sp.getTexture()->getSize().y * boss[0]->enemy_sp.getScale().y;
            boss[0]->enemy_sp.setPosition(targetX, -monsterHeight);
            
            for(int i=0;i<boss[0]->total_beam;i++)
                boss[0]->beam_sp[i].setPosition(boss[0]->enemy_sp.getPosition().x+25,boss[0]->enemy_sp.getPosition().y+115);
            boss[0]->flag = true;
        }

        float currentX = boss[0]->enemy_sp.getPosition().x;
        float currentY = boss[0]->enemy_sp.getPosition().y;

        if (currentY <= targetY) {

            float directionX = targetX - currentX;
            float directionY = targetY - currentY;

            float length = sqrt((directionX * directionX) + (directionY * directionY));
            directionX /= length;
            directionY /= length;

            boss[0]->enemy_sp.move(directionX * transitionSpeed, directionY * transitionSpeed);
        } else {

            boss[0]->enemy_sp.setPosition(targetX, targetY);
            transition_done = true;
        }
    }

    void callMonster(){

        if(!boss[0]->monster_uptodown_transition){
            monsterTransition(boss,boss[0]->monster_uptodown_transition);
        }

        if(!escape){
            if(boss[0]->monster_uptodown_transition){  
                boss[0]->moveEnemy();
                playerHit();
            }

        }

        if(boss[0]->monster_uptodown_transition){
            boss[0]->firebomb();            
        }

    }

    void callStageone(){

        if(rect_cleared && stage_one_flag && !triangle_cleared && !boss[random_boss]->monster_bool){
            
            boss[random_boss]->monster_bool = rand()%2;

            if(boss[random_boss]->monster_done){
                boss[random_boss]->monster_bool = false;
            }

            if(!boss[random_boss]->monster_bool){
                Stage_one();
                transition_done = false;
                stage_one_flag = false;
            }
            else{
                transition_done = false;
                stage_one_flag = false;
                boss[random_boss]->monster_bool = true;
                boss[random_boss]->monster_done = false;
                boss[random_boss]->monster_right = false;
                boss[random_boss]->monster_timer = 90000000;
                boss[random_boss]->monster_uptodown_transition = false;
                triangle_skipped = true;
            }

        }else if(!triangle_skipped &&triangle_cleared && stage_one_flag && !cross_cleared && !boss[random_boss]->monster_bool){
            
            boss[random_boss]->monster_bool = rand()%2;

            if(boss[random_boss]->monster_done){
                boss[random_boss]->monster_bool = false;
            }

            if(!boss[random_boss]->monster_bool){
                Stage_one();
                transition_done = false;
                stage_one_flag = false;
            }
            else{
                transition_done = false;
                stage_one_flag = false;
                boss[random_boss]->monster_bool = true;
                boss[random_boss]->monster_done = false;
                boss[random_boss]->monster_right = false;
                boss[random_boss]->monster_timer = 90000000;
                boss[random_boss]->monster_uptodown_transition = false;
                cross_skipped = true;
            }
        }else if(!boss[random_boss]->monster_done && triangle_cleared && rect_cleared && cross_cleared && stage_one_flag ){
            transition_done = false;
            stage_one_flag = false;
            boss[random_boss]->monster_bool = true;
            boss[random_boss]->monster_done = false;
            boss[random_boss]->monster_right = false;
            boss[random_boss]->monster_timer = 90000000;
            boss[random_boss]->monster_uptodown_transition = false;
            //Stage_one_completed = true;
        }

        // cout<<"Cp6"<<endl;
        
        
        if(boss[random_boss]->monster_done && triangle_skipped){
            triangle_cleared = false;
            triangle_skipped = false;
            stage_one_flag = true;
        }else if(boss[random_boss]->monster_bool && cross_skipped){
            cross_cleared = false;
            cross_skipped = false;
            stage_one_flag = true;
        }
        // cout<<"boss[0]->monster_done "<<boss[0]->monster_done<<endl;
        // cout<<"!triangle_cleared"<<!triangle_cleared<<endl;
        // cout<<"!cross_cleared"<<!cross_cleared<<endl;

        if(boss[random_boss]->monster_done && (!triangle_cleared || !cross_cleared)){
            // cout<<"In the first if cond "<<endl; 
            if(!triangle_cleared && stage_one_flag){
                // cout<<"In the 2nd if cond "<<endl; 
                Stage_one();
                transition_done = false;
                stage_one_flag = false;
                // triangle_cleared = true;
            }
            else if(!cross_cleared && stage_one_flag){
                Stage_one();
                transition_done = false;
                stage_one_flag = false;
                // cross_cleared = true;
            }

            if(triangle_cleared && cross_cleared){
                boss[random_boss]->monster_done = false;
            }

        } 

        if(!transition_done && rect_cleared && !triangle_cleared && !boss[random_boss]->monster_bool){
            transition_up_to_down();
        }
        //cout<<"!tran"<<!transition_done<<" and "<<"tri clear "<<triangle_cleared<<endl;
        if(!transition_done && triangle_cleared && !boss[random_boss]->monster_bool){
            crossTransition(5);
            if(!triangle_cleared && !boss[random_boss]->monster_done){
                triangle_cleared = true;
                boss[random_boss]->monster_done = true;
            }
            //cout<<"transition"<<endl;
        }
        //cout<<"hi"<<endl;
        if(cross_cleared && stage_one_flag){
            rebalancing();
            stage_one_flag = false;
        }
        // cout<<"Cp7"<<endl;
    
    }

    void callStagetwo(){

        // if(!transition_done && !circle_cleared && !escape){
        //     //Hollow_Circle_Transition();
        //     meteor_transition();
        // }
        if(transition_done && !circle_cleared && stage_two_flag){
            Stage_two();
            stage_two_flag = false;
            transition_done = true;
        }else if(circle_cleared && stage_two_flag && !diamond_cleared && !boss[random_boss]->monster_bool){
            
            boss[random_boss]->monster_bool = rand()%2;

            if(boss[random_boss]->monster_done){
                boss[random_boss]->monster_bool = false;
            }

            if(!boss[random_boss]->monster_bool){
                Stage_two();
                transition_done = false;
                stage_two_flag = false;
            }
            else{
                transition_done = false;
                stage_two_flag = false;
                boss[random_boss]->monster_bool = true;
                boss[random_boss]->monster_done = false;
                boss[random_boss]->monster_right = false;
                boss[random_boss]->monster_timer = 90000000;
                boss[random_boss]->monster_uptodown_transition = false;
                diamond_skipped = true;
            }

        }else if(!diamond_skipped &&diamond_cleared && stage_two_flag && !heart_cleared && !boss[random_boss]->monster_bool){
            
            boss[random_boss]->monster_bool = rand()%2;

            if(boss[random_boss]->monster_done){
                boss[random_boss]->monster_bool = false;
            }

            if(!boss[random_boss]->monster_bool){
                Stage_two();
                transition_done = false;
                stage_two_flag = false;
            }
            else{
                transition_done = false;
                stage_two_flag = false;
                boss[random_boss]->monster_bool = true;
                boss[random_boss]->monster_done = false;
                boss[random_boss]->monster_right = false;
                boss[random_boss]->monster_timer = 90000000;
                boss[random_boss]->monster_uptodown_transition = false;
                heart_skipped = true;
            }
        }else if(!boss[random_boss]->monster_done && diamond_cleared && circle_cleared && heart_cleared && stage_two_flag ){
            transition_done = false;
            stage_two_flag = false;
            boss[random_boss]->monster_bool = true;
            boss[random_boss]->monster_done = false;
            boss[random_boss]->monster_right = false;
            boss[random_boss]->monster_timer = 90000000;
            boss[random_boss]->monster_uptodown_transition = false;
        }

        if(boss[random_boss]->monster_done && diamond_skipped){
            diamond_cleared = false;
            diamond_skipped = false;
            stage_two_flag = true;
        }else if(boss[random_boss]->monster_done && heart_skipped){
            heart_cleared = false;
            heart_skipped = false;
            stage_two_flag = true;
        }

        if(boss[random_boss]->monster_done && (!diamond_cleared || !heart_cleared)){
            if(!diamond_cleared && stage_two_flag){
                Stage_two();
                transition_done = false;
                stage_two_flag = false;
            }
            else if(!heart_cleared && stage_two_flag){
                Stage_two();
                transition_done = false;
                stage_two_flag = false;
            }

            if(diamond_cleared && heart_cleared){
                boss[random_boss]->monster_done = false;
            }
        } 

        if(heart_cleared && stage_two_flag){
            rebalancing();
            stage_two_flag = false;
        }
    }

    void callStagethree(){

        if(filledrect_cleared && transition_done && stage_three_flag  && !boss[0]->monster_bool){
            Stage_three();
            transition_done = true;
            stage_three_flag = false;
        }

        if(filledrect_cleared && stage_three_flag && !filledtriangle_cleared && !boss[random_boss]->monster_bool){
            
            boss[random_boss]->monster_bool = rand()%2;

            if(boss[random_boss]->monster_done){
                boss[random_boss]->monster_bool = false;
            }

            if(!boss[random_boss]->monster_bool){
                Stage_three();
                transition_done = false;
                stage_three_flag = false;
            }
            else{
                transition_done = false;
                stage_three_flag = false;
                boss[random_boss]->monster_bool = true;
                boss[random_boss]->monster_done = false;
                boss[random_boss]->monster_right = false;
                boss[random_boss]->monster_timer = 90000000;
                boss[random_boss]->monster_uptodown_transition = false;
                filledtriangle_skipped = true;
            }

        }else if(!filledtriangle_skipped &&filledtriangle_cleared && stage_three_flag && !filledcircle_cleared && !boss[random_boss]->monster_bool){
            
            boss[random_boss]->monster_bool = rand()%2;

            if(boss[random_boss]->monster_done){
                boss[random_boss]->monster_bool = false;
            }

            if(!boss[random_boss]->monster_bool){
                Stage_three();
                transition_done = false;
                stage_three_flag = false;
            }
            else{
                transition_done = false;
                stage_three_flag = false;
                boss[random_boss]->monster_bool = true;
                boss[random_boss]->monster_done = false;
                boss[random_boss]->monster_right = false;
                boss[random_boss]->monster_timer = 90000000;
                boss[random_boss]->monster_uptodown_transition = false;
                // filledcircle_skipped = true;
            }
        }else if(!boss[random_boss]->monster_done && filledrect_cleared && filledtriangle_cleared && filledcircle_cleared && stage_three_flag ){
            transition_done = false;
            stage_three_flag = false;
            boss[random_boss]->monster_bool = true;
            boss[random_boss]->monster_done = false;
            boss[random_boss]->monster_right = false;
            boss[random_boss]->monster_timer = 90000000;
            boss[random_boss]->monster_uptodown_transition = false;
        }

        if(boss[random_boss]->monster_done && filledtriangle_skipped){
            filledtriangle_cleared = false;
            filledtriangle_skipped = false;
            stage_three_flag = true;
        }else if(boss[random_boss]->monster_done && filledcircle_skipped){
            filledcircle_cleared = false;
            filledcircle_skipped = false;
            stage_three_flag = true;
        }

        if(boss[random_boss]->monster_done && (!filledtriangle_cleared || !filledcircle_cleared)){
            if(!filledtriangle_cleared && stage_three_flag){
                Stage_three();
                transition_done = false;
                stage_three_flag = false;
            }
            else if(!filledcircle_cleared && stage_three_flag){
                Stage_three();
                transition_done = false;
                stage_three_flag = false;
            }

            if(filledtriangle_cleared && filledcircle_cleared){
                boss[random_boss]->monster_done = false;
            }
        } 

        if(filledcircle_cleared && stage_three_flag){
            rebalancing();
            stage_three_flag = false;
        }
    }

};
