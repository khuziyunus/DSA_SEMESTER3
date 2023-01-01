#pragma once
#include <iostream>
#include <queue>
#include <windows.h>
#include "linkedlist.hpp"

class HeapNode{
	public:
		int data;
		HeapNode* left;
		HeapNode* right;
		HeapNode* parent;
		HeapNode(int val)
		{
			data = val;
			left = NULL;
			right = NULL;
			parent = NULL;
		}
};


void Hashinorder(HeapNode* he)
{
	if(he == NULL)
	{
		return;
	}
	Hashinorder(he->left);
	for(int i = 0 ; i < he->data ; i++)
            {
                std::cout<<"#";
            }
            std::cout<<"\n";
	Hashinorder(he->right);
}




class Heap{
	HeapNode* root;
	public:
		Heap()
		{
			root = NULL;
		}
	HeapNode* lastparent()
	{
		std::queue<HeapNode*> q;
		q.push(root);
		HeapNode* temp;
		
		while(!q.empty())
		{
			temp = q.front();
			q.pop();
			if(temp->left && temp->right)
			{
				q.push(temp->left);
				q.push(temp->right);
			}
			else
			{
				break;
			}
		}
		return temp;
	}
		void upHeapify(HeapNode* temp)
		{
			if(temp->parent == NULL)
			{
				return;
			}
			if(temp->parent->data < temp->data)
			{
				std::swap(temp->parent->data,temp->data);
				upHeapify(temp->parent);
			}
		}
		void add(int data)
		{
			HeapNode* newnode = new HeapNode(data);
			std::cout<<"Inserting: "<<data<<"\n";
			
			if(root == NULL)
			{
				root = newnode;
				return;
			} 
			
			HeapNode* lpar = lastparent();
			
			if(lpar->left == NULL)
			{
				lpar->left = newnode;
				newnode->parent = lpar;
			}
			else
			{
				lpar->right = newnode;
				newnode->parent = lpar;
			}
			upHeapify(newnode);
		}
		
		void inorder(HeapNode* he)
		{
			if(he == NULL)
			{
				return;
			}
			inorder(he->left);
			std::cout<<he->data<<" ";
			inorder(he->right);
		}
		
		void print()
		{
			std::cout<<"Printing the data of the Heap: ";
			HeapNode* temp = root;
			inorder(temp);
			std::cout<<std::endl;
		}
		bool isEmpty()
		{
			if(root == NULL)
			{
				return true;
			}
			else
				return false;
		}
		HeapNode* lastnode()
		{
			std::queue<HeapNode*> q;
			q.push(root);
			HeapNode* last;
			while(!q.empty())
			{
				last = q.front();
				q.pop();
				if(last->left)
				{
					q.push(last->left);
				}
				if(last->right)
				{
					q.push(last->right);
				}
			}
			return last;
		}
		void downHeapify(HeapNode* he)
		{
			HeapNode* largest = he;
			
			if(he->left && he->left->data > largest->data)
			{
				largest = he->left;
			}
			if(he->right && he->right->data > largest->data)
			{
				largest = he->right;
			}
			if(largest != he)
			{
				std::swap(largest->data,he->data);
				downHeapify(largest);
			}
		}
		void remove()
		{
			if(isEmpty())
			{
				std::cout<<"Heap is empty\n";
				return;
			}
			std::cout<<"Deleting: "<<root->data<<std::endl;
			
			HeapNode* last = lastnode();
			if(last == root)
			{
				delete last;
				root == NULL;
				return;
			}
			std::swap(root->data, last->data);
			HeapNode* pr = last->parent;
			
			if(pr->left == last)
			{
				delete last;
				pr->left = NULL;
			}
			else
			{
				delete last;
				pr->right = NULL;
			}
			
			downHeapify(root);
		}
};

void HashHeap(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
	{
		for(int j = 0 ; j < arr[i] ; j ++)
		{
			std::cout<<'#';
		}
    	cout << "\n";
	}
	system("cls");
}

void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
	HashHeap(arr, 40);
}
 
// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
 
