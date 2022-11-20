//
// Created by rongfan on 2022/6/8.
//
#include <iostream>
#include <vector>
#include <map>


void a_vector() {
    std::vector<int> a{1, 2, 3};
    std::cout << a[1] << std::endl;
}

void a_map_1() {
    std::map<char, int> m{{'a', 4}, {'b', 5}};
    std::cout << m['a'] << std::endl;
}

void a_map_2() {
    std::map<int, bool> m{{3, true}, {4, false}, {1, true}};
    for (auto p : m) {
        std::cout << p.first << " " << p.second << std::endl;
    }

    for  (auto [k, v] : m) {  // g++ --std=c++2a
        std::cout << k << " " << v << std::endl;
    }
//    for (auto ptr = m.begin(); ptr != m.end(); ++ptr) {
//        auto p = *ptr; // std::pair <const int, bool>
//        std::cout << p.first << " " << p.second << std::endl;
//    }
}

void map_insert_erase() {
    std::map<int, bool> m;
    m.insert(std::pair<int, bool>(5, true));
    m.insert(std::pair<int, bool>(6, false));
    for (auto p : m) {
        std::cout << p.first << " " << p.second << std::endl;
    }
    std::cout << " ------ erase element -------- " << std::endl;
    m.erase(5);
    for (auto p : m) {
        std::cout << p.first << " " << p.second << std::endl;
    }

}

void map_index() {
    std::cout << " ----- index ----- " << std::endl;
    std::map<int, int> m{{3, 33}, {4, 44}, {5, 55}};
    std::cout << m.at(3) << std::endl;  // when cross boundary raise error
    std::cout << m[3] << std::endl;        // when cross boundary equals to create a new node
    std::cout << m[100] << std::endl;
}


void map_find() {
    std::cout << "------ map find ------ " << std::endl;
    std::map<int, bool> m;
    m.insert(std::pair<const int, bool>(7, true));
    auto ptr = m.find(7);
    std::cout << ptr->first << " " << ptr->second << std::endl;
}

int main() {
//    a_vector();
//    a_map_1();
//    a_map_2();
    map_index();
//    map_insert_erase();
//    map_find();
    return 0;
}

