/*
 * City.cpp
 *
 *  Created on: Mar 20, 2017
 *      Author: Kathan Patel
 */
#include "City.h"
#include <stdlib.h>

    /***** Complete this file. *****/
City::City()
{
	name = "";
	state = "";
}

Coordinate City::get_coordinate() const
{
	return this->coordinate;
}


string City::get_name() const
{
	return name;
}

string City::get_state() const
{
	return state;
}

istream& operator >>(istream& ins, City& city)
{
	string s;
	double x;
	getline (ins,	s,	',');
	city.name = s;
	getline (ins,	s,	',');
	city.state = s;
	getline (ins,	s,	',');
	x= atof(s.c_str());
	city.coordinate.set_latitude(x);
	getline (ins,	s);
	x= atof(s.c_str());
	city.coordinate.set_longitude(x);
	return ins;
}

ostream& operator <<(ostream& outs, const City& city)
{
	outs << "*" << city.name << " " << city.state;
	return outs;
}
