/*
 * Employee.cpp
 *
 *  Created on: Mar 6, 2017
 *      Author: Kathan Patel
 */
#include "Employee.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

Employee::Employee()
{
	id = 0;
	last = "";
	first = "";
	salary = 0;
}

istream& operator >>(istream& outs, Employee& r)
{
	string s;
	getline(outs, s, ',');
	r.id = atoi(s.c_str());
	getline(outs, s, ',');
	r.last = s;
	getline(outs, s, ',');
	r.first = s;
	getline(outs, s);
	r.salary = atof(s.c_str());
	return outs;
}

ostream& operator <<(ostream& outs, const Employee& r)
{
	outs //<< r.id <<": "
		 << "Employee{ID=" << r.id << ", "
		 << "last=" << r.last << ", "
		 << "first=" << r.first << ", "
		 << "salary=" << r.salary << "}";
	return outs;
}

int Employee::getid()
{
	return id;
}

double Employee::getsalary()
{
	return salary;
}



