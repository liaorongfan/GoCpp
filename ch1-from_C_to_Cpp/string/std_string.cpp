//
// Created by rongfan on 2022/4/20.
//

#include <iostream>
#include <string>

void a_string() {
    std::string x = "Hello world";
    std::string y = x;

    y = y + " cpp";
    std::cout << y << std::endl;
}

int main() {
    a_string();
    return 0;
}
