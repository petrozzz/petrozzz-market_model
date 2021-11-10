#include "market.h"

void Market::refresh(mytime* time){
    this->time = time;
    if((state == MarketState::Open) && !canwork()){
        state = MarketState::Close;
        message = "The market close";
    }
    if(state == MarketState::Close && canwork()){
        state = MarketState::Open;
        message = "The market open";
    }
    if(time->day == 1 && !is_pay_mounth_costs){
        balance -= mounth_costs;
        is_pay_mounth_costs = true;
        message = "Mounth costs payed (Balance: " + std::to_string(balance) + ")";
    }
    if(time->day == 2 && is_pay_mounth_costs){
        is_pay_mounth_costs = false;
    }
    if(stack.)
}

std::string Market::get_message(){
    std::string res = message;
    message = "";
    return res;
}

void Market::init_market(){
    balance = 1000.0;
    mounth_costs = 100.0;
    is_pay_mounth_costs = false;
}

bool Market::canwork(){
    if ((time->hour > hour_open) && (time->hour < hour_close))
        return true;
    else
        return false;
}

