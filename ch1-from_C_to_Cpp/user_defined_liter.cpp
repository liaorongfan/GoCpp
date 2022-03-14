//
// Created by rongfan on 2022/3/15.
//

#include <iostream>

// user defined suffix liter  "_int" and it can be any string
int operator "" _int(long double x) {
    return (int)x * 2;
}

int main() {
    int x = 3.1415_int;
    std::cout << x << std::endl;
}

