#include "audit.h"
#define MY_LINE "------------------------------------------"

void Audit::init(const char* filename){
    size = 5; //_msize(good.all_ids) / sizeof(good.all_ids);
    counts_solded = new int[size];
    money_solded = new double[size];
    counts_bouth = new int[size];
    money_bouth = new double[size];
    this->filename = filename;
    ofstream filestream("audit.txt");
    filestream.close();
}

void Audit::reset(){
    for(int k = 0; k < size; k++){
        counts_bouth[k] = 0;
        money_bouth[k] = 0;
        counts_solded[k] = 0;
        money_solded[k] = 0;
    }
}

double Audit::profit(){
    double res = 0;
    for(int k = 0; k < size; k++){
        res += money_solded[k] - money_bouth[k];
    }
    return res;
}

void Audit::write_file(string headline){
    ofstream filestream("audit.txt", ios_base::app);
    filestream << headline << endl;
    filestream << "Продажи: " << endl;
    for(int k = 0; k < size; k++){
        good.init_good(good.all_ids[k]);
        filestream << good.name << ": " << counts_solded[k] << " шт. " << money_solded[k] << " руб." << endl;
    }
    filestream << endl;
    filestream << "Закупки: " << endl;
    for(int k = 0; k < size; k++){
        good.init_good(good.all_ids[k]);
        filestream << good.name << ": " << counts_bouth[k] << " шт. " << money_bouth[k] << " руб." << endl;
    }
    filestream << endl;
    filestream << "Прибыль: " << profit() << " руб." << endl << MY_LINE << endl << endl;
    filestream.close();
    reset();
}
