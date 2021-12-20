#include <vector>
#include <string>
#include"others.h"
using namespace std;


class movie
{
public:
    string name;
    time duration;
    string description;
    vector<pair<cinema*, time>> time_based_table;
    int price_factor;
    vector<package*> Search(cinema*, time){};
    vector<pair<cinema*, time>> Get_Table(){};
    movie();
    bool Add_Movie(cinema*){};
    bool Delete_Movie(movie*) {};
};

