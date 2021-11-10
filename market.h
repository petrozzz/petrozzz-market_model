#ifndef MARKET_H
#define MARKET_H

#include <ctime>
#include <string>
#include "good.h"
#include "mytime.h"
#include "marketstack.h"

struct Market{
public:
    enum MarketState{Open, Close};
    void refresh(mytime* time);
    std::string get_message();
    void init_market();

private:
    mytime* time;
    std::string message;
    MarketState state = MarketState::Close;
    bool canwork();
    int hour_open = 8;
    int hour_close = 22;    
    double balance;
    double mounth_costs;
    bool is_pay_mounth_costs;
    MarketStack stack;
};
#endif // MARKET_H
