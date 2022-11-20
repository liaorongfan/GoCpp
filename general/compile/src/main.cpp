//
// Created by rongfan on 2022/5/7.
//

#include <iostream>
#include "person/person.h"
//#include "person.h"

int main() {
    Person person;
    std::cout << "test g++ compile" << std::endl;
    return 0;
}

/*
 * g++:
 * ---------------------
 *      -o output execute file
 *      -c just compile do not link
 *      -E pre-compile
 *      -S assembly compile not to binary code
 *      -g add debug info
 *      -I specify header file directory
 *      --02_static include dependency libs into execute file
 * example:
 *      $ g++ main.cpp person/person.cpp -I ./person
 *
 *      $ ldd a.out
 *      # list dependency libs
 *
 * Compile dynamic link lib:
 * ------------------------
 * e.g:
 *      $ g++ xx.cpp -fpic -shared -o libperson.so
 *      # -fpic : indicates functions in xx.cpp are irrelevant
 *      #         with the file location and locate codes by func name
 *      # -shared : generates dynamic link lib
 *      # -o : lib name s.t. lib<name>.so
 *
 * Use compiled os lib:
 * --------------------
 * set env-path:
 *      $ export LD_LIBRARY_PATH=$PWD
 *      $ g++ main.cpp -L $PWD -l person
 *      # -L : specify .so file path
 *      # -l : specify lib name (not I but L in its lower case)
 *      >>>
 *         linux-vdso.so.1 (0x00007fff591a9000)
 *         libperson.so => /home/rongfan/13-CPP/GoCpp/compile/src/libperson.so (0x00007f5a6337f000)
 *         libstdc++.so.6 => /lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007f5a63149000)
 *         libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f5a62f57000)
 *         libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007f5a62e08000)
 *         /lib64/ld-linux-x86-64.so.2 (0x00007f5a6338b000)
 *         libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007f5a62ded000)
 *      >>>
 */