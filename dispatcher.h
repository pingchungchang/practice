using namespace std;

class customer;
class salesman;

class dispatcher{
public:
    dispatcher();
    vector<salesman*> salesmans;
    salesman* Match(customer* customer_pointer);
    static dispatcher* Get_Instance();
private:
    static dispatcher instance();
};
