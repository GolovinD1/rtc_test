#pragma once
#include <string>
#include <cstdint>

class AlphaX_RTC {
private:
    uint16_t year;
    uint8_t month;
    uint8_t date;
    uint8_t hours;
    uint8_t minutes;
    uint8_t seconds;

public:
    AlphaX_RTC();

    // сеттеры
    void setYear(uint16_t y) { year = y; }
    void setMonth(uint8_t m) { month = m; }
    void setDate(uint8_t d) { date = d; }
    void setHours(uint8_t h) { hours = h; }
    void setMinutes(uint8_t m) { minutes = m; }
    void setSeconds(uint8_t s) { seconds = s; }

    // геттеры
    uint16_t getYear() const { return year; }
    uint8_t getMonth() const { return month; }
    uint8_t getDate() const { return date; }
    uint8_t getHours() const { return hours; }
    uint8_t getMinutes() const { return minutes; }
    uint8_t getSeconds() const { return seconds; }

    // методы
    std::string getTimeString() const;
    void simulateTickSeconds(int sec);
};