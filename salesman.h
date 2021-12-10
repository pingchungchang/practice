#include "others.h"
#include "customer.h"
#include "backstage.h"
class salesman{
private:
    int id;
    backstage::backstage* bkstage;
public:
    int Get_Id();
    vector<package*> Search_By_Movie(string movie_name);
    vector<package*> Search_By_Time(time);
    vector<package*> Search_By_Type(int cinema);
    int Buy_Food(customer* customer_pointer,string food_name);
    ticketinfo Buy_Ticket(customer* customer_pointer,string movie_name,int cinema_id,time t);
};
