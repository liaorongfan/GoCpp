//
// Created by rongfan on 2022/5/6.
//
#include <iostream>

// execute both in compile time and run time
constexpr int fun() {
    return 3;
}

// compute in compile time
constexpr int x = fun();

int main() {
    return 0;
}
