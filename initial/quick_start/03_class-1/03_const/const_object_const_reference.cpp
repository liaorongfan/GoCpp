#include<iostream>
using namespace std;

//���������βΣ��ں����в��ܸ��� r�����õĶ���
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
    A const a(3,4); //a�ǳ����󣬲��ܱ�����
    return 0;
}


