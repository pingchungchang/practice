#include<cstdio>
#include<iostream>
#include<vector>
#include<string>

#ifndef food_defined
#define food_defined 1

using namespace std;

class food
{
public:
    virtual int price() = 0;
};

class Coke: public food
{
public:
    int price();
};

class Blacktea: public food
{
public:
    int price();
};

class Popcorn: public food
{
public:
    int price();
};

class Churros: public food
{
public:
    int price();
};

#endif