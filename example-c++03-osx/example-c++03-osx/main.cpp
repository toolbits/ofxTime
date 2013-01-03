#include <iostream>
#include "IRXTime.h"

using namespace ir;
using namespace std;

void test_summer(int delta)
{
    IRXTime time;
    {
        time.setDate(2012, 4, 1);
        time.setTime(1, 55, 0, IRXTime::SUMMERTIME_STANDARD);
        time_t pt = time.asTime_t();
        while (true) {
            cout << endl << "\x1B[1A\x1B[2K" << time.format("%YYYY/%MM/%DD %hh:%mm:%ss%S %p");
            usleep(1000);
            time += IRXTimeDiff(delta);
            if (time > IRXTime(2012, 4, 1, 3, 5, 0, IRXTime::SUMMERTIME_SUMMER)) {
                time -= IRXTimeDiff(delta);
                cout << "\t\t\t\t\t\t\t\t\t\t\t...OK" << endl;
                break;
            }
            time_t nt = time.asTime_t();
            if (nt - pt != delta) {
                cout << "\t\t\t\t\t\t\t\t\t\t\t...NG <<<" << endl;
                break;
            }
            pt = nt;
        }
        while (true) {
            cout << endl << "\x1B[1A\x1B[2K" << time.format("%YYYY/%MM/%DD %hh:%mm:%ss%S %p");
            usleep(1000);
            time -= IRXTimeDiff(delta);
            if (time < IRXTime(2012, 4, 1, 1, 55, 0)) {
                time += IRXTimeDiff(delta);
                cout << "\t\t\t\t\t\t\t\t\t\t\t...OK" << endl;
                break;
            }
            time_t nt = time.asTime_t();
            if (nt - pt != -delta) {
                cout << "\t\t\t\t\t\t\t\t\t\t\t...NG <<<" << endl;
                break;
            }
            pt = nt;
        }
        time.setDate(2012, 10, 28);
        time.setTime(1, 55, 0, IRXTime::SUMMERTIME_SUMMER);
        pt = time.asTime_t();
        while (true) {
            cout << endl << "\x1B[1A\x1B[2K" << time.format("%YYYY/%MM/%DD %hh:%mm:%ss%S %p");
            usleep(1000);
            time += IRXTimeDiff(delta);
            if (time > IRXTime(2012, 10, 28, 1, 5, 0)) {
                time -= IRXTimeDiff(delta);
                cout << "\t\t\t\t\t\t\t\t\t\t\t...OK" << endl;
                break;
            }
            time_t nt = time.asTime_t();
            if (nt - pt != delta) {
                cout << "\t\t\t\t\t\t\t\t\t\t\t...NG <<<" << endl;
                break;
            }
            pt = nt;
        }
        while (true) {
            cout << endl << "\x1B[1A\x1B[2K" << time.format("%YYYY/%MM/%DD %hh:%mm:%ss%S %p");
            usleep(1000);
            time -= IRXTimeDiff(delta);
            if (time < IRXTime(2012, 10, 28, 1, 55, 0, IRXTime::SUMMERTIME_SUMMER)) {
                time += IRXTimeDiff(delta);
                cout << "\t\t\t\t\t\t\t\t\t\t\t...OK" << endl;
                break;
            }
            time_t nt = time.asTime_t();
            if (nt - pt != -delta) {
                cout << "\t\t\t\t\t\t\t\t\t\t\t...NG <<<" << endl;
                break;
            }
            pt = nt;
        }
    }
    return;
}

void test_all(void)
{
    IRXTime time;
    {
        cout << "time.set(2013, 1, 1, 1, 2, 3)...";
        time.set(2013, 1, 1, 1, 2, 3);
        cout << time.formatYMD() << "\t\t\t\t\t\t...";
        if (time.getYear() == 2013 &&
            time.getMonth() == 1 &&
            time.getDay() == 1 &&
            time.getHour() == 1 &&
            time.getMinute() == 2 &&
            time.getSecond() == 3) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG <<<" << endl;
        }
    }
    {
        cout << "time.set(2013, 1, 1, 1, 2, 3)...";
        time.set(2013, 1, 1, 1, 2, 3);
        cout << time.formatYMD() << "\t\t\t\t\t\t...";
        if (time["year"] == 2013 &&
            time["month"] == 1 &&
            time["day"] == 1 &&
            time["hour"] == 1 &&
            time["minute"] == 2 &&
            time["second"] == 3 &&
            time["YEAR"] == 2013 &&
            time["Month"] == 1 &&
            time[""] == -1 &&
            time["test"] == -1) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG <<<" << endl;
        }
    }
    {
        cout << "time.set(2013, 2, 29, 22, 23, 24)...";
        time.set(2013, 2, 29, 22, 23, 24);
        cout << time.formatYMD() << "\t\t\t\t\t...";
        if (time.getYear() == 2013 &&
            time.getMonth() == 3 &&
            time.getDay() == 1 &&
            time.getHour() == 22 &&
            time.getMinute() == 23 &&
            time.getSecond() == 24) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG <<<" << endl;
        }
    }
    {
        cout << "time.set(2012, 2, 29, 22, 23, 24)...";
        time.set(2012, 2, 29, 22, 23, 24);
        cout << time.formatYMD() << "\t\t\t\t\t...";
        if (time.getYear() == 2012 &&
            time.getMonth() == 2 &&
            time.getDay() == 29 &&
            time.getHour() == 22 &&
            time.getMinute() == 23 &&
            time.getSecond() == 24) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG <<<" << endl;
        }
    }
    {
        cout << "time.set(2012, 13, 60, -10, 0, 0)...";
        time.set(2012, 13, 60, -10, 0, 0);
        cout << time.formatYMD() << "\t\t\t\t\t...";
        if (time.getYear() == 2013 &&
            time.getMonth() == 2 &&
            time.getDay() == 28 &&
            time.getHour() == 14 &&
            time.getMinute() == 0 &&
            time.getSecond() == 0) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG <<<" << endl;
        }
    }
    {
        cout << "time.set(2012, 12, 31, 24, 61, 182)...";
        time.set(2012, 12, 31, 24, 61, 182);
        cout << time.formatYMD() << "\t\t\t\t...";
        if (time.getYear() == 2013 &&
            time.getMonth() == 1 &&
            time.getDay() == 1 &&
            time.getHour() == 1 &&
            time.getMinute() == 4 &&
            time.getSecond() == 2) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG <<<" << endl;
        }
    }
    {
        cout << "time.set(2013, 1, 1, 0, -1, -2)...";
        time.set(2013, 1, 1, 0, -1, -2);
        cout << time.formatYMD() << "\t\t\t\t\t...";
        if (time.getYear() == 2012 &&
            time.getMonth() == 12 &&
            time.getDay() == 31 &&
            time.getHour() == 23 &&
            time.getMinute() == 58 &&
            time.getSecond() == 58) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG <<<" << endl;
        }
    }
    {
        cout << "time.set(2012, 3, 31, 12, 59, 59)...";
        time.set(2012, 3, 31, 12, 59, 59);
        cout << time.formatYMD() << "\t\t\t\t\t...";
        if (time.getYear() == 2012 &&
            time.getMonth() == 3 &&
            time.getDay() == 31 &&
            time.getHour() == 12 &&
            time.getMinute() == 59 &&
            time.getSecond() == 59) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG <<<" << endl;
        }
    }
    {
        cout << "time.subMonth(1)...";
        time.subMonth(1);
        cout << time.formatYMD() << "\t\t\t\t\t\t\t\t\t...";
        if (time.getYear() == 2012 &&
            time.getMonth() == 2 &&
            time.getDay() == 29 &&
            time.getHour() == 12 &&
            time.getMinute() == 59 &&
            time.getSecond() == 59) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG <<<" << endl;
        }
    }
    {
        cout << "time.subYear(1)...";
        time.subYear(1);
        cout << time.formatYMD() << "\t\t\t\t\t\t\t\t\t...";
        if (time.getYear() == 2011 &&
            time.getMonth() == 2 &&
            time.getDay() == 28 &&
            time.getHour() == 12 &&
            time.getMinute() == 59 &&
            time.getSecond() == 59) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG <<<" << endl;
        }
    }
    {
        cout << "time.addMonth(1)...";
        time.addMonth(1);
        cout << time.formatYMD() << "\t\t\t\t\t\t\t\t\t...";
        if (time.getYear() == 2011 &&
            time.getMonth() == 3 &&
            time.getDay() == 28 &&
            time.getHour() == 12 &&
            time.getMinute() == 59 &&
            time.getSecond() == 59) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG <<<" << endl;
        }
    }
    {
        cout << "time.addDay(4)...";
        time.addDay(4);
        cout << time.formatYMD() << "\t\t\t\t\t\t\t\t\t...";
        if (time.getYear() == 2011 &&
            time.getMonth() == 4 &&
            time.getDay() == 1 &&
            time.getHour() == 12 &&
            time.getMinute() == 59 &&
            time.getSecond() == 59) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG <<<" << endl;
        }
    }
    {
        cout << "time.addMonth(23)...";
        time.addMonth(23);
        cout << time.formatYMD() << "\t\t\t\t\t\t\t\t\t...";
        if (time.getYear() == 2013 &&
            time.getMonth() == 3 &&
            time.getDay() == 1 &&
            time.getHour() == 12 &&
            time.getMinute() == 59 &&
            time.getSecond() == 59) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG <<<" << endl;
        }
    }
    {
        cout << "time.subHour(13)...";
        time.subHour(13);
        cout << time.formatYMD() << "\t\t\t\t\t\t\t\t\t...";
        if (time.getYear() == 2013 &&
            time.getMonth() == 2 &&
            time.getDay() == 28 &&
            time.getHour() == 23 &&
            time.getMinute() == 59 &&
            time.getSecond() == 59) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG <<<" << endl;
        }
    }
    {
        cout << "time.subSecond(-1)...";
        time.subSecond(-1);
        cout << time.formatYMD() << "\t\t\t\t\t\t\t\t...";
        if (time.getYear() == 2013 &&
            time.getMonth() == 3 &&
            time.getDay() == 1 &&
            time.getHour() == 0 &&
            time.getMinute() == 0 &&
            time.getSecond() == 0) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG <<<" << endl;
        }
    }
    {
        cout << "time.setDate(2013, 7, 1)...";
        time.setDate(2013, 7, 1);
        cout << time.formatYMD() << "\t\t\t\t\t\t\t...";
        if (time.getYear() == 2013 &&
            time.getMonth() == 7 &&
            time.getDay() == 1 &&
            time.getHour() == 0 &&
            time.getMinute() == 0 &&
            time.getSecond() == 0) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG <<<" << endl;
        }
    }
    {
        cout << "time.setTime(14, 15, 16)...";
        time.setTime(14, 15, 16);
        cout << time.formatYMD() << "\t\t\t\t\t\t\t...";
        if (time.getYear() == 2013 &&
            time.getMonth() == 7 &&
            time.getDay() == 1 &&
            time.getHour() == 14 &&
            time.getMinute() == 15 &&
            time.getSecond() == 16) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG <<<" << endl;
        }
    }
    {
        cout << "time.setDate(2013, 12, 1)...";
        time.setDate(2013, 12, 1);
        cout << time.formatYMD() << "\t\t\t\t\t\t\t...";
        if (time.getYear() == 2013 &&
            time.getMonth() == 12 &&
            time.getDay() == 1 &&
            time.getHour() == 14 &&
            time.getMinute() == 15 &&
            time.getSecond() == 16) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG <<<" << endl;
        }
    }
    {
        cout << "time.subMonth(5)...";
        time.subMonth(5);
        cout << time.formatYMD() << "\t\t\t\t\t\t\t\t\t...";
        if (time.getYear() == 2013 &&
            time.getMonth() == 7 &&
            time.getDay() == 1 &&
            time.getHour() == 14 &&
            time.getMinute() == 15 &&
            time.getSecond() == 16) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG <<<" << endl;
        }
    }
    {
        cout << "time = IRXTime::epochTime()...";
        time = IRXTime::epochTime();
        cout << time.formatYMD() << "\t\t\t\t\t\t...";
        if (time.asTime_t() == 0) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG <<<" << endl;
        }
    }
    {
        cout << "time = IRXTime::epochUTCTime()...";
        time = IRXTime::epochUTCTime();
        cout << time.formatYMD() << "\t\t\t\t\t...";
        if (time.getYear() == 1970 &&
            time.getMonth() == 1 &&
            time.getDay() == 1 &&
            time.getHour() == 0 &&
            time.getMinute() == 0 &&
            time.getSecond() == 0) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG <<<" << endl;
        }
    }
    {
        cout << "time = IRXTime::currentTime()...";
        time = IRXTime::currentTime();
        time_t tt = ::time(NULL);
        cout << time.formatYMD() << "\t\t\t\t\t\t...";
        if (time.asTime_t() == tt - 1 ||
            time.asTime_t() == tt ||
            time.asTime_t() == tt + 1) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG <<<" << endl;
        }
    }
    {
        int year = (sizeof(time_t) >= 8) ? (6000950) : (1970);
        cout << "time1(1902, 2, 22, 11, 0, 33)...";
        IRXTime time1(1902, 2, 22, 11, 0, 33);
        cout << time1.format("%Y/%MM/%DD (%WEEK) %hh:%mm:%ss%S") << "\t\t\t...";
        if (time1.getYear() == 1902 &&
            time1.getMonth() == 2 &&
            time1.getDay() == 22 &&
            time1.getHour() == 11 &&
            time1.getMinute() == 0 &&
            time1.getSecond() == 33) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG <<<" << endl;
        }
        cout << "time2(" << year << ", 1, 1, 11, 22, 33)...";
        IRXTime time2(year, 1, 1, 11, 22, 33);
        cout << time2.format("%Y/%MM/%DD (%WEEK) %hh:%mm:%ss%S") << "\t...";
        if (time2.getYear() == year &&
            time2.getMonth() == 1 &&
            time2.getDay() == 1 &&
            time2.getHour() == 11 &&
            time2.getMinute() == 22 &&
            time2.getSecond() == 33) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG <<<" << endl;
        }
        IRXTimeDiff diff = time2 - time1;
        cout << "time3 = time1 + diff...";
        IRXTime time3 = time1 + diff;
        cout << time3.format("%Y/%MM/%DD (%WEEK) %hh:%mm:%ss%S") << "\t\t\t\t...";
        if (time3.getYear() == year &&
            time3.getMonth() == 1 &&
            time3.getDay() == 1 &&
            time3.getHour() == 11 &&
            time3.getMinute() == 22 &&
            time3.getSecond() == 33) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG <<<" << endl;
        }
        cout << "time3 = time2 - diff...";
        time3 = time2 - diff;
        cout << time3.format("%Y/%MM/%DD (%WEEK) %hh:%mm:%ss%S") << "\t\t\t\t\t...";
        if (time3.getYear() == 1902 &&
            time3.getMonth() == 2 &&
            time3.getDay() == 22 &&
            time3.getHour() == 11 &&
            time3.getMinute() == 0 &&
            time3.getSecond() == 33) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG <<<" << endl;
        }
        diff = time1 - time2;
        cout << "time3 = time1 - diff...";
        time3 = time1 - diff;
        cout << time3.format("%Y/%MM/%DD (%WEEK) %hh:%mm:%ss%S") << "\t\t\t\t...";
        if (time3.getYear() == year &&
            time3.getMonth() == 1 &&
            time3.getDay() == 1 &&
            time3.getHour() == 11 &&
            time3.getMinute() == 22 &&
            time3.getSecond() == 33) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG <<<" << endl;
        }
        cout << "time3 = time2 + diff...";
        time3 = time2 + diff;
        cout << time3.format("%Y/%MM/%DD (%WEEK) %hh:%mm:%ss%S") << "\t\t\t\t\t...";
        if (time3.getYear() == 1902 &&
            time3.getMonth() == 2 &&
            time3.getDay() == 22 &&
            time3.getHour() == 11 &&
            time3.getMinute() == 0 &&
            time3.getSecond() == 33) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG <<<" << endl;
        }
    }
    {
        cout << "[delta = 1]" << endl;
        test_summer(1);
        cout << "[delta = 3]" << endl;
        test_summer(3);
        cout << "[delta = 10]" << endl;
        test_summer(10);
        cout << "[delta = 13]" << endl;
        test_summer(13);
    }
    return;
}

int main(int argc, const char * argv[])
{
    {
        cout << "\x1B[3g" << endl;
        for (int i = 0; i < 20; ++i) {
            cout << "    \x1BH";
        }
        cout << endl << "\x1B[2A" << endl;
    }
    {
        setenv("TZ", "JST-09", 1);
        tzset();
    }
    cout << "[TZ = JST-09]" << endl;
    test_all();
    {
        setenv("TZ", "EST+05EDT,M4.1.0,M10.5.0", 1);
        tzset();
    }
    cout << endl;
    cout << "[TZ = EST+05EDT]" << endl;
    test_all();
    return 0;
}
