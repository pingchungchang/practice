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
