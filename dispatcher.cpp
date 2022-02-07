#include "dispatcher.h"
#include "math.h"
#include "time.h"
salesman* dispatcher::Match(customer* customer_pointer){
    srand(time(NULL));
    return salesmans[rand() % salesmans.size()];
}
