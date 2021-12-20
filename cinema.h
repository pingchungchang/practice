#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include "customer.h"
using namespace std;


class cinema
{
public:
    int id;
    int row;
    int column;
    vector<vector<*customer::customer>> seats virtual void bake() = 0;
    virtual void cut() = 0;
    virtual void box() = 0;
};

class margherita: public pizza
{
public:
    void bake() {
        printf("marghrita baked.\n");
    }
    void cut() {
        printf("marghrita cutted.\n");
    }
    void box() {
        printf("marghrita boxed.\n");
    }
    margherita(){}
};

class hawaii: public pizza
{
public:
    void bake() {
        printf("hawaii baked.\n");
    }
    void cut() {
        printf("hawaii cutted.\n");
    }
    void box() {
        printf("hawaii boxed.\n");
    }
    hawaii(){}
};

class pepperoni: public pizza
{
public:
    void bake() {
        printf("pepperoni baked.\n");
    }
    void cut() {
        printf("pepperoni cutted.\n");
    }
    void box() {
        printf("pepperoni boxed.\n");
    }
    pepperoni(){}
};

class pizzastore
{
public:
    static pizza* create(int p){
        if (p == 1) {
            pizza* order = new margherita;
            return order;
        }
        else if (p == 2) {
            pizza* order = new hawaii;
            return order;
        }
        else if (p == 3) {
            pizza* order = new pepperoni;
            return order;
        }
    }
    //pizzastore(){}
};

int main(){
    printf("Please select: 1: martherita; 2: hawaii; 3: pepperoni; 0: end\n");
    //machine* m = new machine();//Cake* c = new Cake;
    int select = 4;
    while(1){
        scanf("%d", &select);
        if (select > 3 || select < 0) printf("error! Please select again.\n");
        else if (select != 0){
            //pizzastore* store = new pizzastore;
            pizza* order = pizzastore::create(select);
            order->bake();
            order->cut();
            order->box();
        }
        else {
            printf("end order\n");
            break;
        };
    }
}
