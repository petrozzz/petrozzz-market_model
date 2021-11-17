#ifndef AUDIT_H
#define AUDIT_H
#include "good.h"
#include <iostream>
#include <fstream>

struct Audit{
    int *counts_solded;
    double *money_solded;
    int *counts_bouth;
    double *money_bouth;
    void init(const char *filename);
    void reset();
    double profit();
    void write_file(string headline);

private:
    int size;
    Good good;
    const char* filename;

};

#endif // AUDIT_H
