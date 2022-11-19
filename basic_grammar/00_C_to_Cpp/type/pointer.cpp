//
// Created by rongfan on 2022/3/17.
//
#include <iostream>

#define BEGINS(x) namespace x {
#define ENDS(x) }

BEGINS(ref)
// The same pointer points to different reference(address)
int main() {
    int x = 42;
    int y = 56;
    int* p = &x;
    p = &y;
    return 0;
}
ENDS(ref)

BEGINS(len)
// the length of pointer data is fixed
int main() {
    int x = 43;
    char y = 33;

    std::cout << sizeof(x) << std::endl;
    std::cout << sizeof(y) << std::endl;

    int* p1 = &x;
    char* p2 = &y;

    std::cout << sizeof(p1) << std::endl;  // 8 byte
    std::cout << sizeof(p2) << std::endl;  // 8 byte

    return 0;
}
ENDS(len)

BEGINS(address)
// & get address and * get value in the address
int main() {
    int x = 42;
    std::cout << "address of x : " << &x << std::endl;  // reference
    int* p = &x;
    std::cout << "pointer of p : " << p << std::endl;
    std::cout << "value in the address which p points to : " << *p << std::endl; // dereference
    return 0;
}
ENDS(address)

BEGINS(opt)

int main() {
    int x = 42;
    int* p = &x;
    int* q = &x;
    std::cout << p << std::endl;
    // address id increases the size of int (4 byte)
    std::cout << p + 1 << std::endl;
    std::cout << p - 2 << std::endl;
    std::cout << (p == q) << std::endl;
    return 0;
}

ENDS(opt)

BEGINS(void_ptr)
// used as placeholder for pointer variable
// lost the size info of variable
void fun(void* para) {
    std::cout << para << std::endl;
    // std::cout << para + 1 << std::endl;
    // will cause error , void pointer has not size info of var,
    // so adding opt is not allowed
    // and g++ are different clang when compiling
}

int main() {
    int* r = nullptr;
    char* c = nullptr;
    fun(r);
    fun(c);
    return 0;
}

ENDS(void_ptr)

BEGINS(pass_addr)

void fun(int* param) {
    *param = *param + 1;
}

int main() {
    int x = 3;
    fun(&x);
    std::cout << x << std::endl;
    return 0;
}

ENDS(pass_addr)



int* p1;

int main() {
//    ref::main();
//    len::main();
//    address::main();
//    opt::main();
//    void_ptr::main();
    pass_addr::main();
//    std::cout << p1 << std::endl;
//    std::cout << *p1 << std::endl;
/* dereference a non-initial global pointer, it will cause segment-fault
 * because global pointer will be initialized to 0 by default
 * but 0 is not a legal address
*/
    return 0;
}
