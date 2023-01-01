#include<iostream>
#include<SFML/Graphics.hpp>

sf::RenderWindow window(sf::VideoMode(960, 600), "Sorter");
const int n=80;
float recHs[n];
bool sorted=false;


void dispSort(int index){
    window.clear();
    

    for(int i=0; i<n; i++){
        sf::RectangleShape block(sf::Vector2f(10, recHs[i]));
        block.setPosition(i*12, 600-recHs[i]);
        block.setFillColor(sorted || i==index? sf::Color::Green : sf::Color::White);
        window.draw(block);
    }
    window.display();
}


// void 


struct Node{
	int data;
	Node* next  = nullptr;

};

void addNode(struct Node *head, int n) {
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;

	Node *cur = head;
	while(cur) {
		if(cur->next == NULL) {
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}

Node* swap(Node* ptr1, Node* ptr2)
{
    Node* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}


void bubbleSort(Node** Head) {
    Node*temp = *Head;
    int index = 0;

    while (temp !=NULL)
    {
        recHs[index++] = temp->data  ;
        temp = temp->next;
    }
    
 
  for (int step = 0; step < (n-1); ++step) {
    int swapped = 0;
    for (int i = 0; i < (n-1); ++i) {
      if (recHs[i] > recHs[i + 1]) {
        int temp = recHs[i];
        recHs[i] = recHs[i + 1];
        recHs[i + 1] = temp;
        
        swapped = 1;
        dispSort(i);
      }
    }
    if (swapped == 0)
      break;
    dispSort(step);
  }
  sorted = true;
}

void insertionSort(Node** Head)
{
     Node*temp = *Head;
    int index = 0;

    while (temp !=NULL)
    {
        recHs[index++] = temp->data  ;
        temp = temp->next;
    }
    
    int i, key, j;
    for (i = 0; i < n; i++)
    {
        key = recHs[i];
        j = i - 1;

        while (j >= 0 && recHs[j] > key)
        {
            recHs[j + 1] = recHs[j];
            j = j - 1;
            dispSort(j);
        }
        recHs[j + 1] = key;
    }

    sorted = true;

    dispSort(i);

}