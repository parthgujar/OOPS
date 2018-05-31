	#include "InsertionSort.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
InsertionSort::InsertionSort(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
InsertionSort::~InsertionSort() {}

/**
 * Run the insertion sort algorithm.
 * @throws an exception if an error occurred.
 */
void InsertionSort::run_sort_algorithm() throw (string)
{
/*
	int sizem1 = size - 1;
   for ( int i = 1; i < sizem1; i++)
   {
	   Element key = data[i];
	   int j = i-1;
	   while (j >= 0 && data[j] > key)
	   {
		   compare_count++;
		   data[j+1] = data[j];
		   j = j-1;
		   move_count++;
	   }
	   data[j+1] = key;
	   move_count++;
   }
*/
	  int j;
	  Element val;
	  //iterate through entire list
	  for(int i = 1; i < size; i++)
	  {
	     val = data[i];
	     j = i;
	     while(j > 0 && data[j-1] > val)
	     {
	    	 compare_count++;
	         data[j] = data[j - 1];
	         j = j - 1;
	     }
	     move_count++;
	     data[j] = val;
	  }
	}
