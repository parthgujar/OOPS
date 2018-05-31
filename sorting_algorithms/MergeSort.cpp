#include <string>
#include "MergeSort.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
MergeSort::MergeSort(string name) : ListSorter(name) {}

/**
 * Destructor.
 */
MergeSort::~MergeSort() {}

/**
 * Run the mergesort algorithm.
 * @throws an exception if an error occurred.
 */
void MergeSort::run_sort_algorithm()
    throw (string)
{
    // Defensive programming: Make sure we end up
    // with the same size list after sorting.
    int size_before = data.get_size();

//    mergesort(data);

    // Check sizes.
    int size_after = data.get_size();
    if (size_before != size_after)
    {
        string message = "***** Size mismatch: before " +
                         to_string(size_before) + ", size after " +
                         to_string(size_after);
        throw message;
    }
}

/**
 * The mergesort algorithm recursively splits and merges data lists.
 * @param list the list of data to sort.
 */
void MergeSort::mergesort(LinkedList& list)
{
    /***** Complete this member function. *****/
	LinkedList f,l;
	if(list.get_head()!=nullptr)
	{
		move_count+=list.get_size();
		list.split(f,l);

		if(f.get_head()!=nullptr)
		{
			mergesort(f);
		}
		if(l.get_head()!=nullptr)
		{
			mergesort(l);
		}
		merge(list,f,l);
	}
}

/**
 * Merge two sublists back into a single list.
 * @param list the merged list.
 * @param sublist1 the first sublist.
 * @param sublist2 the second sublist.
 */
void MergeSort::merge(LinkedList& list, LinkedList& p1, LinkedList& p2)
{
    /***** Complete this member function. *****/
if (p1.get_head() == nullptr)
		{
			list.concatenate(p2);
		}
		else if(p2.get_head()!=nullptr){
			list.concatenate(p1);
		}
		else{

			while(p1.get_head() != nullptr && p2.get_head() != nullptr){
			if(p1.get_head()->element.get_value()<=p2.get_head()->element.get_value())
			{
				compare_count++;
				move_count++;
				list.add(p1.remove_head());
			}
			else
			{
				compare_count++;
				move_count++;
				list.add(p2.remove_head());
			}
			}
			merge(list,p1,p2);

		}

}

/**
 * Clear the data.
 */
void MergeSort::clear() { data.clear(); }
