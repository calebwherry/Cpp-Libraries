/////////////////////////////
//
//  File:
//      \file Tree.hpp
//
//  Description:
//      \brief Tree: Header & Impl
//
//  Author:
//      \author J. Caleb Wherry
//
/////////////////////////////

// Include Guards:
#ifndef TREE_H
#define TREE_H

// Forward Declared Dependencies:
//

// Local Include Dependencies:
//

// Compiler Include Dependencies:
#include <cstdlib>
#include <iostream>

/// Namespace:
namespace tree
{
	/// Tree Class:
	class Tree {

		protected:

			/// Default Constructor:
      Tree();

      /// Deconstructor:
      ~Tree();
    
			/// Pure virtual Print:
      virtual void print() = 0;

      /// Tree Depth
      int depth;

	}; // Tree

	Tree::Tree()
			: depth(0)
	{
	}

	Tree::~Tree()
	{
		// TODO
	}

} // tree namespace

#endif // TREE_H
