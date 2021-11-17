#ifndef GOOD_H
#define GOOD_H
#include <string>
#include "mytime.h"

using namespace std;
#define NUM_LEVELOFNEED 3

struct Good{
    string name;
    int id;
    int index;
    int weight;
    int width;
    int height;
    int depth;
    double purchase_price;
    double price;
    int expiration;
    Mytime day_produced;
    Mytime day_expiration;    
    int min_count[NUM_LEVELOFNEED];
    void init_good(int id);
    void set_min_count(int *min_count);
    int all_ids[5]{11, 21, 31, 41, 42};
    int index_fromid(int id);
};



#endif // GOOD_H
