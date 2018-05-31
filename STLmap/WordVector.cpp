
#include <iostream>
#include <vector>
#include <string>
#include "WordVector.h"

using namespace std;
using namespace std::chrono;

WordVector::WordVector()
{
}

WordVector::~WordVector()
{
}


vector<Word>& WordVector::get_data()
{
	return data;
}

int WordVector::get_count(const string text) const
{
    /***** Complete this member function. *****/
	int index = find(text, 0, data.size()-1);
	if (find(text, 0,data.size()-1))
	{
		return data[index].get_count();
	}
	else
	{
		return -1;
	}
}

void WordVector::insert(const string text)
{
	/***** Complete this member function. *****/
	steady_clock::time_point start_point= steady_clock::now();
	vector<Word>::iterator itr = search(text);
	if (itr != data.end())
	{
		itr->increment_count();
	}
	else
	{
	if(data.size() == 0){
		Word w(text);
		data.push_back(w);
	}
	else
	{
		itr = data.begin();
		Word _word(text);
		while(itr!=data.end() && text > (*itr).get_text() ){
			itr++;
		}

		data.insert(itr,_word);
//	for ( itr = data.begin(); itr != data.end(); itr++)
//		{
//
//			if ((*itr).get_text() > text)
//			{
//				break;
//			}
//		}
//	Word w(text);
//	data.insert(itr,w);
	}
	}
	steady_clock::time_point end_point= steady_clock::now();
	increment_elapsed_time(duration_cast<std::chrono::microseconds>(end_point - start_point).count());
	return;
}

vector<Word>::iterator WordVector::search(const string text)
{
    /***** Complete this member function. *****/
	steady_clock::time_point start_point= steady_clock::now();
	int index = find(text,0,data.size()-1);
	vector<Word>:: iterator it = data.begin();
	if(index != -1)
	{
		it = data.begin()+index;
	}
	else
	{
		it = data.end();
	}
	steady_clock::time_point end_point= steady_clock::now();
	increment_elapsed_time(duration_cast<std::chrono::microseconds>(end_point - start_point).count());
	return it;
}


int WordVector::find(const string text, int low, int high) const
{
    /***** Complete this member function. *****/
    while (low <= high)
    {
        int mid = (low + high)/2;
        if (text == data[mid].get_text())
        {
            return mid;
        }
        else if (text < data[mid].get_text())
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return -1;
}
