//
// Created by rongfan on 2022/4/12.
//

#include <iostream>
#include <cstring>
using namespace std;

void aString() {
    char str[] = "Hello";
    auto ptr = str;

    cout << strlen(str) << endl;
    cout << strlen(ptr) << endl;
}


int main() {
    aString();
    return 0;
}