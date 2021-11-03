/*************************************************************************
	> File Name: 3-multi_succeed.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 04 Nov 2021 12:46:12 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;


#define BEGINS(x) namespace x { // namespace of x
#define ENDS(x) }  // end of namespace x


BEGINS(test1)


class A {
protected:
    A(): x(9973) {}
    int x;
};

class B: virtual public A {

public:
    void setX(int x) {
        cout << "set x : " << &(this->x) << endl;
        this->x = x;
        return ;
    }
};


class C: virtual public A {
public: 
    int getX() {
        cout << "get x : " << &(this->x) << endl; 
        return this->x;
    } 
};


class D: public B, public C {};


int main() {
    D d;
    cout << d.getX() << endl;
    d.setX(10000);
    cout << d.getX() << endl;
    return 0;
}

ENDS(test1)

BEGINS(test2)

class NoObject{
public:
    NoObject() = delete;
    // NoObject(const NoObject &) = delete;
};

int main() {
    NoObject *p = (NoObject *)malloc(sizeof(NoObject));
    NoObject b(*p);
    return 0;
}

ENDS(test2)

int main() {
    
    // test1::main();
    test2::main();
    return 0;
}


/*
 * 工程设计的时候提倡：
 *   单继承实体类（用于产生对象的类） ， 多继承接口类（抽象类）
 *
 *
 */
