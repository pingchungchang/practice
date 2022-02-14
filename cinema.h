#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include"others.h"
#include <map>
#ifndef cinema_defined
#define cinema_defined 1

using namespace std;

class customer;

class cinema
{
public:
    int id;
    int row;
    int col;
    map<movietime, vector<vector<customer*>>> seats;
    //vector<vector<vector<customer* c>>> seats;//可能要開三為(時間軸)
    vector<pair<movietime, movie*>> time_based_table;
    int price_factor;
    cinema(){}
    cinema(int id1, int column1, int row1, string type1);
    movietime Add_Movie (movietime time, movie* movie_id);
    bool Delete_Movie (movie* movie_id);
    vector<pair<movietime, movie* >>& GetTable();
    bool CheckAvailable(string movie_name,int cinema_id,movietime time);
    bool isFull(movietime time);
    bool SetSeat(int row, int column, movietime time, customer* c);
};

#endif