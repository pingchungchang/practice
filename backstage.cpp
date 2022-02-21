#include "backstage.h"
#include <string>
using namespace std;
backstage::backstage(){
	fstand = new foodstand();
}
movie* backstage::New_Movie(string name,movietime t,string description,int price_factor){
	movie* newone = new movie();
	newone->name = name;
	newone->duration = t;
	newone->description = description;
	newone->price_factor = price_factor;
	onstage_movies[name] = newone;
	return newone;
}

cinema* backstage::New_Cinema(int id,int col,int row,string type){
	cinema* c;
	if(type == "kids"){
		c = new cinema();
		c->id = id;
		c->row = row;
		c->col = col;
	}
	this->cinemas[id] = c;
	return c;
}
bool backstage::Delete_Movie(string movie_name){
	for(auto it = cinemas.begin();it != cinemas.end();it++){
		it->second->Delete_Movie(onstage_movies[movie_name]);
	}
	auto it = onstage_movies[movie_name];
	onstage_movies.erase(movie_name);
	free(it);
	return true;
}
bool backstage::Add_Movie(string movie_name,int cinema_id){
	cinema* c_pointer = cinemas[cinema_id];
	movie* m_id = onstage_movies[movie_name];
	movietime t = c_pointer->Add_Movie(m_id);
	m_id->Add_Movie(c_pointer,t);
	return true;
}

vector<package*> backstage::Search_By_Movie(string movie_name){
	vector<package*> returns;
	movie* m_id = onstage_movies[movie_name];
	for(auto it:m_id->time_based_table){
		package* tmp = new package(m_id);
		tmp->t = it.second;
		tmp->cine = it.first;
		returns.push_back(tmp);
	}
	return returns;
}
vector<package*> backstage::Search_By_Time(movietime t){
	vector<package*> returns;
	for(auto it:cinemas){
		for(auto each:it.second->time_based_table){
			if(each.first>t)break;
			else if((each.first<t)){
				continue;
			}
			else{
				package* tmp = new package(each.second);
				tmp->t = each.first;
				tmp->cine = it.second;
				returns.push_back(tmp);
				break;				
			}
		}
	}
	return returns;
}


// vector<package*> backstage::Search_By_Type(string cinema_type){
// 	vector<package*> returns;

// 	return returns;
// }
int backstage::Buy_Food (customer* customer_pointer,string food_name){
	return fstand->Buy(food_name);
}
ticketinfo backstage::Buy_Ticket(customer* customer_pointer,string movie_name,int cinema_id,movietime t){
	cinema* c_id = cinemas[cinema_id];
	for(int i = 0;i<c_id->row;i++){
		for(int j = 0;j<c_id->col;j++){
			if(c_id->SetSeat(i,j,t,customer_pointer) == true){
					ticketinfo returns;
					returns.mov = onstage_movies[movie_name];
					returns.cine = c_id;
					returns.value = onstage_movies[movie_name]->price_factor;
					returns.t = t;
					return returns;				
			}
		}
	}
	ticketinfo returns;
	returns.value = -1;
	return returns;
}