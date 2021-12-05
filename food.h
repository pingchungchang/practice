##include<cstdio>
#include<iostream>
#include<vector>
#include<string>
using namespace std;


class food
{
public:
    virtual int price();
};

class Coke: public food
{
public:
    int price();
    }
};

class Blacktea: public food
{
public:
    int price();
    }
};

class Popcorn: public food
{
public:
    int price();
    }
};

class Churros: public food
{
public:
    int price();
    }
};
