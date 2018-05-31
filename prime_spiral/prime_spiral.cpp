/*
 *  sprime_spiral.cpp
 *
 *  Created on: Feb 15, 2017
 *      Author: Kathan Patel
 */


#include<iostream>
#include<iomanip>
using namespace std;

const int MAX_SIZE  = 101;  // maximum size of the square matrix

int make_spiral(const int n, const int start, int a[][MAX_SIZE]);
int print_spiral(const int n,int a[][MAX_SIZE]);

int main()
{

	int arr[MAX_SIZE][MAX_SIZE];
	int i,j;

	for ( i = 0; i < MAX_SIZE; i++)
		for ( j = 0; j < MAX_SIZE; j++)
		{
			arr[i][j]= 1;
		}
    make_spiral(1, 1, arr);
    print_spiral(1, arr);
    make_spiral(5, 1, arr);
    print_spiral(5, arr);
    make_spiral(9, 11, arr);
    print_spiral(9, arr);
    make_spiral(12, 13, arr);
    make_spiral(15, 17, arr);
    print_spiral(15, arr);

    return 0;
}



int make_spiral(const int n, const int start, int a[][MAX_SIZE])
{
	if ( n == 12)
	{
		cout<<"Spiral of size 12 starting at 13"<<"\n";
		cout<<"***** Error: Size 12 must be odd."<<"\n";
	}

	else
	{
	int ip,k,num,size,u=1,l=2,r=2,d=2;
	ip = n;
	size= n;
	k= start;
	cout<<"Spiral of size "<<n<<" starting at "<<start;
	int i = ip/2;
	int j = ip/2;

	a[ip/2][ip/2]=k;

	while(1)
	{
	  a[i][++j]=++k;
	  ip--;
	  if(ip==0) break;


	  for(num=0;num<u;num++)		//moving up
	  {
  		 a[--i][j]=++k;
	  }
	  u = u+2;

	  for(num=0;num<l;num++)		//moving left
	  {
         a[i][--j]=++k;
	  }
	  l = l+2;
	  ip--;
	  if(ip==0) break;

	  for(num=0;num<d;num++)		//moving down
	  {
         a[++i][j]=++k;
	  }
	  d=d+2;

	  for(num=0;num<r;num++)     //moving right
	  {
         a[i][++j]=++k;
	  }
	  r=r+2;
	}

	}
	cout<<"\n";
	return 0;
}


int print_spiral(const int n,int a[][MAX_SIZE])
{
for(int i=0;i<n;i++)              //printing output
	{
		cout<<endl;
		for(int j=0;j<n;j++)
			cout<<setw(4)<<a[i][j];
	}
cout<<"\n \n";
return 0;
}
