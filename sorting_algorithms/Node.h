#ifndef NODE_H_
#define NODE_H_

#include "Element.h"

/**
 * A node of the linked list for mergesort.
 */
class Node
{
public:
    /***** Complete this class. *****/
	Node* next;
	Node();
	Node(const Element&);
	Element element;
private:

};

#endif /* NODE_H_ */
