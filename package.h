#include <iostream>
#include <string>
#include <cinema.h>
#include <movie.h>
using namespace std;

class package{
public:
    cinema::cinema* c;
    movie::movie* m;
    int time;
    package(cinema::cinema* a,movie::movie* b,int t);
};
