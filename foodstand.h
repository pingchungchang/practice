#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include"food.h"

using namespace std;

class food;

class foodstand
{
public:
    static food* create(int p);
    int Buy(string f);
};
