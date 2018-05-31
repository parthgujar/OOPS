
#ifndef NODE_H_
#define NODE_H_

#include "City.h"
#include "Coordinate.h"

/**
 * A linked list node.
 */
class Node
{
public:

    /***** Complete this file. *****/
	Node(Coordinate& k);
	Node(City& c);
	int get_row() const;
	int get_col() const;
	string get_name() const;
	string get_state() const;

    // Public pointer to the next node in the list.
    Node *next;

    // Overloaded > operator.
    bool operator >(const Node& other);
//    bool operator ==(const Node& other);

    // Overloaded stream output insertion operator.
    friend ostream& operator <<(ostream& outs, const Node& node);

private:
    string name;   // city name,  or the empty string for a border location
    string state;  // city state, or the empty string for a border location
    int row;       // print row
    int col;       // print column

    void convert_coordinate(const Coordinate& coordinate);
};

#endif /* NODE_H_ */
