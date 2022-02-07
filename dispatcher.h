#include "vector"

#ifndef dispatcher_defined
#define dispatcher_defined 1

using namespace std;

class salesman;
class customer;

class dispatcher{
public:
    dispatcher(){};
    vector<salesman*> salesmans;
    salesman* Match(customer* customer_pointer);
    static dispatcher* Get_Instance(){
	    static dispatcher instance;
		return &instance;    	
	}
};

#endif