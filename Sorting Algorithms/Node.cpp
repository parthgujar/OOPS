#include "Node.h"
#include "Element.h"

/***** Complete this class. *****/
Node::Node()
{
	next = nullptr;
	element = NULL;
}

Node::Node(const Element& other)
{
	element = other;
	next = nullptr;
}
