#include "others.h"
#include <string>
#include <vector>
using namespace std;

#ifndef salesman_defined
#define salesman_defined 1

class backstage;
class customer;
class dispatcher;

static int sales_man_num = 0;

class salesman{
private:
    int id;
    backstage* bkstage;
    dispatcher* dspatcher;
public:
	
	salesman();
    int Get_Id();
    vector<package*> Search_By_Movie(string movie_name);
    vector<package*> Search_By_Time(movietime t);
    vector<package*> Search_By_Type(string type);
    int Buy_Food(customer* customer_pointer,string food_name);
    ticketinfo Buy_Ticket(customer* customer_pointer,string movie_name,int cinema_id,movietime t);
};


#endif