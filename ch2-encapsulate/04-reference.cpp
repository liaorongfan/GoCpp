/*************************************************************************
	> File Name: 04-constructor.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Oct 2021 11:05:48 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
//引用：贴在实参上的标签, 不单独占用存储空间
void add_one(int &n) {
    n += 1;
    return ;
}

int main() {
    int a = 1, b = 3;
    cout << "normal param : " << a << " " <<  b << endl;
    add_one(a);
    add_one(b);
    cout << a << " " << b << endl;
    return 0;
}
