/*************************************************************************
	> File Name: 06-constructor_order.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Oct 2021 01:38:39 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define BEGINS(x) namespace x {

#define ENDS(X) }

BEGINS(test1)
class A {
public:
    A() {
        cout << this << " default constructor" << endl;
    }
    A(int n, int m):
        n(n), m(m),
        arr(nullptr), size(nullptr),
        offset(nullptr) {
        cout << "A(int) constructor" << endl;
    } 
    A(int *size, int *offset): size(size), offset(offset) {
        arr = new int[*size];
        arr += *offset;
        cout << "A(int *size) constructor" << endl;
    }
    ~A() {
        cout << this << "deconstructor" << endl;
        if (arr == nullptr) return ;
        arr -= *offset;
        delete[] arr;
    }
    int *arr, *size, *offset;
    int n, m; 
};


int main() {
    /*
     * 对像析构与定义的顺序相反：
     *
     * 逻辑：
     *     先定义 a 对象，说明 b 对象的构造有可能依赖于 a 对象
     *
     */
    A a(3, 4);
    A b(&a.n, &a.m);
    cout << "&a : " << &a << " &b : " << &b << endl;

    return 0;
}

ENDS(test1)

BEGINS(test2)

class ATTR_1 {
public:
    ATTR_1() {
        cout << "ATTR_1 DEFAULT CONSTRUCTOR" << endl;
    }
    ~ATTR_1() {
        cout << "ATTR_1 DESTRUCTOR" << endl;
    }

};


class ATTR_2 {
public:
    ATTR_2() {
        cout << "ATTR_2 DEFAULT CONSTRUCTOR" << endl;
    }
    ~ATTR_2() {
        cout << "ATTR_2 DESTRUCTOR" << endl;
    }
};

class ATTR_3 {
public:
    ATTR_3() {
        cout << "ATTR_3 DEFAULT CONSTRUCTOR" << endl;
    }
    ~ATTR_3() {
        cout << "ATTR_3 DESTRUCTOR" << endl;
    }

};

class ATTR_4 {
public:
    ATTR_4() {
        cout << "ATTR_4 DEFAULT CONSTRUCTOR" << endl;
    }
    ~ATTR_4() {
        cout << "ATTR_4 DESTRUCTOR" << endl;
    }

};

class A {
    /*
     * 当前对象的构造依赖于它的属性，所以构造过程中
     * 先执行属性的构造函数
     *
     */
public:
    A() {
        cout << "CLASS A CONSTRUCTOR" << endl;
    }
    ~A() {
        cout << "CLASS A DESTRUCTOR" << endl;
    }
    ATTR_1 a1;
    ATTR_2 a2;
    ATTR_3 a3;
    ATTR_4 a4;
};

void main() {
    A a;
    return ;
}

ENDS(test2)


int main() {

    test1::main();
    cout << endl;
    test2::main();

    return 0;
}






