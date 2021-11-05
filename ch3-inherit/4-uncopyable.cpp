/*************************************************************************
	> File Name: 4-uncopyable.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 04 Nov 2021 01:36:55 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;


/*
 *
 * 设计一个类：
 *     类的对象没有办法进行拷贝
 *     拷贝分为两种，1）拷贝构造 2）赋值运算
 * 功能类表示了一类类的性质
 */

#define BEGINS(x) namespace x {  // namespace of x
#define ENDS(x) } // end of namespace

BEGINS(test1)


class UNCOPYABLE {
public:
    // 不可以生成对象
    // 其所有的派生类也没有拷贝构造方法
    UNCOPYABLE(const UNCOPYABLE &) = delete;

    UNCOPYABLE &operator=(const UNCOPYABLE &) = delete;
    // UNCOPYABLE &opetator=(const UNCOPYABLE &) const = delete;
protected: 
    // 将默认构造声明为受保护权限
    UNCOPYABLE() = default;
};


class A: public UNCOPYABLE {
    
};


int main() {
    A a;
    A b;
    // b = a;
    // A b(a); // no, copy constructor delete
    return 0;
}




ENDS(test1)

BEGINS(test2)

class HAS_XY {
public:
    int x, y;
};

class HAS_XYZ: public HAS_XY {
public:
    int z;
};

class A: public HAS_XY {
public:
    A() { x = y = 1; }
};

class B: public HAS_XY {
public:
    B() { x = y = 2; }
};

class C: public HAS_XYZ {
public:
    C() { x = y = z = 3; }
};

class D: public HAS_XY {
public:
    D() { x = y = 4; }
};

class E: public HAS_XYZ {
public:
    E() { x = y = z = 5; }
};


void func(HAS_XY &a) {
    cout << "has xy : ";
    cout << a.x << ", " << a.y << endl;
    return ;
}


void func(HAS_XYZ &a) {
    cout << "has xyz : ";
    cout << a.x << ", " << a.y << ", " << a.z << endl;
    return ;
}


int main() {
    A a;
    B b;
    C c;
    D d;
    E e;
    func(a), func(b), func(c), func(d), func(e); 
    return 0;
}




ENDS(test2)

int main() {
    // test1::main();
    test2::main();
    return 0;
}



