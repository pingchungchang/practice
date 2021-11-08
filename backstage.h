#include <iostream>
#include <movie.h>
#include <cinema.h>
#include <package.h>
#include <food_stand.h>
#include <string>
#include <map>

class backstage{
public:
    backstage Get_Instance();
    map<string,movie::movie*> onstage_movies;
    map<int/*cinema_id*/,cinema::cinema*> cinemas;
    movie::movie* New_Movie(int name,int time,string description);
    int Delete_Movie(string movie_name);
    cinema::cinema* New_Cinema(int cinema_id,int column,int row,string type);
    package::package* Search_By_Movie(string movie_name);
    package::package* Search_By_Time(int time);
    package::package* Search_By_Cinema(int cinema_id);
    package::package* Search_By_Type(string cinema_type);
    int But_Food(customer::customer* c,string food_name);
    int Buy_Ticket(customer::customer* c,string movie_name,int cinema_id,int time);
    backstage();
private:
    static backstage instance();
};
