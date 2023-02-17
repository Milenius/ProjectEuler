#include<iostream>

const int months[] =   {31, 28, 31, 30, 
                        31, 30, 31, 31,
                        30, 31, 30, 31};

int main() {
    int start_year = 1901;
    int end_year = 2000;

    int day = 0;
    int sundays = 0;

    for (int year = start_year; year < end_year; year++) {
        for (int month = 0; month < 12; month++) {
            day += months[month];
            if (year%4 == 0 && month == 1)
                day++;

            if ((day+1)%7 == 0) {
                sundays++;
                std::cout << day <<"."<<month+1<<"."<<year<<std::endl;
            }
        }
    }
    
    std::cout << sundays;

}