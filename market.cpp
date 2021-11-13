#include "market.h"

void Market::refresh(Mytime* time){
    this->time = time;
    time_count++;
    if((state == MarketState::Open) && !canwork()){
        state = MarketState::Close;
        message = "The market close";
    }
    if(state == MarketState::Close && canwork()){
        state = MarketState::Open;
        message = "The market open";
        if(stack.is_needgood(11) >= 2){
            order_goods(11, 5);
        }
        if(stack.is_needgood(21) >= 2){
            order_goods(21, 10);
        }
        if(stack.is_needgood(31) >= 2){
            order_goods(31, 15);
        }
        if(stack.is_needgood(41) >= 2){
            order_goods(41, 12);
        }
        if(stack.is_needgood(42) >= 2){
            order_goods(42, 13);
        }
    }

    if(state == MarketState::Open && ((time_count%10) == 0)){
        time_count = 0;
        customer.balance = rand() % 1000;
        customer.appeared();
        for(int k =0; k < customer.size_ids; k++){
            for(int n = 0; n < customer.desired_counts[k]; k++){
                int num = stack.find_good(good.all_ids[k]);
                if(num >= 0 ){
                    double price_of_good = stack.goods[num].price;
                    std::string name = stack.goods[num].name;
                    if(price_of_good < customer.balance && stack.remove_good(num) == 1){
                        customer.balance -= price_of_good;
                        balance += price_of_good;
                        message = "The customers by " + name + ".";
                    }
                }
            }
        }
    }


    if(time->day == 1 && !is_pay_mounth_costs){
        balance -= mounth_costs;
        is_pay_mounth_costs = true;
        message = "Mounth costs payed (Balance: " + std::to_string(balance) + ")";
    }
    if(time->day == 2 && is_pay_mounth_costs){
        is_pay_mounth_costs = false;
    }
}

std::string Market::get_message(){
    std::string res = message;
    message = "";
    return res;
}

void Market::init_market(){
    balance = 10000.0;
    mounth_costs = 2000.0;
    is_pay_mounth_costs = false;
    srand(std::time(NULL));
    customer.init_customer();
}

void Market::order_goods(int id, int count){
    Good good;
    good.init_good(id);
    for(int k = 0; k < count; k++){
        if(balance > good.purchase_price){
            stack.add_good(good, good.purchase_price*1.1);
            balance -= good.purchase_price;
        }
        else{
            message += "\n We can not order " + good.name + ". The balance is smaller. (Balance: " + std::to_string(balance) + ")";
            break;
        }
    }
    message += "\n We order " + std::to_string(count) + " " + good.name + " (Balance: " + std::to_string(balance) + ")";
}

bool Market::canwork(){    
    if ((time->hour > hour_open) && (time->hour < hour_close))
        return true;
    else
        return false;
}

