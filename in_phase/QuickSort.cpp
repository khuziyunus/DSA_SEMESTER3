#include <SFML/Graphics.hpp>
#include <algorithm>
#include <sstream>

template <typename T>
void quickSort(T* array, int low, int high)
{
    while (low < high)
    {
        int pivotIndex = partition(array, low, high);
        quickSort(array, low, pivotIndex - 1);
        low = pivotIndex + 1;
    }
}

template <typename T>
int partition(T* array, int low, int high)
{
    T pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            std::swap(array[i], array[j]);
        }
    }

    std::swap(array[i + 1], array[high]);
    return i + 1;
}

int main()
{
    // Create an array of integers to sort
    int array[10] = { 5, 3, 8, 1, 2, 9, 4, 7, 6, 0 };

    // Sort the array using quicksort
    quickSort(array, 0, 9);

    // Create an SFML window to display the sorted array
    sf::RenderWindow window(sf::VideoMode(200, 200), "Quick Sort");
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        // Error loading font
        return 1;
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();

        // Draw the sorted array to the screen
        for (int i = 0; i < 10; i++)
        {
            sf::RectangleShape rect(sf::Vector2f(20, 20));
            rect.setPosition(sf::Vector2f(20 * i, 0));
            rect.setFillColor(sf::Color::White);
            window.draw(rect);

            sf::Text text;
            std::stringstream ss;
            ss << array[i];
            text.setString(ss.str());
            text.setFont(font);
            text.setCharacterSize(20);
            text.setPosition(sf::Vector2f(20 * i + 5, 0));
            window.draw(text);
        }

        window.display();
    }

    return 0;
}
