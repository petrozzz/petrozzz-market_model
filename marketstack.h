#ifndef MARKETSTACK_H
#define MARKETSTACK_H
#include "good.h"

struct MarketStack{
    Good*** goods;
    int width = 3000;
};

#endif // MARKETSTACK_H
