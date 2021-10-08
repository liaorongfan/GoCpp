/*************************************************************************
	> File Name: 06-constructor_order.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Oct 2021 01:38:39 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
    A() {
        cout << this << " default constructor" << endl;
    }
    A(int n, int m):
        n(n), m(m),
        arr(nullptr), size(nullptr),
        offset(nullptr) {
        cout << "A(int) constructor" << endl;
    } 
    A(int *size, int *offset): size(size), offset(offset) {
        arr = new int[*size];
        arr += *offset;
        cout << "A(int *size) constructor" << endl;
    }
    ~A() {
        cout << this << "deconstructor" << endl;
        if (arr == nullptr) return ;
        arr -= *offset;
        delete[] arr;
    }
    int *arr, *size, *offset;
    int n, m; 
};


int main() {
    /*
     * 对像析构与定义的顺序相反：
     *
     * 逻辑：
     *     先定义 a 对象，说明 b 对象的构造有可能依赖于 a 对象
     *
     */
    A a(3, 4);
    A b(&a.n, &a.m);
    cout << "&a : " << &a << " &b : " << &b << endl;

    return 0;
}
