#include<iostream>

double power(double x, int n);


int main(int argc, char const *argv[]) {
    double x, y;
    int n;
    std::cout << "input value of x : " << std::endl;
    std::cin >> x;
    std::cout << "input value of n : " << std::endl;
    std::cin >> n;
    y = power(x, n);
    std::cout << "the " << n << " power of " << x << " is " << y << std::endl;
    return 0;
}


double power(double x, int n) {
    double val = 1.0;
    while(n--) {
        val *= x;
    }
    return val;
}
