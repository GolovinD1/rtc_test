#include "alpha_x.h"
#include <cstdio>
#include <ctime>

AlphaX_RTC::AlphaX_RTC()
    : year(2000), month(1), date(1), hours(0), minutes(0), seconds(0) {
}

std::string AlphaX_RTC::getTimeString() const {
    char buffer[50];
    snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d %02d.%02d.%04d",
        hours, minutes, seconds, date, month, year);
    return std::string(buffer);
}

void AlphaX_RTC::simulateTickSeconds(int sec) {
    std::tm time_in = {};
    time_in.tm_year = year - 1900;
    time_in.tm_mon = month - 1;
    time_in.tm_mday = date;
    time_in.tm_hour = hours;
    time_in.tm_min = minutes;

    time_in.tm_sec = seconds + sec;

    std::mktime(&time_in); //нормализует "неправильное" время (23:59:61 -> 00:00:01)

    year = time_in.tm_year + 1900;
    month = time_in.tm_mon + 1;
    date = time_in.tm_mday;
    hours = time_in.tm_hour;
    minutes = time_in.tm_min;
    seconds = time_in.tm_sec;
}