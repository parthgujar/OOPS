#include "Calculator.h"

using namespace std;

double Calculator::expression(string s)
{
	Calculator cal;
	double result;
	stringstream str(s);
	string st, st1, st2;
	int pos;
	char temp;

	if (s[0] == '(')
	{
		for ( int i = 0; s[i] == '('; i++)
		{
			str >> temp;
		}
		getline(str,st,')');
		cal.term(st);
		cout << st<< endl;
		result = expression(st);
	}
	else if ( s[0] == '=')
	{
		return 0;
	}
	else
	{
		getline(str, st, '=');
		result = cal.term(st);
	}
	return result;
}

double Calculator::term(string s)
{
	Calculator cal;
	double result = 0.0;
	stringstream str(s);
	double a, b;
	char op;
	str >> a >> op >> b;
	if (op == '*' || op =='/')
	{
		result = cal.factor(s);
		return result;
	}
	else if ( op == '+')
	{
		return a+b;
	}
	else if (op == '-')
	{
		return a-b;
	}
	return result;
}

double Calculator::factor(string s)
{
	Calculator cal;
	double result = 0.00;
	stringstream str(s);
	double a , b;
	char op;
	str >> a >> op >> b;
	if ( op == '*')
	{
		return a*b;
	}
	else if (op == '/')
	{
		return a/b;
	}
	return result;
}
