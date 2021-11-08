#include <package.h>
#include <iostream>
#include <customer.h>
#include <backstage.h>
class salesman{
private:
    int id;
    backstage::backstage* bkstage;
public:
    int Get_Id();
    package::package* Search_By_Time(int t);
    package::package* Search_By_Cinema(int cinema_id);
    package::package* Search_By_Type(string cinema_type);
    package::package* Search_By_Movie(string movie_name);
    int But_Food(customer::customer* c,string food_name);
    int Buy_Ticket(cusomer::customer* c,int cinema_id,int time);
    salesman(int i,backstage::backstage* bkstage);
};
