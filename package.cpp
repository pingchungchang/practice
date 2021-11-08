#include <iostream>
#include <cinema.h>
#include <movie.h>
#include <package.h>

using namespace std;

class package{
    cinema::cinema* c;
    movie::movie* m;
    int time;
    package(cinema::cinema* a,movie::movie* b,int t){
        c = a;
        m = b;
        time = t;
    }
};
