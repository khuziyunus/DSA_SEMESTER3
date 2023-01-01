#pragma once
#include <iostream>
#include <windows.h>
#include "linkedlist.hpp"
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


int len(Node* head)
{
    Node* temp = head ;
    int i = 0 ;
    while(temp!=NULL)
    {
        i++;
        temp=temp->next ;
    }
    
    return i ;
}

Node* swap(Node* ptr1, Node* ptr2)
{
    Node* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

void bubbleSort(Node** head)
{
    int length=len(*head);
    Node** temp;
    int i, j, swapped;
    Node* p1,*p2;
    Node *ttt = *head;
  
    for (i = 0; i <= length; i++)
    {
  
        temp = head;
        swapped = 0;
  
        for (j = 0; j < length - i - 1; j++) 
        {
  
            p1 = *temp;
            p2 = p1->next;
  
            if (p1->data > p2->data)
            {
  
                *temp = swap(p1, p2);
                swapped = 1;
                hashDisplay(ttt);
            }
  
            temp = &(*temp)->next;
        }

        if (swapped == 0)
            break;
    }
    return;
}

void BubbleSort()
{
    Node *Head = new Node();
    for(int i = 0 ; i < 40 ; i++)
        addNode(Head, (rand() % 100) + 1);
    findTimeComplexity(bubbleSort, &Head);
    
    bubbleSort(&Head);
}