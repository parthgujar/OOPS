#include "hash.h"
using namespace std;

hash::hash()
{
	for (int i = 0; i < tablesize; i++)
	{
		hashtable[i] = new item;
		hashtable[i]->name = "base";
		hashtable[i]->drink = "base";
		hashtable[i]->next = NULL;
	}
}

int hash::hashindex(string key)
{
	int hash = 0;
	for (int i = 0; i < key.length(); i++)
	{
		hash = hash + (int)key[i];
	}
	hash *= 13;
	return hash % tablesize;
}

void hash::additem(string name, string drink)
{
	int index = hashindex(name);

	if (hashtable[index]->name == "base")
	{
		hashtable[index]->name = name;
		hashtable[index]->drink = drink;
	}
	else
	{
		item* ptr = hashtable[index];
		item* temp = new item;
		temp->name = name;
		temp->drink = drink;
		temp->next = NULL;
		while(ptr->next != NULL) ptr=ptr->next;
		ptr->next = temp;
	}
}

int hash::numbertotalinIndex(int index)
{
	int count = 0;

	if (hashtable[index]->name == "base") return count;

	count ++;
	item* ptr = hashtable[index];
	while(ptr->next != NULL)
	{
		count ++;
		ptr= ptr->next;
	}
	return count;
}

void hash::printtable()
{
	for (int i = 0; i < tablesize; i++)
	{
		cout << "--------------->>>>>>>>> \n index: " << i << endl;
		cout << hashtable[i]->name << endl;
		cout << hashtable[i]->drink<< endl;
		cout << "NUMBER OF ITEMS= " << numbertotalinIndex(i) << endl ;
		if (numbertotalinIndex(i) > 1) printitemsinIndex(i);
		cout << "---------------->>>>>>>> \n";
	}
}

void hash::printitemsinIndex(int index)
{
	item* ptr = hashtable[index];
	ptr = ptr->next;

	while(ptr != NULL)
	{
		cout << "-----------------" << endl;
		cout << ptr->name << endl;
		cout << ptr->drink<< endl;
		cout << "-----------------" << endl;
		ptr = ptr->next;
	}
}

void hash::remove(string name)
{
	int index = hashindex(name);
	item *temp = hashtable[index],
		 *next;

	// case-1: EMPTY bucket
	if(temp->name == "base" || temp->drink == "base")
	{
		cout << name << " was not found in this TABLE" << endl;
	}

	// case-2: NAME at the top of the table annd the only one in list
	else if (temp->name == name && temp->next == NULL)
	{
		temp->name = "base";
		temp->drink = "base";
	}

	// case-3: NAME at the top and other VALUES are there also
	else if (temp->name == name)
	{
		temp = temp->next;
		delete temp;
	}

	// case-4: NAME not at the top in between first and last (or last)
	else
	{
		next = temp->next;
		while( next != NULL && next->name != name)
		{
			temp = next;
			next = next->next;
		}

		// NAME between FIRST and LAST
		if (next->name == name)
		{
			temp->next = next->next;
			delete next;
		}

		// NAME at LAST
		else
		{
			cout << name << " was not found in the TABLE" << endl;
		}
	}
}
