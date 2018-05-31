/*
 * hash.h
 *
 *  Created on: Jun 8, 2017
 *      Author: Kathan Patel
 */

#ifndef HASH_H_
#define HASH_H_

#include <iostream>
#include <string>
using namespace std;

class hash
{
	static const int tablesize = 30;
	struct item{
		string name;
		string drink;
		item* next;
	}* hashtable[tablesize];

	public:
	hash();
	int hashindex(string key);
	void additem(string name, string drink);
	int numbertotalinIndex(int index);
	void printtable();
	void printitemsinIndex(int index);
	void remove(string name);
};




#endif /* HASH_H_ */
