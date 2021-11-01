/*************************************************************************
	> File Name: 2-succeed_copy.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 02 Nov 2021 12:31:32 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
/*
 * 代码演示：
 *     继承环境下的拷贝行为
 * 
 */


#define BEGINS(x) namespace x {   // namespace of x
#define ENDS(x)  }                // namespace of x


BEGINS(test1)

class ATTR_BASE {
public:
    ATTR_BASE(string name): name(name) {
        cout << "constructor" << name << endl;
    }
    ATTR_BASE(const ATTR_BASE &a): name(a.name)  {
        cout << "default copy constructor : " << name << endl;
    }
    ATTR_BASE &operator=(const ATTR_BASE &a) {
        name = a.name;
        cout << "operator= : " << name << endl;
        return *this;
    }
    ~ATTR_BASE() {
        cout << "destructor : " << name << endl;
    }
    string name;  
};


class ATTR1: public ATTR_BASE {
public:
    ATTR1(string name = " none "): ATTR_BASE(name) {}
};

class ATTR2: public ATTR_BASE {
public:
    ATTR2(string name = " none "): ATTR_BASE(name) {}
};

class Base {
public:
    Base(): attr1("attr1 in Base"), attr2("attr2 in Base") {
        cout << "Base constructor done" << endl;
    }
    Base(const Base &b): attr1(b.attr1), attr2(b.attr2) {
        cout << "Base copy constructor done" << endl;
    }
    Base &operator=(const Base &b) {
        attr1 = b.attr1;
        attr2 = b.attr2;
        cout << "Base operator= done" << endl;
        return *this; 
    }
    ~Base() {
        cout << "Base destructor done" << endl;
    }

private:
    ATTR1 attr1;
    ATTR2 attr2;
};

class A: public Base {
public:
    A(): attr1("attr1 in A"), attr2("attr2 in A") {
        cout << "A constructor done" << endl;
    }
    // 正确的拷贝构造，要显示的调用父类的拷贝构造
    // 否则父类调用的是它的默认构造函数
    A(const A &a): Base(a), attr1(a.attr1), attr2(a.attr2) {
        cout << "A copy constructor done" << endl;
    }
    A &operator=(const A &a) {
        // 显示说明调用父类中的赋值运算符
        this->Base::operator=(a); // default operator= 
        attr1 = a.attr1;
        attr2 = a.attr2;
        cout << "A operator= done " << endl;
        return *this;
    }
    ~A() {
        cout << "A destrctor done" << endl;
    }
private:
    ATTR1 attr1;
    ATTR2 attr2;
};


int main() {
    A a;
    cout << "================== default constructor  =================" << endl << endl;
    A b(a);
    cout << "==================  copy   constructor  =================" << endl << endl;
    b = a;
    cout << "================== operator constructor =================" << endl << endl;
    
    return 0;
}

ENDS(test1)


int main() {
    test1::main();
    return 0;
}
