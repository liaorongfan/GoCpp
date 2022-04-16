//
// Created by rongfan on 2022/3/20.
//
#include <iostream>
using namespace std;

int test1() {
    int z;
    // using default initialization
    // int z = 0;
    std::cout << z << std::endl;
    int x = 3.5 + 15l;
    auto y = 3.5 + 15l;
    std::cout << x << std::endl << y << std::endl;
    return 0;
}

int test2() {
    auto x = 6.5;  // equal to auto x(6.5);
    auto y = x;    //
    std::cout << y << std::endl;
    return 0;
}

int test3() {
    /*
     * Type Decay:
     *     int& --> int
     *     const int& --> int
     */
    int x = 3;
    int& ref = x;
    auto ref1 = ref;
    // lvalue:ref[int&] --> rvalue: ref[int] -- type decay--> ref1[int]
    std::cout << std::is_same<decltype(ref1), int>::value << std::endl;

    const int& ref2 = x;
    std::cout << std::is_same<decltype(ref2), const int&>::value << std::endl;
    auto ref3 = ref2;
    std::cout << ref2 << " " << ref3 << std::endl;
    // lvalue:ref2[const int&] --> rvalue: ref2[int] -- type decay--> ref3[int]
    std::cout << std::is_same<decltype(ref3), const int>::value << std::endl;
    std::cout << std::is_same<decltype(ref3), int>::value << std::endl;
    /*
     * In this case modification of ref2 and ref3 doesn't affect ref or x
     */
    return 0;
}

int test4() {
    const auto x = 3;
    cout << is_same<decltype(x), const int>::value << endl;

    constexpr auto y = 3;
    cout << is_same<decltype(y), const int>::value << endl;

    const auto& z = 3;
    cout << is_same<decltype(z), const int&>::value << endl;

    const int h = 3;
    const auto f = h;
    cout << is_same<decltype(f), const int>::value << endl;

    // avoid type decay
    const int m = 3;
    auto& w = m;
    cout << is_same<decltype(w), const int&>::value << endl;

    const int& a = 3;
    auto& b = a;
    cout << is_same<decltype(b), const int&>::value << endl;

    return 0;
}

int test5() {
    int x[3] = {1, 2, 3};
    // type decay x[3] --> int*
    auto y = x;
    cout << is_same<decltype(y), int*>::value << endl;

    // avoid type decay
    auto& z = x;
    cout << is_same<decltype(z), int(&)[3]>::value << endl;

    return 0;
}

int main() {
//    test1();
//    test2();
//    test3();
//    test4();
    test5();
    return 0;

}
