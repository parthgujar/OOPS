/*
 * Node.cpp
 *
 *  Created on: Mar 20, 2017
 *      Author: Kathan Patel
 */
#include <math.h>
#include "Node.h"

    /***** Complete this file. *****/

/**
 * Convert a coordinate's latitude and longitude
 * into a row and column, respectively, for printing.
 */

Node::Node(City& c)
{
	next = NULL;
	name = c.get_name();
	state = c.get_state();
	convert_coordinate(c.get_coordinate());
}

Node:: Node(Coordinate& k)
{
	name = "";
	state = "";
	convert_coordinate(k);
	next = NULL;
}

int Node::get_row() const
{
	return row;
}

int Node::get_col() const
{
	return col;
}

string Node::get_name() const
{
	return name;
}

string Node::get_state() const
{
	return state;
}

void Node::convert_coordinate(const Coordinate& coordinate)
{
    row = round(2*(Coordinate::MAX_LATITUDE - coordinate.get_latitude()));
    col = round(2*(coordinate.get_longitude() - Coordinate::MIN_LONGITUDE));
}

/**
 * Overloaded > operator used to determine
 * where to insert a node into the linked list.
 * The list is sorted first by row and then by column.
 */
bool Node::operator >(const Node &other)
{
    /***** Complete this function. *****/
	if (this->row == other.row)
	{
		if ( this->col > other.col )
			return 1;
		else if ( this->col < other.col)
			return 0;
	}
	else if (this->row > other.row)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
bool Node::operator ==(const Node& other)
{
	if ( (this->row == other.row) && (this->col == other.col))
		return 1;
}
*/

ostream& operator <<(ostream& outs, const Node& node)
{
	if ( node.name== "")
	{
		cout << '#';
	}
	else
	{
		cout << "*" + node.get_name()+" "+node.get_state();
	}
	return outs;
}
