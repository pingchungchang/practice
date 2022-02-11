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
    static int k;
    salesman* Match(customer* customer_pointer){
        return salesmans[0];
        // if(salesmans.size()==0)return nullptr;
        // k++;
        // return salesmans[k%salesmans.size()];
    }
    static dispatcher* Get_Instance(){
	    static dispatcher instance;
		return &instance;    	
	}
};

#endif