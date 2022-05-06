/*************************************************************************
	> File Name: 09-rvp.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Oct 2021 02:48:35 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
    A() {
        cout << this << " : DEFAULT CONSTRUCTOR" << endl;
    }
    A(int x) {
        cout << this << " : PARA CONSTRUCTOR" << endl;
    }
    A(const A &a) {
        cout << this << " : COPY CONSTRUCTOR" << endl;
    }
};

A func() {
    A temp(3);
    cout << "OBJECT temp: " << &temp << endl;
    return temp;  // 这里返回 temp的值 是将temp 拷贝给了一个临时的A类型的匿名变量
}

int main() {
    A a = func(); // 临时的匿名变量再拷贝给 a 对象
    cout << "OBJECT a: " << &a << endl;
    return 0;
}
