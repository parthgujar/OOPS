#include "ShellSortOptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortOptimal::ShellSortOptimal(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortOptimal::~ShellSortOptimal() {}

/**
 * Run the optimal shellsort algorithm.
 * According to Don Knuth:
 * h = 3*i + 1 for i = 0, 1, 2, ... used in reverse.
 * @throws an exception if an error occurred.
 */
void ShellSortOptimal::run_sort_algorithm() throw (string)
{
    /***** Complete this member function. *****/
/* https://github.com/xtaci/algorithms/blob/master/include/shell_sort.h */
	int h = 1;
	while (h < size / 3)
	{
		h = 3 * h + 1; // 1, 4, 13, 40, 121, ...
	}
	while (h >= 1)
	{
		for (int i = h; i < size; i++)
		{
			Element cur = data[i];
			compare_count++;
			int j = i - h;
			while (j >= 0 && data[j] > cur)
			{

				move_count++;
				data[j + h] = data[j];
				j = j - h;
			}
			data[j + h] = cur;
		}
		h = h / 3;
	}
}
