//
// Created by rongfan on 2022/5/31.
//


#include <iostream>
#include <vector>

void vector_size() {
    std::vector<int> a{1};
    std::vector<int> b{1, 2, 3};
    std::cout << a.size() << " " << a.max_size() << std::endl;
    for (auto ptr = b.begin(); ptr != b.end(); ++ptr) {
        std::cout << *ptr << std::endl;
    }
}

void vector_compare() {
    std::vector<int> a{1};
    std::vector<int> b{0, 2, 3};
    std::cout << (a > b) << std::endl;
}

void vector_reserve() {
    std::vector<int> a;
    a.reserve(1024);
    // no minding that buffer used up
    // and no need to call new memory
    for (int i = 0; i < 1024; ++i) {
        a.push_back(i);
    }
}

void print_vec(const std::vector<int>& vec) {
    for (auto x: vec) {
        std::cout << " " << x;
    }
    std::cout << "\n";
}

void vector_insert() {
    std::vector<int> vec(3, 100);
    print_vec(vec);

    auto it = vec.begin();
    vec.insert(it + 1, 200);
    print_vec(vec);
}

int main() {
    // some write operations may invalid iterator
    vector_size();
    vector_compare();
    vector_insert();
    return 0;
}
