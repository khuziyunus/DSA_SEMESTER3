#include<iostream>
#include <bits/stdc++.h>
#include<SFML/Graphics.hpp>
#include <algorithm>
#include <cmath>

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

const int BUCKET_SIZE = 10;

// Function to sort an array using radix sort
void radixSort(Node** Head) {
    Node* temp = *Head;
    int index = 0;

    while (temp !=NULL)
    {
        recHs[index++] = temp->data  ;
        temp = temp->next;
    }

    // int arr[80];
    // std::copy(recHs, recHs+80, arr);

  // Find the maximum number to know the number of digits
 // int maxNum = *max_element(arr, arr + 80);
int maxNum;
  for(int i = 1;i < 80; ++i) {

    // Change < to > if you want to find the smallest element
    if(recHs[0] < recHs[i])
      maxNum = recHs[i];
  }
  // Do counting sort for every digit. Note that instead of
  // passing digit number, exp is passed. exp is 10^i
  // where i is the current digit number
  for (int exp = 1; maxNum / exp > 0; exp *= 10) {
    // Create 10 buckets (0-9) to store the numbers
    int bucket[BUCKET_SIZE] = {0};

    // Store the count of numbers in each bucket
    for (int i = 0; i < n; i++) {
      bucket[int(recHs[i] / exp) % 10]++;
    }

    // Modify the bucket[] so that it now contains actual
    // position of the digits in the output array
    for (int i = 1; i < BUCKET_SIZE; i++) {
      bucket[i] += bucket[i - 1];
    }

    // Create a temporary array to store the sorted array
    int temp[n];
    for (int i = n - 1; i >= 0; i--) {
      temp[--bucket[int(recHs[i] / exp) % 10]] = recHs[i];
    }

    // Copy the sorted array back to arr
    for (int i = 0; i < n; i++) {
      recHs[i] = temp[i];
      dispSort(i);
    }
    dispSort(exp);
  }
  sorted = true;
}

void QuickSort(Node **Head)
{

}


void MergeSort(Node **Head)
{
    
}

int main()
{

    Node *Head = new Node() ;
     for(int i = 0 ; i < 80 ; i++)
         addNode(Head, (rand() % 500) + 1);
    
   



    while(window.isOpen())
    {
        sf::Event event;


        while (window.pollEvent(event)){
            switch(event.type){

                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
      

        if(!sorted){
            dispSort(0);
             
            //insertionSort(&Head);
            //bubbleSort(&Head);
            //QuickSort(&Head);
            radixSort(&Head);
        }
        

        window.display();

    }

}







// void quicksort(Node** Head, int left, int right) {
//   // base case: if the subrecHs has less than 2 elements, it is already sorted
  

//    Node*temp = *Head;
//     int index = 0;

//     while (temp !=NULL)
//     {
//         recHs[index++] = temp->data  ;
//         temp = temp->next;
//     }
  
//   if (left >= right) {
//     return;
//   }

//   // choose pivot as the middle element of the subrecHs
//   int pivotIndex = left + (right - left) / 2;
//   int pivot = recHs[pivotIndex];

//   // partition the recHs into two subrecHss around the pivot
//   int i = left;
//   int j = right;
//   while (i <= j) {
//     // find the first element in the left subrecHs that is greater than the pivot
//     while (recHs[i] < pivot) {
//       i++;
//     }
//     // find the first element in the right subrecHs that is less than the pivot
//     while (recHs[j] > pivot) {
//       j--;
//     }
//     // if i and j have not crossed, swap the elements and move on to the next pair
//     if (i <= j) {
//       int temp = recHs[i];
//       recHs[i] = recHs[j];
//       recHs[j] = temp;
//       i++;
//       j--;
//     }
//   }

//   // recursively sort the left and right subrecHss
//   quicksort(left, j);
//   quicksort(i, right);
// }


















