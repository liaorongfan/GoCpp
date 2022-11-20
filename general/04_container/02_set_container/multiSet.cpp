//
// Created by rongfan on 2022/6/20.
//
#include <iostream>
#include <set>

using namespace std;

void a_multiset() {
    cout << "======= set ======= " << endl;
    set<int> s1{1, 2, 1, 2};
    for (auto i : s1) {
        cout << i << endl;
    }
    cout << "======= multiset ======= " << endl;
    multiset<int> s2{1, 2, 1, 2};
    for (auto i : s2) {
        cout << i << endl;
    }
}

int main() {
    a_multiset();
    return 0;
}