#include<iostream>
#include<vector>
#include<string>
#include"food.h"

using namespace std;

class food;
#ifndef fstanddef
#define fstanddef 1
class foodstand
{
public:
	foodstand();
    food* create(int p);
    int Buy(string f);
    static foodstand* GetInstance(){
        foodstand instance;
        return &instance;
    }
};
#endif