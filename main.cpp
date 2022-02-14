#include "backstage.h"
#include "customer.h"
#include "salesman.h"
#include "dispatcher.h"
#include "others.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iterator>

using namespace std;

vector<string> SplitString(string s)
{
	stringstream ss(s);
	istream_iterator<string> begin(ss);
	istream_iterator<string> end;
	vector<string> outputString(begin, end);
	return outputString;
}
int main(){
	// New class
	backstage* backStage = backstage::Get_Instance();
	vector<customer*> customers;
	vector<salesman*> salesmans;

	salesmans.push_back(new salesman());
	customers.push_back(new customer());
	
	while(1)
	{
		// Read input
		string inputCmd;
		getline(cin, inputCmd);
		vector<string> inputStrings = SplitString(inputCmd);

		if (inputStrings.size() > 0)
		{
			if (inputStrings[0] == "New_Client")
			{
				customer* c = new customer("DefaultName", inputStrings[1], 10);
				customers.push_back(c);
			}

			if (inputStrings[0] == "New_Clerk")
			{
				salesman* s = new salesman();
				salesmans.push_back(s);
			}

			if (inputStrings[0] == "New_Movie")
			{
				string name = inputStrings[1];
				movietime t;
				t.minute = stoi(inputStrings[2]);
				movie* m = backStage->New_Movie(name, t, inputStrings[3], 1);
			}

			if (inputStrings[0] == "New_Cinema")
			{
				// cinema* backStage->New_Cinema(int id,int column,int row,string type);
				int cinemaid = stoi(inputStrings[1]);
				int rownum = stoi(inputStrings[2]);
				int colnum = stoi(inputStrings[3]);
				cinema* c = backStage->New_Cinema(cinemaid, colnum, rownum, "kids");
			}
			if(inputStrings[0] == "Add_Movie"){
				string name = inputStrings[1];
				int c = stoi(inputStrings[2]);
				int returns = backStage->Add_Movie(name,c);
				if(returns != 1){
					cout<<"error\n";
					return -1;
				}
			}
			if(inputStrings[0] == "Search_By_Movie"){
				string name = inputStrings[1];
				vector<package*> returns = salesmans[0]->Search_By_Movie(name);
				cout<<"There are "<<returns.size()<<" times available now\n";
				for(auto i:returns){
					cout<<i->t.month<<i->t.day<<i->t.hour<<i->t.minute<<' '<<i->cine<<' '<<i->mov->name<<'\n';
				}
			}
			if(inputStrings[0] == "Search_By_Time"){
				movietime t;
				int k;
				k = stoi(inputStrings[1]);
				t.month = k;
				k = stoi(inputStrings[2]);
				t.day = k;
				k = stoi(inputStrings[3]);
				t.hour = k;
				k = stoi(inputStrings[4]);
				t.minute = k;
				vector<package*> returns = salesmans[0]->Search_By_Time(t);
				cout<<"There are "<<returns.size()<<" movies at that time\n";
				for(auto i:returns){
					cout<<i->cine->id<<'\n';
				}
			}
		}
	}
}
