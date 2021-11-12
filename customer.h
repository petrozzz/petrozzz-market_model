#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include "mytime.h"
#include "good.h"

using namespace std;

struct Customer
{
public:
    double balance;
    int desired_counts[5];
    void init_customer();
    void appeared();
    int** behavior;
    int size_ids;
    int size_probably;
};

#endif // CUSTOMER_H
