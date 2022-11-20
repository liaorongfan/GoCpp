//
// Created by rongfan on 2022/3/20.
//

// typedef int myInt
// using myInt = int

// typedef int* IntPtr
using IntPtr = int*;

int main() {
    int x = 3, y = 4;
    const int* ptr = &x;
    //  --> (const int)* prt  location read only, values in it cannot be changed
    const IntPtr ptr1 = &x;
    //  --> (const int*) prt1 read only, address can not change

//    *ptr = 4  //  error: assignment of read-only location ‘* ptr’
//    ptr1 = &y  // error: assignment of read-only variable ‘ptr1’

}

