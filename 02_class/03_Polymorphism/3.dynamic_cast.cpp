/*************************************************************************
	> File Name: 3.dynamic_cast.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 14 Nov 2021 02:52:28 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define BEGINS(x) namespace x {
#define ENDS(x) }

BEGINS(test1)

class Base {
public:
    virtual ~Base() {}
};

class A: public Base {

};
class B: public Base {

};
class C: public Base {

};

int main() {
    srand(time(0));

    Base *p;
    switch (rand() % 4) {
        case 0: p = new A(); break;
        case 1: p = new B(); break;
        case 2: p = new C(); break;
        case 3: p = nullptr; break;
    }
    // 类似python中 isinstance()
    // c++ 中dynamic_cast依据虚函数表的来判断不同对象的类型
    A a;
    // 如果p不是空地址
    if (p) ((void **)(p))[0] = ((void **)(&a))[0];
    if (dynamic_cast<A *>(p) != nullptr) {
        cout << "p pointer A 02_class object" << endl;
    } else if (dynamic_cast<B *>(p) != nullptr) {
        cout << "p pointer B 02_class object" << endl;
    } else if (dynamic_cast<C *>(p)) {
        cout << "p pointer C 02_class object" << endl;
    } else {
        cout << "p is nullptr" << endl;
    }


    return 0;
}

ENDS(test1)


int main() {
    test1::main();

    return 0;
}
