#include<iostream>
using namespace std;

//常引用做形参，在函数中不能更新 r所引用的对象。
void display(const double& r) {
    cout << r << endl;
}

class A {
public:
    A(int i, int j) {x = i; y = j;}
private:
    int x, y;
};

int main() {
    double d(9.5);
    display(d);
    A const a(3,4); //a是常对象，不能被更新
    return 0;
}


