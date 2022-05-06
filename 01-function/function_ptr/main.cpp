//
// Created by rongfan on 2022/5/7.
//
#include <iostream>
#include <vector>
#include <algorithm>

int inc(int x) {
    return x + 1;
}

int dec(int x) {
    return x - 1;
}

// define a function type
using K = int(int);

// a high level function which using function as para
int twice(K* fun, int x) {
    int tmp = (*fun)(x);
    return 2 * tmp;
}

int main() {
    std::cout << twice(&inc, 100) << std::endl;
    std::vector<int> a{1, 2, 3, 4, 5};
    std::transform(a.begin(), a.end(), a.begin(), &dec);
    for (int i : a) {
        std::cout << i << std::endl;
    }
    return 0;
}