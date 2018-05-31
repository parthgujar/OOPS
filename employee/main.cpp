/*
 * main.cpp
 *
 *  Created on: Mar 6, 2017
 *      Author: Kathan Patel
 */
#include <iostream>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include <fstream>
#include "Employee.h"

using namespace std;

void execute(string s); // to copy the string to stringstream 'variable'
int search(string s); // to search for teh ID in the list vector
int sort (Employee& e); // to find and sort the employee records using @param ID
void print_all( vector<Employee>& list); // prints the final list of teh employee RECORDS
void print_stats(vector<Employee>& list); // calculating and printing the statistics of the salary
const string INPUT_FILE_NAME = "Employee.txt";
vector<Employee> list; // globalizing the vector of objects

int main()
{
    ifstream input;
    string str;
    string id; // temporary storing teh ID as string
    input.open(INPUT_FILE_NAME.c_str()); // opens teh file
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }
    char command; // command to detect what operation to perform
	int index = -2;

	// perform this fucntion until  the end of file
    while (!input.eof())
    {
    	input >> command;
    	switch(command) // using switch casse to perform appropriate operations
    	{
    	case '+': 									// this operations for '+' command
    		cout << command << " ";
    		input >> ws;
    		getline ( input, str, ',');
    		id = str.substr (0,3); // stores teh ID as string
    		getline ( input, str); // takes rest ofthe line as input to 'str'
    		index = search(id); // choosing what operatoin to perform on combination ID and command
    		cout << id << ": ";
    		if ( index == -2)
    		{
    		execute(id +","+ str);
    		cout << "\n";
    		}
    		else if ( index >= 0 )
    		{
    			cout << "*** Duplicate ID ***";
    			cout << "\n";
    		}
    		break;
    	case '%':									// this operations for '%' command
    		cout << command << " ";
    		input >> ws;
    		getline ( input,str, ',');
    		cout << str << ": ";
    		cout << "*** Invalid command ***";
    		cout << "\n";
    		break;
    	case '?':									// this operations for '?' command
    		cout << command << " ";
    		input >> ws;
    		getline ( input,str);
    		id = str.substr(0,3);
    		index = search(id);
    		cout << id << ": ";
    		if ( index >= 0)
    		{
    			cout << list[index];
    			cout << "\n";
    		}
    		else if ( index == -2)
    		{
    			cout << "*** ID not found ***";
        		cout << "\n";
    		}

    		break;
    	case '-':									// this operations for '-' command
    		cout << command << " ";
    		input >> ws;
    		getline ( input,str);
    		id = str.substr(0,3);
    		index = search(id);
    		cout << id << ": ";
    		if ( index >= 0)
    		{
    			cout << list[index];
    			list.erase(list.begin()+index);
    		}
    		else if ( index == -2)
    		{
    			cout << "*** ID not found ***";
    		}
    		cout << "\n";
    	}
    }
    print_all( list);
    print_stats( list);
    return 0;
}


int search (string s)
{
	int id = atoi (s.c_str());
	for ( int i = 0; i < list.size(); i++)
	{
		if (id == (list[i]).getid())
		{
			return i;
		}
	}
	return -2;
}

int sort (Employee& e)
{
	for ( int i = 0; i < list.size(); i++)
	{
		if ( list[i].getid() > e.getid())
		{
			list.insert ( list.begin() + i, e);
			return i;
		}
	}
	list.push_back(e);
	return -1;
}

void print_all( vector<Employee>& list)
{
	cout << endl << "All Employees" << endl << "-------------" << endl;
	for (int i =0; i < list.size(); i++)
	{
		cout << list[i];
		cout << "\n";
	}
}

void print_stats(vector<Employee>& list)
{
	 double min, max, temp, total;
	 min = list[0].getsalary();
	 max = list[0].getsalary();
	 total= list[0].getsalary();
	 int i = 1;
	 while (i < list.size())
	 {
		 temp = list[i].getsalary();
		 total = total + temp;
		 if ( temp < min )
		 {min = temp;}
		 else if ( temp > min )
		 {
			 if ( temp > max)
			 {max = temp;}
			 else
			 {}
		 }
		 i++;
	 }
	 cout << endl;
	 cout << "Statistics" << endl;
	 cout << "----------" << endl;
	 cout.setf(ios::fixed);
	 cout.precision(2);
	 cout << "Minimum salary = $" << setw(9) << min << endl;
	 cout << "Maximum salary = $" << setw(9) << max << endl;
	 cout << "Average salary = $" << setw(9) << total/list.size()
	         << endl;

}

void execute(string s)
{
	Employee e;				// create object 'e' of employee class
	stringstream kp(s);		// assigning string 's' to string 'kp'
	kp >> e;				// calling insertion '>>' operator
	sort(e);				// finding and sorting teh employee records
	cout << e;				// calling extraction '<<' operator
}
