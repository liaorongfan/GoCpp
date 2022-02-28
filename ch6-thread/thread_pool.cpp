//
// Created by rongfan on 2022/2/27.
//
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <thread>
using namespace std;

#define BEGINS(x) namespace x {
#define ENDS(x) }


BEGINS(thread_pool_test)


int main() {

    return 0;
}

ENDS(thread_pool_test)


int main() {
    thread_pool_test::main();
    return 0;
}
