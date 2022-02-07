#include "movie.h"
#include "cinema.h"
#include "others.h"
#include "foodstand.h"
#include <string>
#include <map>

#ifndef backstage_defined
#define backstage_defined 1

class backstage{
public:
	backstage();
	static backstage* Get_Instance(){
		static backstage instance;
		return &instance;		
	}
    movie* New_Movie(string name,movietime t,string description,int price_factor);
    bool Add_Movie(string movie_name,int cinema_id);
    bool Delete_Movie(string movie_name);
    cinema* New_Cinema(int id,int column,int row,string type);
    vector<package*> Search_By_Movies(string movie_name);
    vector<package*> Search_By_Time(movietime t);
    vector<package*> Search_By_Type(string cinema_type);
    int Buy_Food(customer* customer_pointer,string food_name);
    ticketinfo Buy_Ticket(customer* customer_pointer,string movie_name,int cinema_id,movietime t);
private:
    map<string,movie*> onstage_movies;
    map<int/*cinema_id*/,cinema*> cinemas;
    foodstand* fstand;

};

#endif