/**
 * A node of a binary tree.
 */

#ifndef BINARY_NODE_H
#define BINARY_NODE_H

class BinaryNode
{
public:
    BinaryNode(const int data);
    BinaryNode(const int data, BinaryNode *left, BinaryNode *right);
    virtual ~BinaryNode();
	BinaryNode* &get_left();
    BinaryNode* &get_right();

    int data;
    int height;  // node height

    BinaryNode *left;
    BinaryNode *right;
	int get_data();

	static void reset();
    static int probe_count;
    static int compare_count;
};


#endif // BINARY_TREE_PRINTER_H
