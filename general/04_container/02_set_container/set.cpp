//
// Created by rongfan on 2022/6/12.
//

#include <iostream>
#include <set>

void a_set() {
    std::set<int> s{2, 4, 22, 2};
    s.emplace(100);
    s.erase(100);
    s.erase(s.begin());
    for (auto ptr = s.begin(); ptr != s.end(); ++ptr) {
        std::cout << *ptr << std::endl;
    }
    std::cout << "--------------------" << std::endl;
}

void set_comparator() {
    std::set<int, std::greater<int>> s {3, 4, 45, 2, 4};
    for (auto ptr = s.begin(); ptr != s.end(); ++ptr) {
        std::cout << *ptr << std::endl;
    }
}

struct Str {
    int x;
};

bool my_comp(const Str& val1, const Str& val2) {
    return val1.x < val2.x;
}

void define_set_comparator() {
    std::set<Str, decltype(&my_comp)> s({Str{3}, Str{5}}, my_comp);
}

void set_find() {
    std::set<int> s{1, 3, 5};
    auto ptr = s.find(1);
    if (ptr != s.end()) std::cout << *ptr << std::endl;
}

void set_contains() {
    std::set<int> s{1, 3, 5};
    std::cout << s.contains(50) << std::endl; // g++ --std=c++2a set.cpp
    std::cout << s.contains(5) << std::endl;
}


int main() {
    a_set();
    set_comparator();
    define_set_comparator();
    set_find();
    set_contains();
    return 0;
}