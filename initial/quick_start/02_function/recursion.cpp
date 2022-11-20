#include<iostream>
using namespace std;

int factorial_opt(int n);

void factorial() {
    int x;
    cout << "input x : ";
    cin >> x;
    cout << factorial_opt(x) << endl;
}

int factorial_opt(int n) {
    if(n==0) {
        return 1;
    } else {
        return n * factorial_opt(n-1);
    }
}

int main() {
    cout << "===== Factorial ------: " << endl;
    factorial();
    return 0;
}