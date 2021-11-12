#ifndef MARKETSTACK_H
#define MARKETSTACK_H
#include "good.h"

struct MarketStack{
    Good* goods;
    int size = 0;
    int width = 3000;    
    int is_needgood(int id);
    int count_good(int id);
    void add_good(Good good, double price);
    int remove_good(int n);
    int find_good(int id);
    double balance = 0;
};

#endif // MARKETSTACK_H
