#include "salesman.h"
#include "dispatcher.h"
#include "backstage.h"
#include "foodstand.h"
using namespace std;

salesman::salesman(){
	this->dspatcher = dispatcher::Get_Instance();
	this->bkstage = backstage::Get_Instance();
	this->id = sales_man_num;
	sales_man_num++;
	dspatcher->salesmans.push_back(this);
}

vector<package*> salesman::Search_By_Movie(string movie_name){
	return bkstage->Search_By_Movie(movie_name);
}
vector<package*> salesman::Search_By_Time(movietime t){
	return bkstage->Search_By_Time(t);
}
vector<package*> salesman::Search_By_Type(string type){
	return bkstage->Search_By_Type(type);
}
int salesman::Buy_Food(customer* customer_pointer,string food_name){
	int returns = bkstage->Buy_Food(customer_pointer,food_name);
	return returns;
}
ticketinfo salesman::Buy_Ticket(customer* customer_pointer,string movie_name,int cinema_id,movietime t){
	return bkstage->Buy_Ticket(customer_pointer,movie_name,cinema_id,t);
}
