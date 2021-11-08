#include <iostream>
#include <customer.h>
#include <salesman.h>

class dispatcher{
public:
    dispatcher();
    vector<salesman*> sellers;
    salesman::salesman* Match(customer::customer*);
    static dispatcher* Get_Instance();
private:
    static dispatcher instance();
};
