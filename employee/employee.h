/*
 * Employee.h
 *
 *  Created on: Mar 6, 2017
 *      Author: Kathan Patel
 */

#ifndef Employee_H_
#define Employee_H_
#include <string>

using namespace std;
class Employee
{
public:
	Employee();
	friend ostream& operator <<(ostream& outs, const Employee& r);
	friend istream& operator >>(istream& outs, Employee& r);
	int getid();
	double getsalary();
private:
	int id;
	string last;
	string first;
	double salary;
};

#endif /* Employee_H_ */
