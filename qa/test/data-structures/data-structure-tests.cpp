/////////////////////////////
//
//  File:
//      \file data-structure-tests.cpp
//
//  Description:
//      \brief DX Tests
//
//  Author:
//      \author J. Caleb Wherry
//
/////////////////////////////

// Local Include Dependencies:
#include "SinglyLinkedList.hpp"
#include "DoublyLinkedList.hpp"
#include "BinaryTree.hpp"

// Compiler Include Dependencies:
#include <iostream>
#include <string>

// Typedefs:
typedef int myType; 

// Namespaces:
namespace DLL = doublyLinkedList;
namespace SLL = singlyLinkedList;
namespace BT  = binaryTree;
using namespace DLL;
using namespace SLL;
using namespace BT;
using namespace std;

int main() 
{
    // Grab current cout flags, used for when the stream is altered and the user wants
    //   to reset it to the default values: 
    ios::fmtflags f( cout.flags() );

    // Test 1:
    {
	    SinglyLinkedList<char>* list = new SinglyLinkedList<char>();

	    char var = 'A';

	    for (int i = 1; i <= 10; i++) 
        {
		    list->pushBack(var);
		    var++;
	    }

	    cout << endl << "Test 1 - Char list:" << endl << "\t";
	    list->print();
        cout << endl;
    }

    // Reset cout stream flags:
    cout.flags(f);

    // Test 2:
    {
        DoublyLinkedList<myType>* list = new DoublyLinkedList<myType>();

        myType var = 1;

        for (int i = 1; i <= 10; i++) 
        {
            list->pushBack(var);
            var++;
        }

        cout << endl << "Test 2 - Int list:" << endl << "\t";
        list->print();
        cout << endl;
    }

    // Reset cout stream flags:
    cout.flags(f);

    // Test 3:
    {
        BinaryTree<int>* bt = new BinaryTree<int>();

        // Insert a bunch of stuff:
        bt->insert(11);
        bt->insert(6);
        bt->insert(8);
        bt->insert(19);
        bt->insert(4);
        bt->insert(10);
        bt->insert(5);
        bt->insert(17);
        bt->insert(43);
        bt->insert(49);
        bt->insert(31);

        // Print tree preOrderTraversal:
        cout << endl << "Binary Tree PreOrderTravesal:" << endl << "\t";
        bt->preOrderTraversal();
        cout << endl;

        // Print tree inOrderTraversal:
        cout << endl << "Binary Tree InOrderTravesal:" << endl << "\t";
        bt->inOrderTraversal();
        cout << endl;

        // Print tree postOrderTraversal:
        cout << endl << "Binary Tree PostOrderTravesal:" << endl << "\t";
        bt->postOrderTraversal();
        cout << endl;
    }

    cout << endl;

    return 0;
}
