#include <iostream>
#include <string>
#include <package.h>
#include <dispatcher.h>
using namespace std;

class customer{
public:
    string name;
    string id;
    int age;
    dispatcher::dispatcher* dspatcher;
    customer(string n,string i,int a);
    package::package* Search_By_Time(int time);
    package::package* Search_By_Type(string cinema_type);
    package::package* Search_By_Cinema(int cinema_type);
    package::package* Search_By_Movie(string movie_name);
};
