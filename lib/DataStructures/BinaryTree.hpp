/////////////////////////////
//
//  File:
//      \file BinaryTree.hpp
//
//  Description:
//      \brief Binary Tree: Templated Header & Impl
//
//  Author:
//      \author J. Caleb Wherry
//
/////////////////////////////

// Include Guards:
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

// Forward Declared Dependencies:
//

// Local Include Dependencies:
#include "Tree.hpp"

// Compiler Include Dependencies:
#include <cstdlib>
#include <iostream>

// Namespaces:
using namespace tree;

/// binaryTree Namespace
namespace binaryTree
{
    /// Binary Tree Node
    template <typename T>
    struct Node 
    {
        Node()
            : leftChild(NULL),
              rightChild(NULL)
        {
        }

        T datum;
        Node* leftChild;
        Node* rightChild;
    };

    /// Binary Tree class
    template <typename T>
    class BinaryTree : public Tree
    {
        private:
            /// Root Node
            Node<T>* root;

        public:
            /// Default constructor
            BinaryTree();

            /// Deconstructor
            ~BinaryTree();

            /// Insert item
            void insert(T givenData);

            /// Insert item at node
            void insert(T givenData, Node<T>* givenNode);

            /// Remove item
            void remove(T givenData);

            /// Remove item at node
            void remove(T givenData, Node<T>* givenNode);

            /// preOrderTravesal from the root node
            void preOrderTraversal();

            /// preOrderTravesal from a given node
            void preOrderTraversal(Node<T>* givenNode);

            /// inOrderTraversal from the root node
            void inOrderTraversal();

            /// inOrderTraversal from a given node
            void inOrderTraversal(Node<T>* givenNode);

            /// postOrderTraversal from the root node
            void postOrderTraversal();

            /// postOrderTraversal from a given node
            void postOrderTraversal(Node<T>* givenNode);

            /// breadthFirstTraversal from the root node
            void breadthFirstTraversal();

            /// breadthFirstTraversal from a given node
            void breadthFirstTraversal(Node<T>* givenNode);

            /// Print Binary Tree
            void print();

    }; // BinaryTree

    template <typename T>
    BinaryTree<T>::BinaryTree()
        : root(NULL)
    {
    }

    template <typename T>
    BinaryTree<T>::~BinaryTree()
    {
    }

    template <typename T>
    void BinaryTree<T>::insert(T givenData)
    {
        // If tree is empty, create single node:
        if (root == NULL)
        {
            Node<T>* newNode = new Node<T>();
            newNode->datum = givenData;
            root = newNode;
        }
        else // If not, find where to insert data:
        {
            insert(givenData, root);
        }
    }

    template <typename T>
    void BinaryTree<T>::insert(T givenData, Node<T>* givenNode)
    {
        // Compare given data and data of current node:
        if (givenNode->datum == givenData)
        {
            return;
        }
        else if (givenData < givenNode->datum)
        {
            if (givenNode->leftChild != NULL)
            {
                insert(givenData, givenNode->leftChild);
            }
            else
            {
                Node<T>* newNode = new Node<T>();
                newNode->datum = givenData;
                givenNode->leftChild = newNode;
            }
        }
        else if (givenData > givenNode->datum)
        {
            if (givenNode->rightChild != NULL)
            {
                insert(givenData, givenNode->rightChild);
            }
            else
            {
                Node<T>* newNode = new Node<T>();
                newNode->datum = givenData;
                givenNode->rightChild = newNode;
            }    
        }
    }

    template <typename T>
    void BinaryTree<T>::remove(T givenData)
    {
        remove(givenData, root);
    }

    template <typename T>
    void BinaryTree<T>::remove(T givenData, Node<T>* givenNode)
    {

    }

    template <typename T>
    void BinaryTree<T>::preOrderTraversal()
    {
        preOrderTraversal(root);
    }

    template <typename T>
    void BinaryTree<T>::preOrderTraversal(Node<T>* givenNode)
    {
        // Check given node for nullity:
        if (givenNode == NULL)
            return;
            
        // Output current node data:
        std::cout << givenNode->datum << " ";
        
        // Recurse through left child:
        preOrderTraversal(givenNode->leftChild);

        // Recurse through right child:
        preOrderTraversal(givenNode->rightChild);
    }

    template <typename T>
    void BinaryTree<T>::inOrderTraversal()
    {
        inOrderTraversal(root);
    }

    template <typename T>
    void BinaryTree<T>::inOrderTraversal(Node<T>* givenNode)
    {
        // Check given node for nullity:
        if (givenNode == NULL)
            return;

        // Recurse through left child:
        inOrderTraversal(givenNode->leftChild);

        // Output current node data:
        std::cout << givenNode->datum << " ";

        // Recurse through right child:
        inOrderTraversal(givenNode->rightChild);

    }

    template <typename T>
    void BinaryTree<T>::postOrderTraversal()
    {
        postOrderTraversal(root);
    }

    template <typename T>
    void BinaryTree<T>::postOrderTraversal(Node<T>* givenNode)
    {
        // Check given node for nullity:
        if (givenNode == NULL)
            return;
    
        // Recurse through left child:
        postOrderTraversal(givenNode->leftChild);

        // Recurse through right child:
        postOrderTraversal(givenNode->rightChild);

        // Output current node data:
        std::cout << givenNode->datum << " ";
    }

    template <typename T>
    void BinaryTree<T>::breadthFirstTraversal()
    {
        breadthFirstTraversal(root);
    }

    template <typename T>
    void BinaryTree<T>::breadthFirstTraversal(Node<T>* givenNode)
    {
        // Check given node for nullity:
        if (givenNode == NULL)
            return;
    }

    template <typename T>
    void BinaryTree<T>::print()
    {
        // TODO
    }

} // binaryTree namespace

#endif // BINARY_TREE_H
