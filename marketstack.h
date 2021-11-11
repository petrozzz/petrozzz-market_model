#ifndef MARKETSTACK_H
#define MARKETSTACK_H
#include "good.h"

struct MarketStack{
    Good*** goods;
    int width = 3000;    
    int is_needgood(int id);

    void add_good(int id);
};

#endif // MARKETSTACK_H
