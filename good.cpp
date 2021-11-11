#include "good.h"


void Good::init_good(int id){
switch (id) {
    case 11:
        name = "shocolate";
        weight = 100;
        width = 10;
        height = 15;
        depth = 1;
        purchase_price = 30;
        break;
    case 21:
        name = "tea";
        weight = 200;
        width = 10;
        height = 10;
        depth = 10;
        purchase_price = 130;
        break;
    case 31:
        name = "bread";
        weight = 400;
        width = 10;
        height = 12;
        depth = 15;
        purchase_price = 30;
        break;
    case 41:
        name = "butter";
        weight = 200;
        width = 5;
        height = 2;
        depth = 8;
        purchase_price = 70;
        break;
    case 42:
        name = "chease";
        weight = 500;
        width = 10;
        height = 10;
        depth = 10;
        purchase_price = 300;
        break;
    default:
        break;
}
}
