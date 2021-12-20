#include "movie.h"
#include "cinema.h"
#include "package.h"
#include "food_stand.h"
#include "string"
#include "map"

class backstage{
public:
    movie* New_Movie(int name,time t,string description,int price_factor);
    bool Add_Movie(string movie_name,int cinema_id);
    bool Delete_Movie(string movie_name);
    cinema8 New_Cinema(int id,int column,int row,string type);
    vector<package*> Search_By_Movies(string movie_name);
    vector<package*> Search_By_Time(time t);
    vector<package*> Search_By_type(string cinema_type);
    int Buy_Food(customer* customer_pointer,string food_name);
    ticketinfo Buy_Ticket(customer* customer_pointer,string movie_name,int cinema_id,time t);
private:
    static backstage instance();
    map<string,movie*> onstaate_movies;
    map<int/*cinema_id*/,cinema*> cinemas;
    food_stand* fstand;

};
