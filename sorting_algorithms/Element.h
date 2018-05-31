#ifndef DATA_H_
#define DATA_H_

#include <iostream>
using namespace std;

/**
 * The class for the data elements that will be sorted.
 */
class Element
{
public:
    Element();
    Element(long val);
    Element(const Element& other);
    virtual ~Element();

    long get_value() const;

    bool operator>(const Element& other) const;
    bool operator<(const Element& other)const;
    bool operator<=(const Element& other)const;
    long static get_copy_count();
    long static get_destructor_count();
    static void  reset();
    friend ostream& operator<< (ostream& out, const Element& b);
    /***** Complete this class. *****/

private:
    long value;
    static long copy_count;
    static long destructor_count;
};

#endif /* DATA_H_ */
