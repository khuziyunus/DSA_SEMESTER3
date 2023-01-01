#pragma once
#include<chro
#include <iostream>
#include <windows.h>
using namespace std;


struct Node{
	int data   ;
	Node* next ;

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
void hashDisplay(Node* Head)
{
    struct Node * tmp = Head->next;
    while (tmp!= NULL)
        {
            // cout<<tmp->data << " \n";
            for(int i = 0 ; i < tmp->data ; i++)
            {
                cout<<"#";
            }
            cout<<"\n";
            tmp = tmp->next;
        }

        system("cls");
}
void findTimeComplexity(void (*sortFunc)(Node**), Node ** Head)
{
  // Record start time
  auto start =  ::chrono::high_resolution_clock::now();
  // Call the sorting function
  sortFunc(Head);
  // Record end time
  auto end =  ::chrono::high_resolution_clock::now();
  // Calculate elapsed time
  auto elapsed =  ::chrono::duration_cast< chrono::microseconds>(end - start);
  // Print elapsed time
   cout << "Time elapsed: " << elapsed.count() << " microseconds" <<  endl;
}