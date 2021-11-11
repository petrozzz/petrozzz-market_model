#ifndef GOOD_H
#define GOOD_H
#include <string>
#include "mytime.h"

using namespace std;

struct Good{
    string name;
    int id;
    int weight;
    int width;
    int height;
    int depth;
    double purchase_price;
    double price;
    mytime day_produced;
    mytime day_expiration;

    void init_good(int id);
};



#endif // GOOD_H
