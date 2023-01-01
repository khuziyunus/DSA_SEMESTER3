#include <SFML/Graphics.hpp>



int main()
{
    sf::Font font;

    if (!font.loadFromFile("D:\\DSA_SemmesterProject\\DSA_SEMESTER3\\GUI_Implementation\\src\\include\\SFML\\Fonts\\AlexandriaFLF.ttf"))
        return 1; // Return an error code if the font couldn't be loaded
        
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(960, 600), "Main Menu");

    // Load the font

    // Create the buttons
    sf::Text option1ButtonText("Option 1", font, 32);
    option1ButtonText.setString("option_1");
    option1ButtonText.setFillColor(sf::Color::Black);
    option1ButtonText.setPosition(400.0f, 100.0f);
    sf::RectangleShape option1Button(sf::Vector2f(200.0f, 50.0f));
    option1Button.setFillColor(sf::Color::Green);
    option1Button.setPosition(400.0f, 100.0f);


    sf::Text option2ButtonText("Option 2", font, 32);
    option2ButtonText.setString("option_2");
    option2ButtonText.setFillColor(sf::Color::Black);
    option2ButtonText.setPosition(400.0f, 200.0f);
    sf::RectangleShape option2Button(sf::Vector2f(200.0f, 50.0f));
    option2Button.setFillColor(sf::Color::Green);
    option2Button.setPosition(400.0f, 200.0f);

    sf::Text option3ButtonText("Option 3", font, 32);
    option3ButtonText.setString("option_3");
    option3ButtonText.setFillColor(sf::Color::Black);
    option3ButtonText.setPosition(400.0f, 300.0f);
    sf::RectangleShape option3Button(sf::Vector2f(200.0f, 50.0f));
    option3Button.setFillColor(sf::Color::Green);
    option3Button.setPosition(400.0f, 300.0f);


    sf::Text option4ButtonText("Option 4", font, 32);
    option4ButtonText.setString("option_4");
    option4ButtonText.setFillColor(sf::Color::Black);
    option4ButtonText.setPosition(400.0f, 400.0f);
    sf::RectangleShape option4Button(sf::Vector2f(200.0f, 50.0f));
    option4Button.setFillColor(sf::Color::Green);
    option4Button.setPosition(400.0f, 400.0f);

    sf::Text option5ButtonText("Option 5", font, 32);
    option5ButtonText.setString("option_5");
    option5ButtonText.setFillColor(sf::Color::White);
    option5ButtonText.setPosition(400.0f, 500.0f);
    sf::RectangleShape option5Button(sf::Vector2f(200.0f, 50.0f));
    option5Button.setFillColor(sf::Color::Green);
    option5Button.setPosition(400.0f, 500.0f);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
       sf::Event event;
while (window.pollEvent(event))
{
    switch (event.type)
    {
        case sf::Event::Closed:
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
                window.close();
            break;

        case sf::Event::MouseButtonReleased:
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (option1Button.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                        sf::RenderWindow window(sf::VideoMode(640, 480), "My Window");
                        // create the circle
                        sf::CircleShape circle(50.0f);
                        circle.setPosition(100.0f, 100.0f); // set the position of the circle
                        circle.setFillColor(sf::Color::Red); // set the fill color of the circle

                        // run the program as long as the window is open
                        while (window.isOpen())
                        {
                            // check all the window's events that were triggered since the last iteration of the loop
                            sf::Event event;
                            while (window.pollEvent(event))
                            {
                                // "close requested" event: we close the window
                                if (event.type == sf::Event::Closed)
                                    window.close();
                            }

                            // clear the window with black color
                            window.clear(sf::Color::Black);

                            // draw the circle
                            window.draw(circle);

                        // end the current frame
                        window.display();
                    }
                }
                else if (option2Button.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    // Option 2 was clicked
                    // ...
                }
                else if (option3Button.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    // Option 3 was clicked
                    // ...
                }
                else if (option4Button.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    // Option 4 was clicked
                    // ...
                }
                else if (option5Button.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    return 0;
                }
            }
            break;
    }
}

       
        // Clear the window with black color
        window.clear(sf::Color::White);

        // Draw the buttons
        window.draw(option1Button);
        window.draw(option1ButtonText);

        window.draw(option2Button);
        window.draw(option2ButtonText);
        
        window.draw(option3Button);
        window.draw(option3ButtonText);
        
        window.draw(option4Button);
        window.draw(option4ButtonText);
        
        window.draw(option5Button);
        window.draw(option5ButtonText);

        // Display the window contents on the screen
        window.display();
    }

    return 0;
}
