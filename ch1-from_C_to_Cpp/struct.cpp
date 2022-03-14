//
// Created by rongfan on 2022/3/11.
//
# include <iostream>

struct Point {
    int x;
    int y;
    // introduce function member to better represent
    // data opt(func) and the data itself
    void IncX() {
        x = x + 1;
    }
};

// struct used as parameter type and return type
Point func(Point p) {
    p.x = p.x + 1;
    return p;
}

int main() {
    Point p;
    p.x = 0;
    p.y = 0;
    std::cout << "(x, y) = " << p.x << " " << p.y << std::endl;
    p = func(p);
    std::cout << "(x, y) = " << p.x << " " << p.y << std::endl;
    p.IncX();
    std::cout << "(x, y) = " << p.x << " " << p.y << std::endl;
    return 0;
}