/*
 * Constitution.cpp
 *
 *  Created on: Apr 19, 2017
 *      Author: Kathan Patel
 */
#include <iostream>
#include <fstream>
#include <iomanip>
//#include <string>
//#include <vector>
//#include <map>
//#include <ctime>
#include <stdlib.h>
#include <sstream>
#include<algorithm>
#include "Word.h"
#include "WordVector.h"
#include "WordMap.h"

using namespace std;

const string INPUT_FILE_NAME = "USConstitution.txt";
const int    MAX_SEARCHES    = 100000;

void time_word_insertions(ifstream& in, WordVector& v, WordMap& m);
void make_spot_checks(WordVector& v, WordMap& m) throw(string);
void check_concordances(WordVector& v, WordMap& m) throw(string);
void time_word_searches(WordVector& v, WordMap& m) throw(string);
string commafy(const long n);

int main()
{
    ifstream in;
    in.open(INPUT_FILE_NAME.c_str());
    if (in.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }
    WordVector v;
    WordMap    m;
    try
    {
        time_word_insertions(in, v, m);
        make_spot_checks(v, m);
        check_concordances(v, m);
        time_word_searches(v, m);
    }
    catch (string& msg)
    {
        cout << endl << endl << "***** " << msg << endl;
    }
    return 0;
}



void time_word_insertions(ifstream& in, WordVector& v, WordMap& m)
{
    string line;
    int line_count = 0;
    int character_count = 0;
    int word_count = 0;
    cout << "Timed insertions ..." << endl;

    // Loop once per line of the input file.
    while (getline(in, line))
    {
        /***** Complete this function. *****/
    	line_count++;
    	stringstream str(line);
    	string w;
    	while(str >> w)
    	{
    		transform(w.begin(),w.end(),w.begin(),::tolower);

    		word_count++;
    		if (character_count == 0)
    			{
    				character_count = w.size();
    			}
    		else
    			character_count += w.size();
        	v.insert(w);
        	m.insert(w);
    	}

    }

    cout << "          Lines: " << setw(6) << commafy(line_count) << endl;
    cout << "     Characters: " << setw(6) << commafy(character_count) << endl;
    cout << "          Words: " << setw(6) << commafy(word_count) << endl;
    cout << endl;
    cout << "    Vector size: " << commafy(v.get_data().size()) << endl;
    cout << "       Map size: " << commafy(m.get_data().size()) << endl;
    cout << endl;
    cout << "    Vector total insertion time: " << setw(8)
         << commafy(v.get_elapsed_time()) << " usec" << endl;
    cout << "       Map total insertion time: " << setw(8)
         << commafy(m.get_elapsed_time()) << " usec" << endl;
}



void make_spot_checks(WordVector& v, WordMap& m) throw(string)
{
    cout << endl << "Spot checks of word counts ..." << endl;

    vector<Word>&      vdata = v.get_data();
    map<string, Word>& mdata = m.get_data();

    vector<string> texts =
    	{"amendment", "article", "ballot", "citizens", "congress",
        "constitution", "democracy", "electors", "government", "law",
        "legislature", "people", "president", "representatives",
        "right", "trust", "united", "vice", "vote"};

    for (string text : texts)
    {
        cout << "    " << text << ": ";
        vector<Word>::iterator      itv = v.search(text);
        map<string, Word>::iterator itm = m.search(text);
        /***** Complete this function. *****/

        cout << "vector:" ;
        if(itv != vdata.end() && itm!=mdata.end())
        	{ cout << itv->get_count();}
        else
        	cout << "not found" ;
        cout << " map:";
        if(itv != vdata.end() && itm!=mdata.end())
        	{
        		cout << (itm->second).get_count() << "\n";
        	}
        else cout <<"not found"<<endl;
    }
}



void check_concordances(WordVector& v, WordMap& m) throw(string)
{
    cout << endl << "Checking concordances ... ";  cout.flush();

    vector<Word>&      vdata = v.get_data();
    map<string, Word>& mdata = m.get_data();

    int vsize = vdata.size();
    int msize = mdata.size();

    if (vsize == 0) throw("Empty vector.");
    if (msize == 0) throw("Empty map.");

    if (vsize != msize ) throw(string("Size mismatch: ") + to_string(vsize) +
                                                 " and " + to_string(msize));

    vector<Word>::iterator      itv = vdata.begin();
    map<string, Word>::iterator itm = mdata.begin();

    while (itv != vdata.end())
    {
        if (*itv != itm->second)
        {
            throw string(string("Data mismatch: ")
                    + itv->get_text() + ":" + to_string(itv->get_count())
                    + " and " + itm->second.get_text() + ":"
                    + to_string(itm->second.get_count()));
        }
        ++itv;
        ++itm;
    }
    cout << "both match!" << endl;
}



void time_word_searches(WordVector& v, WordMap& m) throw(string)
{

	v.reset_elapsed_time();
	m.reset_elapsed_time();

	cout << endl << "Timed searches (" << commafy(MAX_SEARCHES)
                 << " searches) ..." << endl;

    /***** Complete this function. *****/

    for (int i=1; i <= MAX_SEARCHES; i++)
    {
        int index = rand() % v.get_data().size();
        string text = v.get_data()[index].get_text();
        /***** Complete this function. *****/

        v.search(text);
        m.search(text);
    }
    cout << endl;
    cout << "    Vector total search time: " << setw(8)
         << commafy(v.get_elapsed_time()) << " usec" << endl;
    cout << "       Map total search time: " << setw(8)
         << commafy(m.get_elapsed_time()) << " usec" << endl;
}



/**
 * Convert a number to a string with commas.
 * @param n the number.
 */
string commafy(const long n)
{
    string str = to_string(n);
    int pos = str.length() - 3;

    while (pos > 0)
    {
        str.insert(pos, ",");
        pos -= 3;
    }

    return str;
}
