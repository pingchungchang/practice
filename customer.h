#include "string"
#include "others.h"
#include "dispatcher.h"
using namespace std;

class customer{
public:
    string name;
    string id;
    int age;
    vector<package*> Search_By_Movie(string movie_name);
    vector<package*> Search_By_Time(time);
    vector<package*> Search_By_Type(int cinema);
    int Buy_Food(customer* customer_pointer,string food_name);
    ticketinfo Buy_Ticket(customer* customer_pointer,string movie_name,int cinema_id,time t);
};
