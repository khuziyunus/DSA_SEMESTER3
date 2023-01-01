#include"Menu.h"

MainMenu::MainMenu(float width, float height)
{
    if(!font.loadFromFile("D:\\DSA_SemmesterProject\\DSA_SEMESTER3\\GUI_Implementation\\src\\include\\SFML\\Fonts\\AlexandriaFLF.ttf")){
        cout<<"No font is Here";
    }
    //play
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(Color::White);
    mainMenu[0].setString("Play");
    mainMenu[0].setCharacterSize(70); 
    mainMenu[0].setPosition(400,100);
    
    //options
    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(Color::White);
    mainMenu[1].setString("Options");
    mainMenu[1].setCharacterSize(70);
    mainMenu[1].setPosition(400,200);

    //about
    mainMenu[2].setFont(font);
    mainMenu[2].setFillColor(Color::White);
    mainMenu[2].setString("About");
    mainMenu[2].setCharacterSize(70);
    mainMenu[2].setPosition(400,300);

    //Merge_SORT
    mainMenu[3].setFont(font);
    mainMenu[3].setFillColor(Color::White);
    mainMenu[3].setString("Exit");
    mainMenu[3].setCharacterSize(70);
    mainMenu[3].setPosition(400,400);


    MainMenuSelected = -1;


}


MainMenu::~MainMenu()
{

}
//draw MAINmenue

void MainMenu :: draw(RenderWindow& window)
{
    for (int i = 0; i < Max_Main_Menue ; ++i)
    {
        window.draw(mainMenu[i]);
    }
}

void MainMenu :: MoveUp()
{
    if (MainMenuSelected - 1 >= 0)
    {
        mainMenu[MainMenuSelected].setFillColor(Color::White);

        MainMenuSelected--;
        if(MainMenuSelected == -1)
        {
            MainMenuSelected = 2;
        }
     mainMenu[MainMenuSelected].setFillColor(Color::Blue);

        
    }
}

void MainMenu :: MoveDown()
{
    if (MainMenuSelected + 1 <= Max_Main_Menue)
    {
        mainMenu[MainMenuSelected].setFillColor(Color::White);
        MainMenuSelected++;
        if(MainMenuSelected == 4)
        {
            MainMenuSelected = 0;
        }
     mainMenu[MainMenuSelected].setFillColor(Color::Blue);

        
    }
}














