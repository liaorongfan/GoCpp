//
// Created by rongfan on 2022/3/19.
//

/*
 * const:
 *     const is introduced in compile stage by compiler,
 *     and it is a concept existing in compiling period
 * usage:
 *     to prevent illegal operation, semantically
 *     to optimize compiling and improve code run-time efficiency
 * example:
 *   int main() {
        const int x = 4;  // declare a read only variable
        // x = 5;  // error: assignment of read-only variable ‘x’
        return 0;
     }
 */

#include <iostream>
#include <type_traits>
#define BEGINS(x) namespace x {
#define ENDS(x) }

BEGINS(const_ptr)
int main() {
    int x = 4;
    int* const prt = &x; // assign an unchanged address in var `prt`

    int y = 3;
//    prt = &y;  // error: assignment of read-only variable ‘prt’

    return 0;
}
ENDS(const_ptr)

BEGINS(constPtrContent)
int main() {
    int x = 4;
    const int* ptr = &x;
//    *ptr = 3;  // error: assignment of read-only location ‘* ptr’
    return 0;
}

ENDS(constPtrContent)

BEGINS(constPtrConvert)

int main() {
    // const int* ---x--> int*
    const int x = 3;
//    int* prt = &x;  // error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
    return 0;
}

ENDS(constPtrConvert)

BEGINS(constRef)

struct str {
    //...consume large memory
};

// Using const ref indicates changing is not allowed
void fun(const str& param) {
    // opts on param are not allowed
}

int main() {
    str s;
    fun(s);

    int x = 3;
    const int y = 4;
    // const reference can be bound to any object
    const int& ref1 = x;
    const int& ref2 = y;
    const int& ref3 = 3;  // on behalf of func call, such as func(3)
    //int& ref4 = 3;
    //error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’

    return 0;
}

ENDS(constRef)

BEGINS(constCompileTime)

int main(){
    int x;
    std::cin >> x;
    const int y1 = x;     // y1 run-time var
    const int y2 = 3;     // y2 compile-time var
    constexpr int y3 = 3; // y3 compile-time var equal to `const int` but certainly for compile-time optimization
    // the type of y3 is `const int` and constexpr is just an indicator
    return 0;
}

ENDS(constCompileTime)



BEGINS(constexprConst)
int main() {
    constexpr const int* ptr = nullptr; // constexpr ---> decorate ---> ptr
    // the type of prt --> const int* const
//    std::cout << std::is_same_v<decltype(ptr), const int* const> << std::endl;
    return 0;
}
ENDS(constexprConst)


int main() {
//    const_ptr::main();
//    constPtrContent::main();
//    constPtrConvert::main();
//    constRef::main();
    constexprConst::main();

    return 0;
}

