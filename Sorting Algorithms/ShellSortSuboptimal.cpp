#include "ShellSortSuboptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortSuboptimal::ShellSortSuboptimal(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortSuboptimal::~ShellSortSuboptimal() {}

/**
 * Run the suboptimal shellsort algorithm.
 * @throws an exception if an error occurred.
 */

/* http://www.cplusplus.com/forum/general/123961/ */
void ShellSortSuboptimal::run_sort_algorithm() throw (string)
{
    /***** Complete this member function. *****/
	int gap, i, j;
	Element temp;
	for (gap = size/2; gap > 0; gap /= 2)
	{
		for (i = gap; i < size; i++)
		{
			for (j=i-gap; j>=0 && data[j]>data[j+gap]; j-=gap)
			{
				compare_count++;
				temp = data[j];
				data[j] = data[j+gap];
				data[j+gap] = temp;
			}
		}
	}
}
