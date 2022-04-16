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
}


 int main() {
//    a_vector();
    vector_opt();
    return 0;
}