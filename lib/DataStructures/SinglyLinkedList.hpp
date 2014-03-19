/////////////////////////////
//
//  File:
//      \file SinglyLinkedList.h
//
//  Description:
//      \brief Singly Linked List: Header
//
//  Author:
//      \author J. Caleb Wherry
//
/////////////////////////////

// Include Guards:
#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

// Forward Declared Dependencies:
//

// Local Include Dependencies:
//

// Compiler Include Dependencies:
#include <cstdlib>      // NULL
#include <iostream>     // cout, endl

// Namespace:
namespace singlyLinkedList
{

template <typename T>
struct Node {
	T datum;
	Node* next;
};

template <typename T>
class SinglyLinkedList {

	private:
		Node<T>* head;
		Node<T>* tail;
        int size;

	public:
		SinglyLinkedList();

		void insert(T data);

		void remove(T data);

		bool contains(T data);

		void pushBack(T data);

		void pushFront(T data);

		void popBack();

		void popFront();

		void print();

		void printReverse();

}; // SinglyLinkedList

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

template <typename T>
void SinglyLinkedList<T>::pushBack(T data)
{
    // Create new node:
    Node<T>* newNode = new Node<T>();

    // Set values for new node:
    newNode->next = NULL;
    newNode->datum = data;

    // Insert new node based on current head and tail:
    if (head == NULL) 
    {
        head = newNode;
        tail = newNode;
        size = 1;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
        size++;
    }
}

template <typename T>
void SinglyLinkedList<T>::pushFront(T data)
{
    // TODO
}

template <typename T>
void SinglyLinkedList<T>::popBack()
{

    Node<T>* nodeToDelete = new Node<T>();
    nodeToDelete = head;

    while (nodeToDelete->next != NULL)
    {
        // TODO
    }

}

template <typename T>
void SinglyLinkedList<T>::popFront()
{
    // TODO
}

template <typename T>
void SinglyLinkedList<T>::print()
{

    Node<T>* nodeToPrint = new Node<T>();
    nodeToPrint = head;

    while (nodeToPrint != NULL)
    {
        std::cout << nodeToPrint->datum << " ";
        nodeToPrint = nodeToPrint->next;
    }
}

} // singlyLinkedList namespace

#endif // SINGLY_LINKED_LIST_H
