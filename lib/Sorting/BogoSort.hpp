/////////////////////////////
//
//  File:
//     BogoSort.hpp
//
//  Description:
//      Bogo Sort: Templated Header & Impl
//
//  Author:
//      J. Caleb Wherry
//
/////////////////////////////

// Include Guard:
#ifndef BOGO_SORT_H
#define BOGO_SORT_H

// Forward Declared Dependencies:
//

// Local Include Dependencies:
//

// Compiler Include Dependencies:
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>

template <typename T>
class BogoSort {

	private:
		std::vector<T> list;

	public:
        BogoSort();
        
        BogoSort(std::vector<T> inList);

		int sort();

        void print();
};

template <typename T>
BogoSort<T>::BogoSort()
{
    list = {};
}

template <typename T>
BogoSort<T>::BogoSort(std::vector<T> inList)
{
    list = inList;
};

template <typename T>
int BogoSort<T>::sort()
{
    int numIterations = 0;

    srand( time(NULL) );

    while ( !std::is_sorted(list.begin(), list.end()) )
    {
        std::random_shuffle(list.begin(),list.end());

        numIterations++;
    }

    return numIterations;
};

template <typename T>
void BogoSort<T>::print()
{
    for(auto &i : list)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;
};

#endif // BOGO_SORT_H
