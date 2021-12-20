#include <vector>
#include <string>
#include "others.h"

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
    movie();
    bool Add_Movie(cinema*);
    bool Delete_Movie(movie*);
};

