//
// Created by rongfan on 2022/5/6.
//
#include <iostream>
/*
 * pass arguments to main function
 */

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " para_1 para_2 \n";
        return -1;
    }

    std::cout << "argc = " << argc << std::endl;
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << "\n";
    }
    return 0;
}
