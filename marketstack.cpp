#include "marketstack.h"

int MarketStack::is_needgood(int id){    
    Good good;
    good.init_good(id);
    for(int k = 0; k < NUM_LEVELOFNEED; k++)
        if(count_good(id) >= good.min_count[k])
            return k;
    return NUM_LEVELOFNEED;
}

int MarketStack::count_good(int id){
    int count = 0;
    for(int k = 0; k < size; k++){
        if(id == goods[k].id)
            count++;
    }
    return count;
}

void MarketStack::add_good(Good good, double price){
    Good* buffer = new Good[size+1];
    for (int k = 0; k < size; k++) {
        buffer[k] = goods[k];
    }
    //good.day_produced = day_produced;
    good.price = price;
    balance+=price;
    //good.day_expiration = day_produced + good.expiration;
    buffer[size] = good;
    delete[] goods;
    goods = buffer;
    size++;
}

int MarketStack::remove_good(int n){
    if(size > 0){
        if(n >=0 && n < size){
            Good* buffer = new Good[size-1];
            for (int k = 0; k < n; k++) {
                buffer[k] = goods[k];
            }
            for (int k = n+1; k < size; k++) {
                buffer[k-1] = goods[k];
            }
            balance -= goods[n].price;
            delete [] goods;
            goods = buffer;
            size--;
            return 1;
        }
        return 0;
    }
    return -1;
}

int MarketStack::find_good(int id){
    for (int k = 0; k < size; k++) {
        if(goods[k].id == id)
            return k;
    }
    return -1;
}
