//
// Created by rongfan on 2022/4/12.
//

#include <iostream>
#include <type_traits>

void nd_array() {
    int x1[3];
    int x2[3][4]; // x2[3] --> int[4]
    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(x2[0]) << std::endl;
    std::cout << std::is_same<decltype(x2[0]), int(&)[4]>::value <<std::endl;

    int x3[3][4] = {1, 2, 3, 4, 5}; // x3 = (1, 2, 3, 4) (5, 0, 0, 0) (0, 0, 0, 0)
    int x4[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}};

}

void iter_array() {
    int x[3][4] = {1, 2, 3, 4, 5};
    for (auto& p : x) {              // avoid implicit type change
        for (auto q : p) {
            std::cout << q << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    size_t index0 = 0;
    while ( index0 < std::size(x)) {
        size_t index1 = 0;
        while (index1 < std::size(x[index0])) {
            std::cout << x[index0][index1] << " ";
            index1 += 1;
        }
        std::cout << std::endl;
        index0 += 1;
    }

    std::cout << std::endl;
    auto ptr = std::begin(x);
    while (ptr != std::end(x)) {
        auto ptr2 = std::begin(*ptr);
        while (ptr2 != std::end(*ptr)) {
            std::cout << *ptr2 << " ";
            ptr2 += 1;
        }
        ptr += 1;
        std::cout << std::endl;
    }

}

int main() {
//    nd_array();
    iter_array();
    return 0;
}