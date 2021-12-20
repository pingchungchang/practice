#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include"others.h"

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
    cinema();
    int Add_Movie (movietime, movie*);
    bool Delete_Movie (movie*);
    vector<pair<movietime, movie*>> GetTable();
    bool CheckAvailable(int, int, movietime);
    bool isFull(movietime);
    bool SetSeat(int, int, movietime);
};
