/*
 * WordMap.cpp
 *
 *  Created on: Apr 19, 2017
 *      Author: Kathan Patel
 */
#include <iostream>
#include <map>
#include <string>
#include "WordMap.h"

using namespace std;
using namespace std::chrono;

WordMap::WordMap()
{
}

WordMap::~WordMap()
{
}

map<string, Word>& WordMap::get_data()
{
	return data;
}

int WordMap::get_count(const string text) const
{
    /***** Complete this member function. *****/
	map<string, Word>::const_iterator it = data.find(text);
	if (it != data.end())
	{
		return (it->second).get_count();
	}
	else
	{
		return -1;
	}
}

void WordMap::insert(const string text)
{
    /***** Complete this member function. *****/
	steady_clock::time_point start_point= steady_clock::now();
	map<string,Word>::iterator it= data.find(text);
	if (it != data.end())
	{
		it->second.increment_count();
	}
	else
	{
		data[text] = Word(text);
	}
	steady_clock::time_point end_point= steady_clock::now();
	increment_elapsed_time(duration_cast<std::chrono::microseconds>(end_point - start_point).count());
}

map<string, Word>::iterator WordMap::search(const string text)
{
    /***** Complete this member function. *****/
	steady_clock::time_point start_point = steady_clock::now();
	map<string, Word>::iterator it = data.find(text);
	steady_clock::time_point end_point = steady_clock::now();
	increment_elapsed_time(duration_cast<std::chrono::microseconds>(end_point - start_point).count());
	return it;
}
