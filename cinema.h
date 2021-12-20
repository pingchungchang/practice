#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include"others.h"
using namespace std;


class cinema
{
public:
    int id;
    int row;
    int column;
    vector<vector<*customer>> seats;
    vector<pair<time*, movie*>>; time_based_table;
    int price_factor;
    cinema();
    int Add_Movie (time*, movie*){};
    bool Delete_Movie (movie*){};
    vector<pair<time*, movie*>> GetTable(){};
    bool CheckAvailable(int, int, time*) {};
    bool isFull(time*){};
    bool SetSeat(int, int, time*){};
};
