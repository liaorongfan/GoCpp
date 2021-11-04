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
    UNCOPYABLE &opetator=(const UNCOPYABLE &) const = delete;
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


int main() {
    test1::main();
    return 0;
}
