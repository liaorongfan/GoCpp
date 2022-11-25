/*
设计一个时钟类，能够记录时、分、秒，重载它的++运算符，每执行一次++运算，加时1秒，但要使计时过程能够自动进位。
*/
#include<iostream>
using namespace std;

class Time {
public:
    Time(int h=0,int m=0,int s=0) {
        hour = h;
        minute = m;
        second = s;
    }
    Time operator++();
    Time operator++(int);
    void showTime() {
        cout << "current time：" << hour << ":" << minute << ":" << second << endl;
    }

private:
    int hour, minute, second;
};

Time Time::operator++(int n){
    cout << "obj++" << endl;
    ++second;
    if(second==60){
        second=0;
        ++minute;
        if(minute==60){
            minute=0;
            ++hour;
            if(hour==24){
                hour=0;
            }
        }
    }
    return *this;
}

int main(int argc, char const *argv[]) {
    int h = 23, m = 59, s = 59;
    Time t(h, m, s);
    t.showTime();
    t++;
    t.showTime();
    return 0;
}
