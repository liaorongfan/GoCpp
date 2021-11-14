/*************************************************************************
	> File Name: 2.vtable.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 14 Nov 2021 01:00:39 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

/*
 * 为什么虚函数可以跟着对象走？
 *     带有虚函数的对象，在它的头8个字节的地址区中，存放着指向
 *     虚函数表的地址，这张表中存放着每一个虚函数
 *
 * 注意：每个类有一个虚函数表，相同类型的对象，指向的虚函数表是
 *       同一张虚函数表
 */



#define BEGINS(x) namespace x {  // namespace of x
#define ENDS(x) }                 // end of namespace x


BEGINS(test1)

class Base {
public: 
    virtual ~Base(){}
};

class A: public Base {
public:
    int x;
};

class B {
public:
    int x;
};


int main() {
    cout <<"sizeof(Base) = " << sizeof(Base) << endl;  // 8字节的虚函数表
    cout <<"sizeof(A)    = " << sizeof(A)    << endl;  // 8字节的虚函数表，4字节的int，4字节的对齐位（为空）
    cout <<"sizeof(B)    = " << sizeof(B)    << endl;  // 4字节 的int 
    return 0;
}


ENDS(test1)


BEGINS(test2)

class Base {
public: 
    virtual void func1() {
        cout << "Base func1" << endl;
    }
    virtual void func2() {
        cout << "Base func2" << endl;
    }
    virtual void func3() {
        cout << "Base func3" << endl;
    }
    // virtual ~Base(){}
};

class A: public Base {
public:
    // override 重写的是基类虚函数表里相应的方法
    void func2() override {
        cout << "A func2" << endl;
        return ;
    }
    int x;
};

class B: public Base {
public:
    void func1() override {
        cout << "B func1" << endl;
        return ;
    }
    void func3() override {
        cout << "B func3" << endl;
        return ;
    }

    int x;
};


typedef void (*func)();

int main() {
    A a;
    B b;
    a.func1();
    a.func2();
    a.func3();
    cout << "-------" << endl;
    b.func1();
    b.func2();
    b.func3();
    cout << "-------" << endl;
    // 函数指针形式 调用 a 对象的第二个虚函数 
    ((func **)(&a))[0][1]();
    cout << "-------" << endl;
    swap(((func **)(&a))[0], ((func **)(&b))[0]);
    ((func **)(&a))[0][0]();
    ((func **)(&a))[0][1]();
    ((func **)(&a))[0][2]();
    return 0;
}


ENDS(tes2)

BEGINS(test3)

class Base {
public: 
    virtual void func(int x) {
        cout << this << " : class Base : "<< x << endl;
        return ;
    }
};

class A: public Base {
public:
    void func(int x) override {
        cout << "this->x = " << this->x << endl;
        cout << this << " : class A : " << x << endl;
        return ;
    }
    int x;
};


typedef void (*func)(void *, int);

int main() {
    A a, b;
    a.x = 1000;
    b.x = 10000;
    a.func(123);
    //this 指针 指向哪个对象 取决于 this指针 被传递的地址
    ((func **)(&a))[0][0](&a, 123);
    ((func **)(&a))[0][0](&b, 123);
    return 0;
}


ENDS(tes3)

int main() {
    // test1::main();
    // test2::main();
    test3::main();

    return 0;
}
