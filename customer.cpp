#include "others.h"
#include "dispatcher.h"
#include "saleman.h"
#include "movie.h"
using namespace std;
customer::customer(string c_name,string c_id,int c_age){
    name = c_name;
    id = c_id;
    age = c_age;
}

customer::vector<package*> Search_By_Movie(string movie_name){
	dispatcher* d = dispatcher::Get_Instance();
	salesman* seller = dispatcher->Match(this);
	return salesman->Search_By_Movie(movie_name);
}
customer::vector<package*> Search_By_Time(time){
	dispatcher* d = dispatcher::Get_Instance();
	salesman* seller = dispatcher->Match(this);
	return salesman->Search_By_Time(t);	
}
customer::vector<package*> Search_By_Type(int cinema){
	dispatcher* d = dispatcher::Get_Instance();
	salesman* seller = dispatcher->Match(this);
	return salesman->Search_By_Time(cinema);	
}
customer::int Buy_Food(string food_name){
	dispatcher* d = dispatcher::Get_Instance();
	salesman* seller = dispatcher->Match(this);
	return salesman->Buy_food(this,food_name);	
}
customer::ticketinfo Buy_Ticket(string movie_name,int cinema_id,time t){
	dispatcher* d = dispatcher::Get_Instance();
	salesman* seller = dispatcher->Match(this);
	return salesman->Buy_Ticket(this,movie_name,cinema_id,t);	
}
