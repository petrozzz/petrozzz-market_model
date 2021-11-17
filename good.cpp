#include "good.h"


void Good::init_good(int id){
    this->id = id;
    switch (id) {
    case 11:
        name = "shocolate";
        weight = 100;
        width = 10;
        height = 15;
        depth = 1;
        purchase_price = 30;
        set_min_count(new int[NUM_LEVELOFNEED]{20, 10, 5});
        expiration = 9*30;
        break;
    case 21:
        name = "tea";
        weight = 200;
        width = 10;
        height = 10;
        depth = 10;
        purchase_price = 130;
        set_min_count(new int[NUM_LEVELOFNEED]{7, 3, 1});
        expiration = 356;
        break;
    case 31:
        name = "bread";
        weight = 400;
        width = 10;
        height = 12;
        depth = 15;
        purchase_price = 30;
        set_min_count(new int[NUM_LEVELOFNEED]{30, 20, 10});
        expiration = 2;
        break;
    case 41:
        name = "butter";
        weight = 200;
        width = 5;
        height = 2;
        depth = 8;
        purchase_price = 70;
        set_min_count(new int[NUM_LEVELOFNEED]{7, 3, 1});
        expiration = 6 * 30;
        break;
    case 42:
        name = "chease";
        weight = 500;
        width = 10;
        height = 10;
        depth = 10;
        purchase_price = 300;
        set_min_count(new int[NUM_LEVELOFNEED]{7, 3, 1});
        expiration = 14;
        break;
    default:
        break;
    }
    index = index_fromid(id);
}

void Good::set_min_count(int *min_count){
    for(int k = 0; k < NUM_LEVELOFNEED; k++){
        this->min_count[k] = min_count[k];
    }
}

int Good::index_fromid(int id){
    for(int k = 0; k < 5; k++){
        if(id == all_ids[k])
            return k;
    }
    return -1;
}

