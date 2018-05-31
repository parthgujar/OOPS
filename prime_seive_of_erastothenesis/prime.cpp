//#include<iostream>
//#include<iomanip>
//const int MAX_NUMBER = 1000;  // maximum possible prime number
//const int ROW_SIZE = 20; // maximmum number of elements iin a ROW
//using namespace std;
//
//int compute_primes(int arr[]);
//int print_primes(int arr[]);
//
//int main()
//{
//	int arr[MAX_NUMBER];
//	int m=1;
//	for (int i=0; i<MAX_NUMBER-1; ++i)
//	{
//		arr[i]=m;
//		m++;
//	}
//	compute_primes(arr); /*calling this function to COMPUTE PRIME numbers*/
//	print_primes(arr); 	 /*calling this function to PRIT PRIME numbers*/
//	cout<<"\n \nDone!";
//	return 0;
//}
//
//int compute_primes(int arr[])
//{
//	for (int i = 2; i < MAX_NUMBER-1; ++i) /*this loop indexes to the NEXT number in array*/
//	{
//		for( int j = i * i; j < MAX_NUMBER-1; j+=i) /*this loop sets the value of MULTIPLES of a number to '1' */
//		{
//			arr[j - 1]= 1;
//		}
//	}
//	return 0;
//}
//
//int print_primes(int arr[])
//{
//	int count=0;
//	for (int x = 0; x < MAX_NUMBER-2; ++x)
//	{
//		if(arr[x] != 1) /*this condition checks the value of teh number in array and if its '1' then is not printed*/
//		{
//			cout<<setw(4)<<arr[x];
//			count++;
//			if( count % ROW_SIZE == 0)
//				cout<<"\n";
//		}
//	}
//	return 0;
//}
//






#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int MAX_NUMBER = 1000;  // maximum possible prime number
const int ROW_SIZE   = 20;    // row size for printing

void compute_primes(int prime[]);
void print_primes(int prime[]);
int x=0;

int main()
{
    int array[MAX_NUMBER]={0};
    compute_primes(array);
    print_primes(array);
}


void compute_primes(int prime[])
{
	int k=0, N=0;
	int num[MAX_NUMBER]={0};
	for (int a=0;a<MAX_NUMBER;a++){
		num[a]=N++;
	}
	for (int i=0;i<MAX_NUMBER;i++)
	{
		if (num[i] != 0 && num[i] != 1) {
			for (k = 2; k < MAX_NUMBER / i; k++)
				num[k * i] = 0;
			prime[x] = num[i];
			x++;
		}

	}

	return ;
}

void print_primes(int prime[])
{
    for(int k=0;k<ROW_SIZE;k++)
    {
        for(int i=0;i<x;i++)
            cout<<right<<setw(3)<<prime[k];
    }
    cout<<"\n";

}
