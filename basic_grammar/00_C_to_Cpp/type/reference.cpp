//
// Created by rongfan on 2022/3/19.
//
#include <iostream>
#define BEGINS(x) namespace x {
#define ENDS(x)  }

using namespace std;

BEGINS(normalRef)
int main() {
    int x = 3;
    // reference is the alias of an object
    // and can not be used on literal value which does not have an address in stack
    // when the program is running
    int& ref = x;

    cout << "x : " << x << " ; " << "ref : " << ref << endl;
    x = ref + 1;
    cout << "ref + 1 = " << x << endl;
    ref = x + 1;
    cout << "x + 1 = " << ref << endl;
    ref = ref + 1;
    cout << "ref + 1 = " << ref << endl;
    cout << "x : " << x << " ; " << "ref : " << ref << endl;

    cout << " ======================== " << endl;
    int h = 3, y = 0;
    cout << "h : " << h << " ; y : " << y << endl;
    int& ref1 = h;
    cout << "ref : " << ref1 << " ; h :" << h << endl;
    ref1 = y;
    cout << "ref : " << ref1 << " ; h :" << h << endl;

    /*
     * why reference:
     *     pointer could point to an empty address
     *     pointer could point to an illegal address
     *
     * while initialize a reference var:
     *     it must be an existing var which has a certain address
     * after initialization:
     *     it can't be bounded to other objects
     *
     * so:
     *     introduce reference as a safer solution
     * but:
     *     indeed reference mechanism is realized by pointers, seen as below:
     *
     *     void main() {
     *         int x;
     *         int* ptr = &x; *ptr = 1; // this line has almost the same assemble language as below
     *         int& ref = x; ref = 1;   // except the address of ptr and ref
     *     }                            // see assemble language in https://godbolt.org
     *
     */

    return 0;
}
ENDS(normalRef)

BEGINS(illegalRef)

int& fun() {
    int x;
    return x;  // return an illegal address

    /*
    return x; equals to:

    int& ref = x;
    return ref;
     */
}

int main() {
    int& ref = fun();
    // reference refers to a non-available address since local var x in fun
    // will be destroyed after fun call, semantically.
    // The following usage of `ref` will cause uncertain code behavior
    return 0;
}

ENDS(illegalRef)

int main() {
//    normalRef::main();
    illegalRef::main();
    return 0;
}

