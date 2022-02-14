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

cinema* backstage::New_Cinema(int id,int column,int row,string type){
	cinema* c;
	if(type == "kids"){
		c = new cinema();
		c->id = id;
		c->row = row;
		c->column = column;
	}
	this->cinemas[id] = c;
	return c;
}
bool backstage::Delete_Movie(string movie_name){
	for(auto it = cinemas.begin();it != cinemas.end();it++){
		it->second->Delete_Movie(onstage_movies[movie_name]);
	}
	onstage_movies.erase(movie_name);
	return true;
}
bool backstage::Add_Movie(string movie_name,int cinema_id){
	cinema* c_pointer = cinemas[cinema_id];
	movie* m_id = onstage_movies[movie_name];
	movietime lastone;
	if(c_pointer->time_based_table.size()>0)lastone = c_pointer->time_based_table[0].first;
	else{
		c_pointer->time_based_table.push_back(make_pair(movietime(1,0,0,0),m_id));
		m_id->time_based_table.push_back(make_pair(c_pointer,movietime(0,0,0,0)));
		return true;
	}
	for(int i = 1;i<c_pointer->time_based_table.size();i++){
		auto now = c_pointer->time_based_table[i];
		
		
		//error!
		if(now.first>lastone+movietime(0,0,0,30)+m_id->duration){
			auto p = make_pair(lastone+movietime(0,0,0,15),m_id);
			c_pointer->time_based_table.insert(c_pointer->time_based_table.begin()+i,p);
			m_id->time_based_table.push_back(make_pair(c_pointer,lastone+movietime(0,0,0,15)));
			return true;
		}
	}
	c_pointer->time_based_table.push_back(make_pair(lastone+movietime(0,0,0,15),m_id));
	m_id->time_based_table.push_back(make_pair(c_pointer,lastone+movietime(0,0,0,15)));
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
	for(int i = 0;i<c_id->time_based_table.size();i++){
		if(c_id->time_based_table[i].first == t){
			for(int j = 0;j<c_id->seats[0].size();j++){
				for(int k = 0;k< c_id->seats[0][0].size();k++){
					if(c_id->SetSeat(j,k,t)){
						ticketinfo returns;
						returns.mov = onstage_movies[movie_name];
						returns.cine = c_id;
						returns.value = onstage_movies[movie_name]->price_factor;
						returns.t = t;
						return returns;
					}
				}
			}
		}
	}
	ticketinfo returns;
	returns.value = false;
	return returns;
}