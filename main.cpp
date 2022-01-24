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
				movie* m = backStage->New_Movie(name, t, inputStrings[3], 0.5);
			}

			if (inputStrings[0] == "New_Cinema")
			{
				cinema* New_Cinema(int id,int column,int row,string type);
				int cinemaid = stoi(inputStrings[1]);
				int rownum = stoi(inputStrings[2]);
				int colnum = stoi(inputStrings[3]);
				cinema* c = backStage->New_Cinema(cinemaid, colnum, rownum, "kids");
			}
		}
	}
}
