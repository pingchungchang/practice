#include "others.h"
#include "dispatcher.h"
#include "salesman.h"
#include "movie.h"
#include "customer.h"

using namespace std;

customer::customer(string c_name,string c_id,int c_age){
    name = c_name;
    id = c_id;
    age = c_age;
}

vector<package*> customer::Search_By_Movie(string movie_name){
	dispatcher* d = dispatcher::Get_Instance();
	salesman* seller = d->Match(this);
	return seller->Search_By_Movie(movie_name);
}
vector<package*> customer::Search_By_Time(movietime t){
	dispatcher* d = dispatcher::Get_Instance();
	salesman* seller = d->Match(this);
	return seller->Search_By_Time(t);	
}
// vector<package*> customer::Search_By_Type(string ci){
// 	dispatcher* d = dispatcher::Get_Instance();
// 	salesman* seller = d->Match(this);
// 	return seller->Search_By_Type(ci);	
// }
int customer::Buy_Food(string food_name){
	dispatcher* d = dispatcher::Get_Instance();
	salesman* seller = d->Match(this);
	return seller->Buy_Food(this,food_name);	
}
ticketinfo customer::Buy_Ticket(string movie_name,int cinema_id,movietime t){
	dispatcher* d = dispatcher::Get_Instance();
	salesman* seller = d->Match(this);
	return seller->Buy_Ticket(this,movie_name,cinema_id,t);	
}

/*
new add search