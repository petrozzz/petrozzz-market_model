#ifndef MARKET_H
#define MARKET_H

#include <ctime>
#include <string>
#include <iostream>
#include <fstream>
#include "good.h"
#include "mytime.h"
#include "marketstack.h"
#include "customer.h"
#include "audit.h"

struct Market{
public:
    enum MarketState{Open, Close};
    void refresh(Mytime* time);
    std::string get_message();
    void init_market();
    void order_goods(int id, int count);


public:
    Mytime* time;
    std::string message;
    MarketState state = MarketState::Close;
    bool canwork();
    int hour_open = 8;
    int hour_close = 22;    
    double balance;
    double mounth_costs;
    bool is_pay_mounth_costs;
    MarketStack stack;
    Customer customer;
    Good good;
    Audit audit;
    int time_count = 0;
    bool audit_on;
};
#endif // MARKET_H
