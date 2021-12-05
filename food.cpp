#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
using namespace std;


class food
{
public:
    virtual int price() = 0;
};

class Coke: public food
{
public:
    int price() {
        return 25;
    }
};

class Blacktea: public food
{
public:
    int price() {
        return 30;
    }
};

class Popcorn: public food
{
public:
    int price() {
        return 50;
    }
};
class Churros: public food
{
public:
    int price() {
        return 50;
    }
};
