#ifndef MYTIME_H
#define MYTIME_H
#include <string>


struct Mytime{
    std::string* namesweekday = new std::string[7] {"Пн", "Вт", "Ср", "Чт", "Пт", "Cб", "Вс"};
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int wday;
    std::string nameweekday;
};

#endif // MYTIME_H
