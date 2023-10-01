#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#define height 780
#define width 780
using namespace sf;
using namespace std;

class Menu
{
public:
    Texture menu_tex;
    Sprite menu;
    Font font;
    Text menu_text;
    Event e;
    bool StartGame;
    Cursor cursor;
    Texture cursor_tex;
    bool help_section_flag, controls, enemies, powerups, goal, bosses, once;
    int count;
    bool leadership_flag;
    // add menu attributes here
    Menu()
    {
        leadership_flag = false;
        count = 0;
        help_section_flag = false;
        controls = false;
        enemies = false;
        once = false;
        powerups = false;
        goal = false;
        bosses = false;
        StartGame = false;
        menu_tex.loadFromFile("img/Menu/menu.png");
        cursor_tex.loadFromFile("img/PNG/UI/cursor.png");
        RenderWindow w(VideoMode(0,0), "Space Bubble - Dobule Trouble"); //done to change cursor
        cursor.loadFromPixels(cursor_tex.copyToImage().getPixelsPtr(), cursor_tex.getSize(), w.getSize());
        menu.setTexture(menu_tex);
        font.loadFromFile("Fonts/ZandaLover.otf");
        menu_text.setFont(font);
        // constructors body
    }

    void leader_ship(int x, int y){
        menu_tex.loadFromFile("img/Leadership.png");
        if(Mouse::isButtonPressed(Mouse::Left))
            if(x>625 && x<774 && y>20 && y<81)
                leadership_flag = false;   
    }

    void help_section(int x,int y){

        menu_tex.loadFromFile("img/Menu/help/help.png");

        if(Mouse::isButtonPressed(Mouse::Left) && !controls)
            if(x>337 && x<543 && y>185 && y<239)
                controls = true;
        
        if(controls){
            menu_tex.loadFromFile("img/Menu/help/controls.png");
        
            if(Mouse::isButtonPressed(Mouse::Left))
                if(x>20 && x<156 && y>14 && y<74)
                    controls = false;
        }
        
        if(Mouse::isButtonPressed(Mouse::Left) && !enemies)
            if(x>497 && x<729 && y>268 && y<332)
                enemies = true;
        
        if(enemies){
            menu_tex.loadFromFile("img/Menu/help/enemies.png");
        
            if(Mouse::isButtonPressed(Mouse::Left))
                if(x>20 && x<156 && y>14 && y<74)
                    enemies = false;
        }
        
        if(Mouse::isButtonPressed(Mouse::Left) && !powerups)
            if(x>153 && x<441 && y>352 && y<412 && once)
                powerups = true;
        
        if(powerups){
            menu_tex.loadFromFile("img/Menu/help/powerups.png");
        
            if(Mouse::isButtonPressed(Mouse::Left))
                if(x>20 && x<156 && y>14 && y<74){
                    powerups = false;
                }
        }

        if(Mouse::isButtonPressed(Mouse::Left) && !goal)
            if(x>377 && x<498 && y>438 && y<497)
                goal = true;
        
        if(goal){
            menu_tex.loadFromFile("img/Menu/help/goal.png");
        
            if(Mouse::isButtonPressed(Mouse::Left))
                if(x>20 && x<156 && y>14 && y<74)
                    goal = false;
        }

        if(Mouse::isButtonPressed(Mouse::Left) && !bosses)
            if(x>181 && x<365 && y>530 && y<588)
                bosses = true;
        
        if(bosses){
            menu_tex.loadFromFile("img/Menu/help/bosses.png");

            if(Mouse::isButtonPressed(Mouse::Left))
                if(x>20 && x<156 && y>14 && y<74)
                    bosses = false;
        }

        if(Mouse::isButtonPressed(Mouse::Left))
            if(x>625 && x<774 && y>20 && y<81)
                help_section_flag = false;

        if(!once && count == 15)
            once = true;

    }

    void display_menu()

    {

        // display menu screen here

        RenderWindow window(VideoMode(height, width), "Space Shooter", Style::Titlebar | Style::Close);
        
        window.setMouseCursor(cursor);
        
        //window.setMouseCursorVisible(false);

        while (window.isOpen())
        {

            while (window.pollEvent(e))
            {

                if (e.type == Event::Closed)
                {
                    StartGame = false;
                    window.close();
                }

                if (Keyboard::isKeyPressed(Keyboard::Escape)){
                    StartGame = false;
                    window.close();
                }
                // else if (Keyboard::isKeyPressed(Keyboard::P))
                // {
                //     StartGame = true;
                //     window.close();
                // }
                else if (Keyboard::isKeyPressed(Keyboard::S))
                {
                    // settings
                }
                // else if (Keyboard::isKeyPressed(Keyboard::H))
                // {
                //     // Help
                //     help_section_flag = true;
                    
                // }
            }

            //cout<<"Mouse position :- "<<Mouse::getPosition(window).x<<" , "<<Mouse::getPosition(window).y<<endl;

            int mouseposwindow_x = Mouse::getPosition(window).x;

            int mouseposwindow_y = Mouse::getPosition(window).y;

            if (mouseposwindow_x > 243 && mouseposwindow_x < 539 && mouseposwindow_y > 176 && mouseposwindow_y < 293)
            {

                if (Mouse::isButtonPressed(Mouse::Left) && !help_section_flag)
                {

                    StartGame = true;
                    window.close();
                }
            }

            if (mouseposwindow_x > 243 && mouseposwindow_x < 539 && mouseposwindow_y > 336 && mouseposwindow_y < 451)
            {

                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    // help
                    help_section_flag = true;
                
                }
            }

            if (mouseposwindow_x > 15 && mouseposwindow_x < 134 && mouseposwindow_y > 64 && mouseposwindow_y < 113)
            {

                if (Mouse::isButtonPressed(Mouse::Left) && !help_section_flag)
                {
                    leadership_flag = true;
                    // leadership board
                }
            }

            if (mouseposwindow_x > 16 && mouseposwindow_x < 83 && mouseposwindow_y > 117 && mouseposwindow_y < 184)
            {

                if (Mouse::isButtonPressed(Mouse::Left) && !help_section_flag)
                {
                    StartGame = false;

                    window.close();
                }
            }

            if (mouseposwindow_x > 144 && mouseposwindow_x < 216 && mouseposwindow_y > 5 && mouseposwindow_y < 78)
            {

                if (Mouse::isButtonPressed(Mouse::Left) && !help_section_flag)
                {

                    // settings
                }
            }

            if(help_section_flag)
                help_section(mouseposwindow_x,mouseposwindow_y);
            else if(leadership_flag){
                leader_ship(mouseposwindow_x,mouseposwindow_y);
            }
            else{
                menu_tex.loadFromFile("img/Menu/menu.png");
                once = false;
                count = 0;
            }
            window.clear(Color::Black);

            window.draw(menu);

            window.display();

            if(count <=15)
                count++;
            else
                count = 0;
        
        }

            
    }

    bool getGameStarted(){
        return StartGame;
    }
    
    void setGameStarted(bool y){
        StartGame = y;
    }
};
