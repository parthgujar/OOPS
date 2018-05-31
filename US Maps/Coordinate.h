
#ifndef COORDINATE_H_
#define COORDINATE_H_

#include <iostream>
#include <string>
using namespace std;

/**
 * A geographic coordinate.
 */
class Coordinate
{
public:

    /***** Complete this file. *****/
	Coordinate();
	double get_latitude() const;
	double get_longitude() const;
	void set_latitude(double lati);
	void set_longitude(double longi);

    // Overloaded input stream extraction operator.
    friend istream& operator >>(istream& ins, Coordinate& coordinate);

    // Constants for this app's input data.
    static const double MAX_LATITUDE;
    static const double MIN_LONGITUDE;

private:
    double latitude;
    double longitude;
};

#endif /* COORDINATE_H_ */
