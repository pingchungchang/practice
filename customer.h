#include "string"
#include "others.h"
using namespace std;

class dispatcher;

class customer{
public:
    customer(string c_name,string c_id,int c_age);
    string name;
    string id;
    int age;
    vector<package*> Search_By_Movie(string movie_name);
    vector<package*> Search_By_Time(movietime t);
    vector<package*> Search_By_Type(int cinema);
    int Buy_Food(string food_name);
    ticketinfo Buy_Ticket(string movie_name,int cinema_id,movietime t);
};
