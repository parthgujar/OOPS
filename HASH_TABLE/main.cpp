#include <iostream>
#include <string>
#include <algorithm>
#include "hash.h"

using namespace std;

int main()
{
	hash table;
	table.additem("kathan", "acai bowl");
	table.additem("badrik", "pb choco");
	table.additem("ravi", "nutty strawberry bowl");
	table.additem("ujjaval", "strwberry surf");
	table.additem("fagun", "razmattaz");
	table.additem("manal", "pitaya");

	table.printtable();
	table.remove("la");
	return 0;
}
