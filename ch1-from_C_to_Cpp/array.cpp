//
// Created by rongfan on 2022/4/9.
//
#include <iostream>
#include <typeinfo>

using namespace std;

int array() {
    // in c or c++ build-in array doesn't support copy opt
    // in consideration of execute efficiency
    // l-value  locator value
    int b[] = {1, 2, 3};
    auto a = b;
    // type decay form int[3] to int*, using a rvalue ,auto will inference b as a pointer
    // instead of int[3]
    cout << is_same<decltype(a), int*>::value << endl;
    auto& c = b;
    cout << is_same<decltype(c), int(&)[3]>::value << endl;

    // string array
    char str[] = "hello";  //char[6]  \0 at the end as default
    char str2[]  = {'h', 'e', 'l', 'l', 'o'};  //char[5]

    return 0;

}

void pointer_array() {
    int x, y, z;
    int* a[3] = {&x, &y, &z};  // pointer as element

}

void visit_array() {
    int x = 100;
    int* ptr = &x;
    // x[n] -> *(x + n)
    cout << *ptr << endl;
    cout << ptr[0] << endl;
    int a[3] = {1, 2, 3};
    auto b = a;
    cout << a[0] << endl;
    cout << *(a + 0) << endl;
    cout << *(a + 1) << endl;
    cout << b[1] << endl;
    // be care of visit over boundary value
    cout << a[100] << endl;
    cout << *(a + 100) << endl;
}

void array_address() {
    int a[3] = {1, 2, 3};
    cout << "start address of array: " << a << endl;
    cout << "start address of array: " << &a[0] << endl;
    cout << "start address of array: " << begin(a) << endl; // cbegin  --> const begin

    cout << "start address of array: " << a + 3 << endl;
    cout << "start address of array: " << &a[3] << endl;
    cout << "start address of array: " << end(a) << endl;  // cend --> const end
}

void array_size() {
    int a[3] = { 1, 2, 3};
    // in c
    cout << sizeof(a) / sizeof(int) << endl;
    // in C++
    // cout << std::size(a) << endl;  // compile: g++ -std=c++17 array.cpp
    cout << std::end(a) - std::begin(a) << endl;
    cout << std::cend(a) - std::cbegin(a) << endl;

}

void iter_array() {
    int a[4] = {1, 3, 5, 7};

    size_t index = 0;
    while (index < std::size(a)) {
        std::cout << a[index] << endl;
        index = index + 1;
    }

    auto ptr = std::cbegin(a);
    while (ptr < std::cend(a)) {
        std::cout << *ptr << std::endl;
        ptr += 1;
    }

    for (int x : a) {
        std::cout << x << std::endl;
    }

}

int main() {
//    array();
//    visit_array();
//    array_address();
//    array_size();
    iter_array();
    return 0;
}