/*
 * Node.cpp
 *
 *  Created on: Apr 5, 2017
 *      Author: Kathan Patel
 */
#include <iostream>
#include "Node.h"

using namespace std;

// Static member variables, which are global to the class.
// These variables exist independently from any Node objects.
long Node::constructor_count;
long Node::copy_count;
long Node::destructor_count;

/***** Complete this file. *****/

Node::Node(const long the_value)
{
	value = the_value;
	constructor_count++;
}

Node::Node(const Node& other)
{
	value = other.value;
	copy_count++;
}

Node::~Node()
{
	destructor_count++;
}

bool Node::operator >(const Node& n) const
{
	if (value > n.get_value())
		return true;
	else
		return false;
}

long Node::get_value() const
{ return value;}

long Node::get_constructor_count()
{ return constructor_count;}

long Node::get_copy_count()
{ return copy_count; }

long int Node::get_destructor_count()
{ return destructor_count; }

void Node::reset()
{
	constructor_count = 0;
	copy_count = 0;
	destructor_count = 0;
}
