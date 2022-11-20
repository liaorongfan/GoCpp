//
// Created by rongfan on 2022/5/7.
//

#include <iostream>

template <typename T = int >
void fun(T input) {
    std::cout << input << std::endl;
}


template <typename T>  // lvalue reference
void fun2(T& input) {
    std::cout << input << std::endl;
}


template <typename T>  // universal reference (rvalue reference, when T is clear)
void fun3(T&& input) {
    std::cout << input << std::endl;
}


int main() {
    //fun<int>(3);  // explicit temp type define
    fun(3);   // implicit temp type deduce
    // func actual para --> (temp formal para) --> temp actual par
    int w = 3;
    const int* const ptr = &w;  // type(ptr) const int* const
    // [ [const int*] const ] ptr:
    // ptr can not be changed
    // the value in ptr can not be changed
    fun(ptr);
    // ===========================================================
    int x = 4;
    int& y = x;
    fun2(y);
    // y: int& --> int  |
    // input: T&        | ==> T& <--> int ==> T : int

    const int& z = x;
    fun2(z);         // | ==> T: const int
    // ==========================================================
    int&& h = 5;     // pass a rvalue reference to template func
    fun3(h);         // | => T: T&& <--> int&& => T: int

    int j = 5;       // pass a lvalue to template func
    fun3(j);         // j --> T&& --> int&  && --> int& (fold ref)


    return 0;
}



