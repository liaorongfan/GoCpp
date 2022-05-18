//
// Created by rongfan on 2022/5/6.
//

#include <iostream>
#include <initializer_list>

void func(std::initializer_list<int> par) {

}

int default_para(int x = 0) {
    return x;
}

int main() {
    func(1, 2, 3, 4, 5);
    return 0;
}