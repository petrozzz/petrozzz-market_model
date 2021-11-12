#include "customer.h"

void Customer::init_customer(){
    Good good;
    size_ids = sizeof(good.all_ids) / sizeof(good.all_ids[0]);
    behavior = new int*[size_ids];
    behavior[0] = new int[3]{70, 80, 95};
    behavior[1] = new int[3]{80, 90, 97};
    behavior[2] = new int[3]{50, 60, 80};
    behavior[3] = new int[3]{70, 85, 98};
    behavior[4] = new int[3]{90, 95, 97};
    size_probably = int(_msize(behavior[0])) / sizeof(behavior[0][0]);
}

void Customer::appeared(){
    int val;
    for(int k = 0; k < size_ids; k++){
        desired_counts[k] = 0;
        val = rand() % 100;
        for(int n = 0; n < size_probably; n++){
            if(val > behavior[k][n])
                desired_counts[k]++;
        }
    }
}
