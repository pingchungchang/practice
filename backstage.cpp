#include "backstage.h"

backstage::backstage(){
	fstand = new foodstand();
}
movie* backstage::New_Movie(string name,movietime t,string description,int price_factor){
	movie* newone = new movie();
	newone->name = name;
	newone->duration = t;
	newone->description = description;
	newone->price_factor = price_factor;
	onstage_movies[newone->name] = newone;
	return newone;
}
cinema* backstage::New_Cinema(int id,int column,int row,string type){
	cinema* c;
	if(type == "kids"){
		c = new cinema();
		c->id = id;
		c->seats = vector<vector<customer*>>(row,vector<customer*>(column,nullptr));
		c->row = row;
		c->column = column;
	}
	this->cinemas[id] = c;
	return c;
}
bool backstage::Delete_Movie(string movie_name){
	onstage_movies.erase(movie_name);
}

