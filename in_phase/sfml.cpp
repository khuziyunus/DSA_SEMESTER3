#include<SFML/Graphics.hpp>
#include"Menu.h"

int main()
{
    RenderWindow Menu(VideoMode(960,720),"MAIN MENUE",Style :: Default);
    MainMenu mainMenu(Menu.getSize().x,Menu.getSize().y);

//set background
RectangleShape background;
background.setSize(Vector2f(960,720));
Texture Maintexture;
Maintexture.loadFromFile("src/Textures/main_menue.jpg");
background.setTexture(&Maintexture);



    while(Menu.isOpen())
    {
        Event event;
        while (Menu.pollEvent(event))
        {   
            if(event.type == Event ::Closed)
            {
                Menu.close();
            }
            if(event.type == Event :: KeyReleased)
            {
                if(event.key.code == Keyboard ::Up)
                {
                    mainMenu.MoveUp();
                    break;
                }
                if(event.key.code = Keyboard :: Down)
                {
                    mainMenu.MoveDown();
                    break;
                }
                if(event.key.code == Keyboard :: Return)
                {
                    RenderWindow PLAY(VideoMode(960, 720),"Game_name");
                    RenderWindow OPTIONS(VideoMode(960, 720),"OPTIONS");
                    RenderWindow ABOUT(VideoMode(960, 720),"ABOUT");
                    
                    int x = mainMenu.MainMenuPressed();
                    if(x == 0 )
                    {
                        
                        while(PLAY.isOpen())
                        {
                            Event aevent;
                            while(PLAY.pollEvent(aevent))
                            {
                                if(aevent.type == Event ::Closed)
                                {
                                    PLAY.close();
                                }
                                if(aevent.type == Event :: KeyPressed)
                                {
                                    if(aevent.key.code == Keyboard::Escape)
                                    {
                                        PLAY.close();
                                    }
                                    
                                
                                }
                                
                            OPTIONS.close();
                            ABOUT.close();
                            // PLAY.clear();

                        PLAY.display();
                            }


                            
                            
                        }
                    }
                    if(x == 1)
                    {
                        while(OPTIONS.isOpen())
                        {
                            Event aevent;
                            while(OPTIONS.pollEvent(aevent))
                            {
                                if(aevent.type == Event :: Closed)
                                {
                                    OPTIONS.close();
                                }
                                if(aevent.type == Event :: KeyPressed)
                                {
                                    if(aevent.key.code == Keyboard::Escape)
                                    {
                                        OPTIONS.close();
                                    }

                                }
                            }

                            PLAY.close();
                            OPTIONS.clear();
                            ABOUT.close();
                            
                            OPTIONS.display();
                        }
                    }
                    if(x == 2)
                    {
                        while(ABOUT.isOpen())
                        {
                            Event aevent;
                            while(ABOUT.pollEvent(aevent))
                            {
                                if(aevent.type == Event :: Closed)
                                {
                                    ABOUT.close();
                                }
                                if(aevent.type == Event :: KeyPressed)
                                {
                                    if(aevent.key.code == Keyboard::Escape)
                                    {
                                        ABOUT.close();
                                    }

                                }
                            }

                            PLAY.close();
                            OPTIONS.clear();
                            ABOUT.clear();
                            
                            ABOUT.display();
                        }
                    }
                    if(x == 3)
                            Menu.close();
                        break;
                }
            }
        }
        Menu.clear();
        mainMenu.draw(Menu);
        Menu.display();
   }

}
