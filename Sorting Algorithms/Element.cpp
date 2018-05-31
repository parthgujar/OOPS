/*
 * Element.cpp
 *
 *  Created on: Apr 24, 2017
 *      Author: Kathan Patel
 */
#include <iostream>
#include "Element.h"

using namespace std;

/***** Complete this class. *****/

long Element::copy_count;
long Element::destructor_count;

/**
 * Default constructor.
 */
Element::Element() : value(0) {}

/**
 * Constructor.
 * @param val the element's value.
 */
Element::Element(long val) : value(val) {}

/**
 * Copy constructor.
 * @param other the other element to be copied.
 */
Element::Element(const Element& other)
{
    /***** Complete this class. *****/
	this->value = other.value;
	copy_count++;
}

/**
 * Destructor.
 */
Element::~Element()
{
    /***** Complete this class. *****/
	destructor_count++;
}

/**
 * Getter.
 * @return the value.
 */
long Element::get_value() const { return value; }


bool Element::operator>(const Element& other) const
{
	return (value > other.value);
}

bool Element::operator<(const Element& other) const
{
	return (this->value < other.value);
}

bool Element::operator<=(const Element& other)const
{
	return (this->value <= other.value);
}

long Element::get_copy_count()
{
	return copy_count;
}

long Element::get_destructor_count()
{
	return destructor_count;
}

void Element::reset()
{
	copy_count= 0;
	destructor_count= 0;
}

ostream& operator<< (ostream& out, const Element& b)
{
	cout << b.value <<endl;
}
