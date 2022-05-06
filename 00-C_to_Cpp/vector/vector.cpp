//
// Created by rongfan on 2022/4/16.
//

#include <iostream>
#include <vector>

void a_vector() {
    std::vector<int> x1;   // default constructor
    std::vector<float> y1;

    int x2[3];
    std::vector<int> x22(3);

    int x3[3] = {1, 2, 3};
    std::vector<int> x33 = {1, 2, 3};

    // x4 = x44 = x444
    std::vector<int> x4(3, 1);
    std::vector<int> x44 = {1, 1, 1};
    std::vector<int> x444{1, 1, 1};  // initializer list

}

void vector_opt() {
    std::vector<int> x(3,1);
    std::cout << x.size() << std::endl;
    std::cout << x.empty() << std::endl;

    std::vector<int> y;
    std::cout << y.size() << std::endl;
    std::cout << y.empty() << std::endl;
    // change num of elements in run time
    x.push_back(2);
    std::cout << x.size() << std::endl;
    x.pop_back();
    std::cout << x.size() << std::endl;

}

void vector_cmp() {
    std::vector<int> x1 = {1, 2, 3};
    std::vector<int> x2 = {1, 3, 2};
    std::cout << (x1 == x2) << std::endl;
    std::cout << (x1 < x2) << std::endl;
}


void vector_iter() {
    std::vector<int> x = {1, 2, 3};
    std::cout << x[2] << " " << x.at(2) << std::endl;

    auto b = x.begin(); // std::begin(x);
    auto e = x.end();   // std::end(x);
    while (b != e) {
        std::cout << *b << std::endl;
        b += 1;
    }

    for (auto val : x) {
        std::cout << val << std::endl;
    }
}

void vector_nd() {
    int a[3][4];
    std::vector<std::vector<int>> x;
    x.push_back(std::vector<int>());
    x[0].push_back(1);
    std::cout << x[0][0] << std::endl;

    std::vector<std::vector<int>> y{{1, 2, 3}, {4, 5}};
    std::cout << y[1][0] << std::endl;
}

void vector_arrow() {
    std::vector<int> x;
    std::vector<int>* ptr = &x;
    std::cout << (*ptr).size() << std::endl;
    std::cout << ptr->size() << std::endl;
}

 int main() {
//    a_vector();
//    vector_opt();
//    vector_cmp();
//    vector_iter();
//    vector_nd();
    vector_arrow();
    return 0;
}