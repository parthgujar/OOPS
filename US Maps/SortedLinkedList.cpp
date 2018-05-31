
#include "SortedLinkedList.h"

    /***** Complete this file. *****/

/**
 * Insert a new node into the sorted linked list.
 * Uses the overloaded Node::operator > to compare nodes.
 * @param node points to the node to insert.
 */

SortedLinkedList::SortedLinkedList()
{
	head = NULL;
}

SortedLinkedList::~SortedLinkedList()
{
	Node *p = head;
	while (p != NULL)
	{
//		cout << "destructor called....." << endl;
		Node * temp;
		temp = p;
		p = p->next;
		delete temp;
	}
}



void SortedLinkedList::insert(Node *node)
{
	Node *NodePtr=head;
	Node *prev=NULL;

	if(head==NULL)
	{
		head = node;
	}
	else
	{
		while(NodePtr!=NULL)
		{
			if ( node->get_row()==NodePtr->get_row() && node->get_col()==NodePtr->get_col() )
			{
				if (node->get_name().length() > 0 )
				{
					prev->next = node;
					node->next = NodePtr->next;
					return;
				}
				return;
			}
			else
			{
				if(*node > *NodePtr)
				{
					if(NodePtr->next!=NULL)
					{
						prev=NodePtr;
						NodePtr=NodePtr->next;
					}
					else
					{
						NodePtr->next=node;
						return;
					}
				}
				else
				{
					node->next=NodePtr;
					if(prev==NULL)
					{
						head=node;
						return;
					}
					else
					{
						prev->next=node;
						return;
					}
				}
			}
		}
	}
}

ostream& operator <<(ostream& outs, const SortedLinkedList& list)
{
    //***** Complete this function.
	Node * p;
	p= list.head;
	int r = p->get_row();
	int c = 0;
	int count=0;
	while (p != NULL)
	{
		if ( r == p->get_row())
		{
			if ( c < p->get_col() )
			{
				cout << " ";
				c++;
			}
			else if ( c == p->get_col() )
			{
				cout << *p;
				if ( p->get_name().length() > 0)
				{
					c += p->get_name().length() + p->get_state().length() + 2;
				}
				else
				{
					c++;
				}
				p= p->next;
			}
			else
			{
				c++;
				p= p->next;
			}
		}
		else
		{
			c= 0;
			r++;
			cout << endl;
		}
	}
	return outs;
}
