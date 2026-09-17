#define BOOST_TEST_MODULE AlphaX_RTC_Tests
#include <boost/test/included/unit_test.hpp>
#include "alpha_x.h"

// фикстура 
struct RTC_Fixture {
    AlphaX_RTC rtc;
    RTC_Fixture() {
        rtc.setYear(2026);
        rtc.setMonth(1);
        rtc.setDate(1);
        rtc.setHours(12);
        rtc.setMinutes(0);
        rtc.setSeconds(0);
    }
};

BOOST_AUTO_TEST_SUITE(RTC_Time_Management)


// проверка на смену дня
BOOST_FIXTURE_TEST_CASE(Midnight_Rollover, RTC_Fixture) {
    rtc.setHours(23);
    rtc.setMinutes(59);
    rtc.setSeconds(59);

    rtc.simulateTickSeconds(2); // перешагиваем через полночь

    BOOST_TEST(rtc.getDate() == 2);
    BOOST_TEST(rtc.getHours() == 0);
    BOOST_TEST(rtc.getMinutes() == 0);
    BOOST_TEST(rtc.getSeconds() == 1);
}

// проверка на високосный год
BOOST_FIXTURE_TEST_CASE(Leap_Year_Rollover, RTC_Fixture) {
    rtc.setYear(2024); // високосный год
    rtc.setMonth(2);
    rtc.setDate(28);
    rtc.setHours(23);
    rtc.setMinutes(59);
    rtc.setSeconds(59);

    rtc.simulateTickSeconds(1);

    // ожидаем 29 февраля
    BOOST_TEST(rtc.getDate() == 29);
    BOOST_TEST(rtc.getMonth() == 2);
}

BOOST_FIXTURE_TEST_CASE(Check_String_Format_Leading_Zeros, RTC_Fixture) {
    // проверка функции вывода
    rtc.setYear(2026);
    rtc.setMonth(2);
    rtc.setDate(5);
    rtc.setHours(9);
    rtc.setMinutes(4);
    rtc.setSeconds(7);

    BOOST_TEST(rtc.getTimeString() == "09:04:07 05.02.2026");
}

BOOST_AUTO_TEST_SUITE_END()