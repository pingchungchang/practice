#include<cstdio>
#include<iostream>
#include<vector>
#include<string>

#include "cinema.h"
using namespace std;


cinema::cinema(int id1, int column1, int row1, string type1)
{
   id = id1;
   seats;
   row = row1;
   column = column1;
   time_based_table.resize(0);
   price_factor = 1;
};
bool cinema::SetSeat(int r,int c,movietime t){
   return true;
}