/*
 * Calculator.h
 *
 *  Created on: Apr 12, 2017
 *      Author: Kathan Patel
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class Calculator
{
public:
	double expression (string s);
	double term(string s);
	double factor(string s);
};


#endif /* CALCULATOR_H_ */
