/*************************************************************************
	> File Name: 10-default_delete.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Oct 2021 03:08:29 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


class A {
public:
    /*
     * 隐性行为 显性化
     *
     */
    A() = default;
    A(const A & ) = delete;
};

int main() {


    return 0;
}
