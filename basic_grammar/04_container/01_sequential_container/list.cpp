//
// Created by rongfan on 2022/5/31.
//
#include <iostream>
#include <list>

void list() {
    std::list<int> a{1, 2, 3};
    for (auto ptr = a.begin(); ptr != a.end(); ++ptr) {
        std::cout << *ptr << std::endl;
    }
}

int main() {
    list();
}
