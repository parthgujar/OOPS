#include <iostream>
#include <iomanip>
#include <math.h>
#include <mpir.h>
#include <gmp.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

const int MAX_ITERATIONS = 6;
const int PLACES         = 1000;        // desired decimal places
const int PRECISION      = PLACES + 2;  // +1 for the digit 3 before the decimal

const int BASE       = 10;  // base 10 numbers
const int BIT_COUNT  = 8;   // bits per machine word

const int BLOCK_SIZE = 10;                // print digits in blocks
const int LINE_SIZE  = 100;               // digits to print per line
const int LINE_COUNT = PLACES/LINE_SIZE;  // lines to print
const int GROUP_SIZE = 5;                 // line grouping size

//**** Function declarations here. ****
void print(const mpf_t& pi);

//*
 //* The main.
 //* Set constants, initialize variables, and iterate
 //* to compute pi to the desired number of decimal places.

int main()
{
    mpf_set_default_prec(BIT_COUNT*PRECISION);  // precision in bits


    FILE* stream;

    // declaring the variables(objects)
    mpf_t temp_2;
    mpf_t temp_rt2;
    mpf_t temp_4;
    mpf_t temp_4rt2;
    mpf_t temp_6;
    mpf_t a;
    mpf_t temp_1;
    mpf_t y;
    mpf_t
			temp_numy,
			temp_dnmy;

    mpf_t
			temp_a1,
			temp_a2,
			temp_power;
    mpf_t pi;

    // initializing the declared variables
    mpf_init (temp_rt2);
    mpf_init (temp_4rt2);
    mpf_init (a);
    mpf_init (y);
    mpf_init (temp_numy);
    mpf_init (temp_dnmy);
    mpf_init (temp_power);
    mpf_init (temp_a1);
    mpf_init (temp_a2);
    mpf_init (pi);

    mpf_init_set_ui (temp_2,2); // 2
    mpf_sqrt (temp_rt2, temp_2); // root(2)


    mpf_init_set_ui (temp_4,4); // 4
    mpf_mul (temp_4rt2, temp_rt2, temp_4); // 4 * root(2)
    mpf_init_set_ui (temp_6, 6); //6
    mpf_sub ( a, temp_6, temp_4rt2); // a0 ;


    mpf_init_set_ui (temp_1, 1);
    mpf_sub (y, temp_rt2, temp_1);


    for ( int i = 1; i <= MAX_ITERATIONS; i++)
    {
    	// this part computes the y(i)
    	mpf_pow_ui 		(y, 			y,              4);
    	mpf_ui_sub		(y, 			1,    		y);
    	mpf_sqrt		(y,				y);
    	mpf_sqrt		(y, 			y);
    	mpf_ui_sub		(temp_numy,		1,			y);
    	mpf_add_ui		(temp_dnmy,		y,			1);
    	mpf_div			(y,				temp_numy,		temp_dnmy);

    	// this part computes the a(i)
    	mpf_pow_ui		(temp_a2,		y,				2);
    	mpf_add			(temp_a2,		temp_a2,		y);
    	mpf_add_ui		(temp_a2,		temp_a2,		1);
    	mpf_mul			(temp_a2, 		temp_a2,		y);
    	mpf_pow_ui		(temp_power,	temp_2,			(2*i)+1);
    	mpf_mul			(temp_a2,		temp_a2,		temp_power);

    	mpf_add_ui		(temp_a1,		y,				1);
    	mpf_pow_ui		(temp_a1,		temp_a1,		4);
    	mpf_mul			(temp_a1,		temp_a1,		a);
    	mpf_sub 		(a,				temp_a1,		temp_a2);
    }


//    mpf_out_str(stream, 10,200, a); // print 'PI'
//    cout<<"\n";

    mpf_ui_div 	(pi,	1,	a);
    print(pi);

    return 0;
}


//**** Function definitions. ****
void print(const mpf_t& pi)
{
		char* str=NULL;
		char* output;
		int pos=1,column=0,row=0;
		mp_exp_t exp = 1;
		output = mpf_get_str(str, &exp , 10, PRECISION, pi);

		cout << output[0] << ".";

		while(pos<PLACES)
		{
			cout << output[pos];
			pos++;

			if(pos%10==1)
			{
				cout << " ";
				column++;
			}
			if(column==10)
			{
				cout << endl << "  ";
				column = 0;
				row++;
			}
			if(row==5)
			{
				cout << endl << endl << "  ";
				row = 0;
			}
		}
		cout<<"9";

}
