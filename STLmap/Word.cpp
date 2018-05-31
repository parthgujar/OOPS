/*
 * Word.cpp
 *
 *  Created on: Apr 19, 2017
 *      Author: Kathan Patel
 */
#include <string>
#include "Word.h"
using namespace std;

/***** Modify this file as needed. *****/

Word::Word() : text(""), count(0)
{
}

Word::Word(string text) : text(text), count(1)
{
}

Word::~Word()
{
}

string Word::get_text()  const
{
	return text;
}

int    Word::get_count() const
{
	return count;
}

void   Word::increment_count()
{
	count++;
}

bool Word::operator !=(const Word& other) const
{
	return (this->text!=other.text) && (this->count != other.count);
}
