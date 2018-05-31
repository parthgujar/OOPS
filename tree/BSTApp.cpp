/**
 * Test the binary search tree and AVL tree implementations.
 * The AVL tree is derived from the binary search tree.
 *
 * Create a tree of height 5 and then repeatedly
 * delete the root. The AVL tree should remain balanced
 * after each node insertion and deletion.
 */

#include <iostream>
#include <vector>
#include <time.h>
#include <ctime>
#include <chrono>
#include <iomanip>
/**
 * Test the binary search tree and AVL tree implementations.
 * The AVL tree is derived from the binary search tree.
 *
 * Create a tree of height 5 and then repeatedly
 * delete the root. The AVL tree should remain balanced
 * after each node insertion and deletion.
 */

#include "BinarySearchTree.h"
#include "AvlTree.h"
#include "BinaryNode.h"

using namespace std;
using namespace std::chrono;
string commafy(long n);
void tree_operations(double counts[][10], BinarySearchTree& tr);
void print_results(double bst_cnt[][10],double avl_cnt[][10]);


int main()
{
	srand(0);
	double bst_counts[6][10];
	double avl_counts[6][10];
	BinarySearchTree bst;
	AvlTree avl;
	tree_operations(bst_counts, bst);
	tree_operations(avl_counts, avl);
	print_results(bst_counts,avl_counts);

	return 0;
}


void tree_operations(double cnt[][10], BinarySearchTree& tr)
{

	for(int i=1;i<=10;i++)
	{
		tr.clear();
		tr.setRoot();
		int size = 10000*i;

		BinaryNode::reset();
		int j=0;
		steady_clock::time_point start_time = steady_clock::now();
		while(j<size){
			int elem = rand()%size;
			tr.insert(elem);
			j++;
		}
		steady_clock::time_point end_time = steady_clock::now();
		long elapsed_time = duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
		cnt[0][i-1]=BinaryNode::probe_count;
		cnt[1][i-1]=BinaryNode::compare_count;
		cnt[2][i-1]=elapsed_time;

		BinaryNode::reset();

		j=0;
		start_time = steady_clock::now();
		while(j<size){
			int elem = rand()%size;
			tr.contains(elem);
			j++;
		}

		end_time = steady_clock::now();
		elapsed_time = duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
		cnt[3][i-1]=BinaryNode::probe_count;
		cnt[4][i-1]=BinaryNode::compare_count;
		cnt[5][i-1]=elapsed_time;

	}



}


void print_results(double bst_cnt[][10],double avl_cnt[][10]){

	for(int i=0;i<6;i++){

		cout<<"   "<<commafy(10000*(i+1));
		for(int j=0;j<10;j++){
			cout<<"    "<<bst_cnt[i][j]<<"    "<<avl_cnt[i][j]<<"||";
		}
		cout<<endl;
	}

}


/**
 * Convert a number to a string with commas.
 * @param n the number.
 */
string commafy(long n)
{
    string str = to_string(n);
    int pos = str.length() - 3;

    while (pos > 0)
    {
        str.insert(pos, ",");
        pos -= 3;
    }

    return str;
}
