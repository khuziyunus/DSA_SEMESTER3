#pragma once
#include <iostream>
#include <windows.h>
#include "linkedlist.hpp"

void SortedPush(struct Node **head, struct Node *newNode)
{
    struct Node *curr;

    if (*head == NULL or (*head)->data > newNode->data)
        {
        newNode->next = *head, *head = newNode;
        }
    else
    {
        curr = *head;
        while (curr->next != NULL && curr->next->data <= newNode->data)
            curr = curr->next;
        newNode->next = curr->next, curr->next = newNode;
    }
}


void InsertionSort(struct Node **head)
{
    struct Node *sortedList = NULL;
    struct Node *temp = *head;

    struct Node *curr = *head;
    while (curr != NULL)
    {
        struct Node *next = curr->next;
        SortedPush(&sortedList, curr);
        hashDisplay(temp);

        curr = next;
    }
    *head = sortedList;
}


void insertionSort()
{

    Node *Head = new Node();
    for(int i = 0 ; i < 40 ; i++)
        addNode(Head, (rand() % 100) + 1);
    findTimeComplexity(insertionSort,& Head);
   
   InsertionSort(&Head);
}
