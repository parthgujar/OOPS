#include "Calculator.h"

using namespace std;

int valid_exp(string st);
int main()
{

	Calculator cal;
	string s;
	double b;

	while(1)
	{
		cout << "expression ? " << endl;
		cin >> s;

		if(s==".")
			return 0;

		b = valid_exp(s);
		if ( b == 0 )
		{
			b = cal.expression(s);
		}
		cout << b;
		cout << "\n";
	}
	return 0;
}


int valid_exp(string st)
{
	int count = 0;
	if (st[0] == '.') return 0;
	for ( int i = 0; i < st.length(); i++)
	{
		if (st[i] == '(')
			count ++;
		else if (st[i] == ')')
			count --;
		else if (st[i] == '.')
			return 0;
	}
	if (count == 0)
	{
		return 0;
	}
	else if ( count > 0 )
	{
		cout << "***** Missing )";
		return 1;
	}
	else
	{
		cout << "***** Unexpected )";
		return -1;
	}
}
