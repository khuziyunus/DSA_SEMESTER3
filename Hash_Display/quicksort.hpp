#pragma once
#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
#include "linkedlist.hpp"

// Creating structure

// Add new node at end of linked list
void insert(struct Node** head, int value)
{
	// Create dynamic node
	struct Node* node
		= (struct Node*)malloc(sizeof(struct Node));
	if (node == NULL) {
		// checking memory overflow
		printf("Memory overflow\n");
	}
	else {
		node->data = value;
		node->next = NULL;
		if (*head == NULL) {
			*head = node;
		}
		else {
			struct Node* temp = *head;

			// finding last node
			while (temp->next != NULL) {
				temp = temp->next;
			}

			// adding node at last position
			temp->next = node;
		}
	}
}


// Finding last node of linked list
struct Node* last_node(struct Node* head)
{
	struct Node* temp = head;
	while (temp != NULL && temp->next != NULL) {
		temp = temp->next;
	}
	return temp;
}

// We are Setting the given last node position to its proper
// position
struct Node* parition(struct Node* first, struct Node* last, Node* MAINHEAD)
{
	// Get first node of given linked list
	struct Node* pivot = first;
	struct Node* front = first;
	int temp = 0;
	while (front != NULL && front != last) {
		if (front->data < last->data) {
			pivot = first;

			// Swapping node values
			temp = first->data;
			first->data = front->data;
			front->data = temp;
	
			hashDisplay(MAINHEAD);
			// Visiting the next node
			first = first->next;
		}

		// Visiting the next node
		front = front->next;
	}

	// Change last node value to current node
	temp = first->data;
	first->data = last->data;
	last->data = temp;
	return pivot;
}


void quick_sort(struct Node* first, struct Node* last, Node* MAINHEAD)
{
	if (first == last) {
		return;
	}
	struct Node* pivot = parition(first, last, MAINHEAD);

	if (pivot != NULL && pivot->next != NULL) {
		quick_sort(pivot->next, last, MAINHEAD);
	}

	if (pivot != NULL && first != pivot) {
		quick_sort(first, pivot, MAINHEAD);
	}
}



void QuickSort()
{
	struct Node* head = NULL;

	// Create linked list
	
    for(int i = 0 ; i < 40 ; i++)
        insert(&head, (rand() % 100) + 1);
		
		findTimeComplexity(quick_sort,& Head);
	quick_sort(head, last_node(head), head);

}
