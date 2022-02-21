#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include <map>
#include "cinema.h"
#include "movie.h"
using namespace std;


cinema::cinema(int id1, int col1, int row1, string type1)
{
   id = id1;
   seats;
   row = row1;
   col = col1;
   time_based_table.resize(0);
   price_factor = 1;
};
movietime cinema::Add_Movie (movie* movie_id){
   movietime lastone;
   if(this->time_based_table.size()>0) {
      lastone = this->time_based_table[0].first;
      for(int i = 1;i<this->time_based_table.size();i++){
		   auto now = this->time_based_table[i];
		   if(now.first>lastone+movietime(0,0,0,30)+movie_id->duration){
			   this->time_based_table.insert(this->time_based_table.begin()+i,make_pair(lastone+movietime(0,0,0,15),movie_id));
			   movie_id->time_based_table.push_back(make_pair(this,lastone+movietime(0,0,0,15)));
			   return lastone+movietime(0,0,0,15);
		   }
      }
      this->time_based_table.push_back(make_pair(lastone+movietime(0,0,0,15),movie_id));
	   movie_id->time_based_table.push_back(make_pair(this,lastone+movietime(0,0,0,15)));
	   return lastone+movietime(0,0,0,15);
	}
	else{
		this->time_based_table.push_back(make_pair(movietime(1,0,0,0), movie_id));
		movie_id->time_based_table.push_back(make_pair(this,movietime(1,0,0,0)));
      this->seats[movietime(1,0,0,0)].resize(this->col, vector<customer*> (this->row, nullptr));
		return movietime(1,0,0,0);
	}
};
bool cinema::Delete_Movie (movie* m_id){
   vector<int> m;
   for (int i = 0; i < time_based_table.size(); i++){
      if (time_based_table[i].second == m_id) m.push_back(i);  
   }
   for (int i = m.size()-1; i >=0; i--){
      this->time_based_table.erase(this->time_based_table.begin()+m[i]);
   }
   return true;
};
vector<pair<movietime ,movie* >>& cinema::GetTable(){
   return this->time_based_table;
};
bool cinema::CheckAvailable(string movie_name,int cinema_id, movietime time){
   return true;
};
bool cinema::isFull(movietime time){
   bool c = 0;
   for (int i = 0; i < this->col; i++){
      for (int j = 0; j < this->row; j++){
         if (this->seats[time][j][i] != nullptr) {
            c = 1;
            break;
         }
      }
   }
   if (c == 0) return false;
   else return true;
};
bool cinema::SetSeat(int row, int col, movietime time, customer* c){
   if (this->seats[time][row][col] == nullptr){
      this->seats[time][row][col] = c;
      return true;
   }
   else return false;
};
