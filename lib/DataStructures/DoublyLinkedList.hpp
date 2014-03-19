/////////////////////////////
//
//  File:
//      \file DoublyLinkedList.hpp
//
//  Description:
//      \brief Doubly Linked List: Templated Header & Impl
//
//  Author:
//      \author J. Caleb Wherry
//
/////////////////////////////

// Include Guards:
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

// Forward Declared Dependencies:
//

// Local Include Dependencies:
//

// Compiler Include Dependencies:
#include <cstdlib>      // NULL
#include <iostream>     // cout, endl

// Namespace:
namespace doublyLinkedList
{

template <typename T>
struct Node {
	T datum;
	Node* prev;
	Node* next;
};

template <typename T>
class DoublyLinkedList {

	private:
		Node<T>* head;
        Node<T>* tail;
        int size;

	public:
		DoublyLinkedList();

		void pushBack(T data);

		void pushFront(T data);

		void popBack(T data);

		void popFront(T data);

		void print();

}; // DoublyLinkedList

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

template <typename T>
void DoublyLinkedList<T>::pushBack(T data)
{
    // Create new node:
    Node<T>* newNode = new Node<T>();

    // Set values for new node:
    newNode->next = NULL;
    newNode->prev = NULL;
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
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        size++;
    }
}

template <typename T>
void DoublyLinkedList<T>::pushFront(T data)
{
    // TODO
}

template <typename T>
void DoublyLinkedList<T>::popBack(T data)
{
    Node<T>* nodeToDelete = new Node<T>();
    nodeToDelete = head;

    for (int i = 0; i < size; i++)
    {
        if (data == nodeToDelete->datum)
        {
            // TODO
        }
    }
}

template <typename T>
void DoublyLinkedList<T>::popFront(T data)
{
    // TODO
}

template <typename T>
void DoublyLinkedList<T>::print()
{
    Node<T>* nodeToPrint = new Node<T>();
    nodeToPrint = head;

    while (nodeToPrint != NULL)
    {
        std::cout << nodeToPrint->datum << " ";
        nodeToPrint = nodeToPrint->next;
    }
}

} // doublyLinkedList namespace

#endif // DOUBLY_LINKED_LIST_H
