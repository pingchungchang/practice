#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include "food.h"
#include "foodstand.h"

using namespace std;

foodstand::foodstand(){}
food* foodstand::create(int p){
    if (p == 1) {
        food* f = new Coke;
        return f;
    }
    else if (p == 2) {
        food* f = new Blacktea;
        return f;
    }
    else if (p == 3) {
        food* f = new Popcorn;
        return f;
    }
    else if (p == 4) {
            food* f = new Churros;
        return f;
    }
    else
    {
        return NULL;
    }
}
int foodstand::Buy(string f){
    int p;
    if (f == "Coke"){
        food* order = foodstand::create(1);
        return order->price();
    }
    else if (f == "Black tea"){
        food* order = foodstand::create(2);
        return order->price();
    }
    else if (f == "Popcorn"){
        food* order = foodstand::create(3);
        return order->price();
    }
    else if (f == "Churros"){
        food* order = foodstand::create(4);
        return order->price();
    }
    else
    {
        return 0;
    }
}

