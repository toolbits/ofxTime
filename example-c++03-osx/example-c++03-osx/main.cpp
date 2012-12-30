#include <iostream>
#include "IRXTime.h"

using namespace ir;
using namespace std;

int main (int argc, const char * argv[])
{
    IRXTime time;
    
    cout << time.format("%YYYY/%MM/%DD %hh:%mm:%ss %p %WEEK") << endl;
    time = IRXTime::epochTime();
    cout << time.format("%YYYY/%MM/%DD %hh:%mm:%ss %p") << endl;
    time = IRXTime::epochUTCTime();
    cout << time.format("%YYYY/%MM/%DD %hh:%mm:%ss %p") << endl;
    time = IRXTime::currentTime();
    cout << time.format("%YYYY/%MM/%DD %hh:%mm:%ss %p") << endl;
    time = IRXTime::currentUTCTime();
    cout << time.format("%YYYY/%MM/%DD %hh:%mm:%ss %p") << endl;
    
    string str;
    time = IRXTime::currentTime();
    cout << time.format("%YYYY/%MM/%DD %hh:%mm:%ss") << endl;
    str = time.format("%p");
    time.parse("%p", str);
    cout << time.format("%YYYY/%MM/%DD %hh:%mm:%ss") << endl;
    
    IRXTime time1(1902, 2, 22, 11, 0, 33);
    IRXTime time2(6000950, 1, 1, 11, 22, 33);
    IRXTime time3;
    IRXTimeDiff diff;
    long day;
    int hour;
    int minute;
    long minute_l;
    int second;
    
    cout << "time1 = " << time1.formatYMD() << endl;
    cout << "time2 = " << time2.format("%Y/%MM/%DD %hh:%mm:%ss") << endl;
    
    diff = time2 - time1;
    
    diff.get(&day, &hour, &minute, &second);
    cout << "D = " << day << ", H = " << hour << ", M = " << minute << ", S = " << second << endl;
    
    diff.get(&minute_l, &second);
    cout << "M = " << minute_l << ", S = " << second << endl;
    cout << "L = " << INT_MAX << endl;
    cout << "T = " << diff["day"] << endl;
    
    time3 = time1 + diff;
    cout << "time3 = " << time3.format("%Y/%MM/%DD %hh:%mm:%ss") << endl;
    
    time3 = time2 - diff;
    cout << "time3 = " << time3.format("%Y/%MM/%DD %hh:%mm:%ss") << endl;
    
    diff = time1 - time2;
    
    time3 = time1 - diff;
    cout << "time3 = " << time3.format("%Y/%MM/%DD %hh:%mm:%ss") << endl;
    
    time3 = time2 + diff;
    cout << "time3 = " << time3.format("%Y/%MM/%DD %hh:%mm:%ss") << endl;
    return 0;
}
