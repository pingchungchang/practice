#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include"others.h"

#ifndef cinema_defined
#define cinema_defined 1

using namespace std;

class customer;

class cinema
{
public:
    int id;
    int row;
    int column;
    vector<vector<customer*>> seats;
    vector<pair<movietime, movie*>> time_based_table;
    int price_factor;
    cinema(){}
    cinema(int id1, int column1, int row1, string type1);
    int Add_Movie (movietime, movie*);
    bool Delete_Movie (movie*);
    vector<pair<movietime, movie*>> GetTable();
    bool CheckAvailable(int, int, movietime);
    bool isFull(movietime);
    bool SetSeat(int, int, movietime);
};

#endif