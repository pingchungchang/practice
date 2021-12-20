#include "iostream"
#include "customer.h"
#include <salesman.h"

class dispatcher{
public:
    dispatcher();
    vector<salesman*> salesmans;
    salesman::salesman* Match(customer* customer_pointer);
    static dispatcher* Get_Instance();
private:
    static dispatcher instance();
};
