#include<iostream>
#include<SFML/Graphics.hpp>


sf::RenderWindow window(sf::VideoMode(1024, 768), "Sorter_Visuliser");
const int n = 80;
float recHs[n]; //induvidal rectranges
bool sorted = false;
const int BUCKET_SIZE = 10;
sf::Clock timer;


void dispSort(int index) { //display function
  window.clear();
    sf::Font font;
  if (!font.loadFromFile("arial.ttf")) {
    std::cout << "Error loading font" << std::endl;
  }

  sf::Text elapsedTimeText;
  sf::Time elapsedTime = timer.getElapsedTime();
  elapsedTimeText.setString(std::to_string(elapsedTime.asSeconds()) + " seconds");

  for (int i = 0; i < n; i++) {
    elapsedTimeText.setFont(font);
    elapsedTimeText.setCharacterSize(24);
    elapsedTimeText.setFillColor(sf::Color::Red);

    sf::RectangleShape block(sf::Vector2f(10, recHs[i]));
    block.setPosition(i * 12, 600 - recHs[i]);
    block.setFillColor(sorted || i == index ? sf::Color::Green: sf::Color::Red);

    window.draw(elapsedTimeText);
    window.draw(block);
  }
  window.display();
}
//start of node;
struct Node {
  int data;
  Node * next = nullptr;

};

void addNode(struct Node * head, int n) {
  Node * newNode = new Node;
  newNode -> data = n;
  newNode -> next = NULL;

  Node * cur = head;
  while (cur) {
    if (cur -> next == NULL) {
      cur -> next = newNode;
      return;
    }
    cur = cur -> next;
  }
}

Node * swap(Node * ptr1, Node * ptr2) {
  Node * tmp = ptr2 -> next;
  ptr2 -> next = ptr1;
  ptr1 -> next = tmp;
  return ptr2;
}

void bubbleSort(Node ** Head) {
  Node * temp = * Head;
  int index = 0;

  while (temp != NULL) {
    recHs[index++] = temp -> data;
    temp = temp -> next;
  }

  for (int step = 0; step < (n - 1); ++step) {
    int swapped = 0;
    for (int i = 0; i < (n - 1); ++i) {
      if (recHs[i] > recHs[i + 1]) {
        int temp = recHs[i];
        recHs[i] = recHs[i + 1];
        recHs[i + 1] = temp;

        swapped = 1;
        window.clear();

        dispSort(i);
      }
    }
    if (swapped == 0)
      break;
    dispSort(step);
  }
  sorted = true;
}

void insertionSort(Node ** Head) {
  Node * temp = * Head;
  int index = 0;
  while (temp != NULL) {
    recHs[index++] = temp -> data;
    temp = temp -> next;
  }
  int i, key, j;
  for (i = 0; i < n; i++) {
    key = recHs[i];
    j = i - 1;
    while (j >= 0 && recHs[j] > key) {
      recHs[j + 1] = recHs[j];
      j = j - 1;
      dispSort(j);
    }
    recHs[j + 1] = key;
  }
  sorted = true;
  dispSort(i);
}


// Function to sort an array using radix sort
void radixSort(Node ** Head) {
  Node * temp = * Head;
  int index = 0;

  while (temp != NULL) {
    recHs[index++] = temp -> data;
    temp = temp -> next;
  }

  int maxNum;
  for (int i = 1; i < 80; ++i) {
    if (recHs[0] < recHs[i])
      maxNum = recHs[i];
  }
  for (int exp = 1; maxNum / exp > 0; exp *= 10) {
    int bucket[BUCKET_SIZE] = {
      0
    };
    for (int i = 0; i < n; i++) {
      bucket[int(recHs[i] / exp) % 10]++;
    }
    for (int i = 1; i < BUCKET_SIZE; i++) {
      bucket[i] += bucket[i - 1];
    }
    int temp[n];
    for (int i = n - 1; i >= 0; i--) {
      temp[--bucket[int(recHs[i] / exp) % 10]] = recHs[i];
    }
    for (int i = 0; i < n; i++) {
      recHs[i] = temp[i];
      dispSort(i);
    }
    dispSort(exp);
  }
  sorted = true;
}


int main() {
  
  sf::Texture backgroundTexture;
  if (!backgroundTexture.loadFromFile("Sorting Visuliser.png")) {
    std::cout << "Error loading background image" << std::endl;
    return 1;
  }
  sf::Sprite backgroundSprite;
  backgroundSprite.setTexture(backgroundTexture);

  sf::Image icon;
  icon.loadFromFile("icon.png");
  window.setIcon(icon.getSize().x,icon.getSize().y,icon.getPixelsPtr());

  

  // button for the text
  sf::RectangleShape bubbleSortButton(sf::Vector2f(225, 50));
  bubbleSortButton.setPosition(170, 220);
  bubbleSortButton.setFillColor(sf::Color::Transparent);

  sf::RectangleShape insertionSortButton(sf::Vector2f(225, 50));
  insertionSortButton.setPosition(425, 620);
  insertionSortButton.setFillColor(sf::Color::Transparent);

  sf::RectangleShape BucketSortButton(sf::Vector2f(220, 50));
  BucketSortButton.setPosition(650, 220);
  BucketSortButton.setFillColor(sf::Color::Transparent);

  sf:: RectangleShape exit(sf::Vector2f(50,50));
  exit.setPosition(930,90);
  exit.setFillColor(sf::Color::Transparent);

  Node * Head = new Node();
  for (int i = 0; i < 80; i++)
    addNode(Head, (rand() % 500) + 1);

  while (window.isOpen()) {
    sorted = false;
    timer.restart();
    sf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        window.close();
        break;
      case sf::Event::KeyReleased:
        if (sf::Keyboard::Escape)
          window.close();
        break;
      case sf::Event::MouseButtonReleased: //event when mouse button is selected
        if (bubbleSortButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
          bubbleSort( & Head);
          window.draw(backgroundSprite);
        } else if (insertionSortButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
          insertionSort( & Head);
        } else if (BucketSortButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
          radixSort( & Head);
        }else if (exit.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
          return 0;
        }

      }
    }

    if (!sorted) {
      window.clear();
      window.draw(backgroundSprite);
      window.draw(bubbleSortButton);
      window.draw(insertionSortButton);
      window.draw(BucketSortButton);
      window.draw(exit);
      window.display();
    } else {
      dispSort(0);
      

      window.display();
    }
  }
}