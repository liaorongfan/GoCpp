//
// Created by rongfan on 2022/5/17.
//

#include <iostream>
#include <array>
#include <type_traits>

void copy_array() {
    std::array<int, 3> a;    // an array which contains 3 int item
    std::array<int, 3> b = a;
    // array support for array copy
    std::cout << std::is_same<std::array<int, 3>::value_type, int>::value << std::endl;
}

void a_array() {
    std::array<int, 4> numbers {4, 5, 7, 8};
    std::cout << "second element: " << numbers[1] << "\n";
    // using .at() to ensure only access element within the container
    // while [n] may out of container boundary
    std::cout << "third element: " << numbers.at(2) << "\n";

    std::cout << ".front(): " << numbers.front() << std::endl;
    std::cout << ".back(): " << numbers.back() << std::endl;


    numbers[0] = 10;

    std::cout << "ALL numbers: ";
    for (auto i : numbers) {
        std::cout << " " << i;
    }
    std::cout << "\n";
}


int main() {
    a_array();
    return 0;
}