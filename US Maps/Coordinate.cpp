
#include "Coordinate.h"
#include <stdlib.h>

/**
 * Maximum latitude and minimum longitude for this app's input data.
 */
const double Coordinate::MAX_LATITUDE  =   49.373112;
const double Coordinate::MIN_LONGITUDE = -124.769867;

    /***** Complete this file. *****/

Coordinate::Coordinate()
{
	latitude = 0;
	longitude = 0;
}


istream& operator >>(istream& ins, Coordinate& coordinate)
{
	//ins >> coordinate.latitude >> temp >> coordinate.longitude;
	string s;
	getline (ins,	s,	',');
	coordinate.latitude = atof(s.c_str());
	getline (ins,	s);
	coordinate.longitude = atof(s.c_str());
	return ins;
}

double Coordinate::get_latitude() const
{
	return latitude;
}

double Coordinate::get_longitude() const
{
	return longitude;
}

void Coordinate::set_latitude(double lati)
{
	latitude = lati;
	return;
}

void Coordinate::set_longitude(double longi)
{
	longitude = longi;
	return;
}
