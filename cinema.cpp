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
movietime cinema::Add_Movie (movietime time, movie* movie_id){
   movietime lastone;
   if(this->time_based_table.size()>0) {
      lastone = this->time_based_table[0].first;
      for(int i = 1;i<this->time_based_table.size();i++){
		   auto now = this->time_based_table[i];
		   if(now.first>lastone+time(0,0,0,30)+movie_id->duration){
			   this->time_based_table.insert(make_pair(lastone+time(0,0,0,15),movie_id),this.time_based_table.begin()+i);
			   movie_id->time_based_table.push_back(make_pair(this,lastone+movietime(0,0,0,15)));
			   return true;
		   }
      }
      this->time_based_table.push_back(make_pair(lastone+time(0,0,0,15),movie_id));
	   movie_id->time_based_table.push_back(make_pair(this,lastone+time(0,0,0,15)));
	   return true;
	}
	else{
		this->time_based_table.push_back(make_pair(time(1,0,0,0), movie_id));
		movie_id->time_based_table.push_back(make_pair(c_pointer,time(0,0,0,0)));
      seats[movie_id].resize(col, vector<customer*> (row, null);
		return true;
	}
};
bool cinema::Delete_Movie (movie*){
   vector<int> m;
   for (int i = 0; i < time_based_table.size(); i++){
      if (time_based_table[i].second == movie*) m.push_back[i];  
   }
   for (int i = 0; i < m.size(); i++){
      this->time_based_table.erase[i];
   }
   return true;
};
vector<pair<movietime time, movie* movie_id>>& cinema::GetTable(){
   return this->time_based_table;
};
bool cinema::CheckAvailable(string movie_name,int cinema_id, movietime time){
   return true;
};
bool cinems::isFull(movietime time){
   bool c = 0;
   for (int i = 0, i < this->column1; i++){
      for (int j = 0; j > this->row1; j++){
         if (this->seats[time][i][j] != null) {
            c = 1;
            break;
         }
      }
   }
   if (c == 0) return false;
   else return true;
};
bool SetSeat(int row, int column, movietime time, customer* c){
   if (this->seats[time][row][column] == null){
      this->seats[time][row][column] = c;
      return true;
   }
   else return false;
};
