//
// Created by rongfan on 2022/3/20.
//

#include <iostream>
using namespace std;

void test() {
    auto x = 3.5 + 15l;                 // may cause type decay
    decltype(3.5 + 15l) y = 3.5 + 15l;  // no tpe decay
    decltype(auto) z = 3.5 + 15l;       // auto : 3.5 + 15l (in c++ 14)

    cout << "x: " << x << " y: " << y << " z: " << z << endl;

    int w = 3;
    int& m = w;

    auto h = m ;        // h [int]
    decltype(m) f = m;  // f [int&]
    cout << is_same<decltype(h), int>::value << endl;
    cout << is_same<decltype(m), int&>::value << endl;
}

void test1() {
    int x = 3;
    int* ptr = &x;

    // different for var and exp, for var decltype will return the
    // declared type for the variable
    cout << is_same<decltype(x), int>::value << endl;
    cout << is_same<decltype(ptr), int*>::value << endl;

    // lvalue add reference
    // ptr --> int* --> *ptr --> int
    // decltype(*ptr) --> int&
    cout << is_same<decltype((x)), int&>::value << endl;
    cout << is_same<decltype(*ptr), int&>::value << endl;

}

int main() {
    test();
//    test1();
    return 0;
}
