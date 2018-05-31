/*
 * SortedVector.cpp
 *
 *  Created on: Apr 5, 2017
 *      Author: Kathan Patel
 */
#include <iostream>
#include <iterator>
#include "SortedVector.h"

using namespace std;

/**
 * Defaut constructor.
 * Reset the global Node counters.
 */
SortedVector::SortedVector()
{
    Node::reset();
}

/**
 * Destructor.
 * Reset the global Node counters.
 */
SortedVector::~SortedVector()
{
    Node::reset();
}

/**
 * @return the size of the data vector.
 */
int SortedVector::size() const { return data.size(); }

/**
 * Check that the data is sorted.
 * @return true if sorted, false if not.
 */
bool SortedVector::check() const
{
    if (data.size() == 0) return true;

    vector<Node>::const_iterator it = data.begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

/**
 * Insert a new node at the beginning of the data vector.
 * @param value the new node's value.
 */
void SortedVector::prepend(const long value)
{
    /***** Complete this function. *****/
	data.insert(data.begin(), value);
}

/**
 * Append a new node at the end of the data vector.
 * @param value the new node's value.
 */
void SortedVector::append(const long value)
{
    /***** Complete this function. *****/
	data.push_back(value);
}

/**
 * Remove a node.
 * @param index the index of the node to remove.
 */
void SortedVector::remove(const int index)
{
    /***** Complete this function. *****/
//	data.erase(data.begin()+index);
	vector<Node>::iterator it= data.begin();
	advance(it, index);
	data.erase(it);
}

/**
 * Insert a new node into the data vector at the
 * appropriate position to keep the vector sorted.
 */
void SortedVector::insert(const long value)
{
	if (data.size() == 0)
	{
		data.push_back(value);
		return;
	}
	else
	{
		for ( vector<Node>::iterator it = data.begin(); it != data.end(); it++)
		{

			if ((*it).get_value() == value)
				return;
			if ((*it).get_value() > value)
			{
				data.insert(it,value);
				return;
			}

		}
		data.push_back(value);
		return;

	}
    /***** Complete this function. *****/
}

/**
 * Return the data node at the indexed position.
 * @param the index of the node.
 * @return a copy of the data node.
 */
Node SortedVector::at(const int index) const
{
	vector<Node>::const_iterator it= data.begin();
	advance(it, index);
	return *it;
}
