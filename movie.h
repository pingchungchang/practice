#include <vector>
#include <string>
#include "others.h"

#ifndef movie_defined
#define movie_defined 1

using namespace std;

class movie
{
public:
    string name;
    movietime duration;
    string description;
    vector<pair<cinema*, movietime>> time_based_table;
    int price_factor;
    vector<package*> Search(cinema*, movietime);
    vector<pair<cinema*, movietime>> Get_Table();
    movie(){}
    movie(string name1, movietime duration1, string description1, int price_factor1);
    bool Add_Movie(cinema*);
    bool Delete_Movie(movie*);
};

#endif