#include<cstdio>
#include<iostream>
#include<vector>
#include<string>

#include "movie.h"
using namespace std;


movie::movie(string name1, movietime duration1, string description1, int price_factor1)
{
    name = name1;
    duration = duration1;
    description = description1;
    time_based_table.resize(0);
    price_factor = price_factor1;
}
movie* movie::Search(cinema* c, movietime time){
    if (c->time_based_table.size() == 0) return NULL;
    else{
        for (int i = 0; i < c->time_based_table.size(); i++){
            if (time_based_table[i].first == time) {
                return time_based_table[i].second;
                break;
            }
        }
    }
}
vector<pair<cinema*, movietime>> movie::Get_Table(){
    return this->time_based_table;
}
bool Add_Movie(cinema* c){

}