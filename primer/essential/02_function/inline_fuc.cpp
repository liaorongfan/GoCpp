#include<iostream>
using namespace std;

// https://www.runoob.com/cplusplus/cpp-inline-functions.html
// https://www.runoob.com/w3cnote/cpp-inline-usage.html

inline double CalArea(double radius);

int main(int argc, char const *argv[]) {
    double r(3.0);
    double area;
    area = CalArea(r);
    cout<<area<<endl;
    return 0;
}

//¼Ó¹Ø¼ü×Öinline
inline double CalArea(double radius)
{
    return 3.14 * radius * radius;
}