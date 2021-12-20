#include "others.h"

using namespace std;

class backstage;
class customer;

class salesman{
private:
    int id;
    backstage* bkstage;
public:
    int Get_Id();
    vector<package*> Search_By_Movie(string movie_name);
    vector<package*> Search_By_Time(movietime t);
    vector<package*> Search_By_Type(int cinema);
    int Buy_Food(customer* customer_pointer,string food_name);
    ticketinfo Buy_Ticket(customer* customer_pointer,string movie_name,int cinema_id,movietime t);
};
