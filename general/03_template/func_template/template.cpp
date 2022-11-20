//
// Created by rongfan on 2022/5/7.
//
#include <iostream>

// declare a template
//template <typename T>
//void func(T);

// define a template
template <typename T>  // T template formal para --> compile time variable
void func(T input)  {  // input function formal para  --> run time varable
    std::cout << input << std::endl;
}


// template reload
template <typename T>
void func(T* input) {
    std::cout << *input << std::endl;
}

// template reload
template <typename T, typename T2>
void func(T input, T2 input2) {
    std::cout << input << std::endl;
    std::cout << input2 << std::endl;
}

int main() {
    int x = 4;
    func<int>(3);  // int template actual para | 3 function actual para
    func<int>(&x);
    func<int, float>(2, 2.2);
    return 0;
}