#include "movie.h"
#include "cinema.h"
#include "others.h"
#include "foodstand.h"
#include <string>
#include <map>

class backstage{
public:
    movie* New_Movie(int name,movietime t,string description,int price_factor);
    bool Add_Movie(string movie_name,int cinema_id);
    bool Delete_Movie(string movie_name);
    cinema* New_Cinema(int id,int column,int row,string type);
    vector<package*> Search_By_Movies(string movie_name);
    vector<package*> Search_By_Time(movietime t);
    vector<package*> Search_By_type(string cinema_type);
    int Buy_Food(customer* customer_pointer,string food_name);
    ticketinfo Buy_Ticket(customer* customer_pointer,string movie_name,int cinema_id,movietime t);
private:
    static backstage instance();
    map<string,movie*> onstaate_movies;
    map<int/*cinema_id*/,cinema*> cinemas;
    foodstand* fstand;

};
