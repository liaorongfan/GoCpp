/*************************************************************************
	> File Name: 14-shared_ptr.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Oct 2021 12:01:21 AM CST
 ************************************************************************/

#include<iostream>
#include<memory>
using namespace std;

#define BEGINS(x) namespace x{
#define ENDS(x) }  // end of namespace x



BEGINS(test1)

class A {
public:
    A() {
        cout << "default constructor" << endl;
    }
    ~A() {
        cout << "destructor" << endl;
    }
};


int main() {

    //A *p = new A();
    //delete p; 
    /* 
     * 智能指针不用手动释放内存，避免内存泄漏
     */
    shared_ptr<A> p = make_shared<A>();
    cout << "p.use_count = " << p.use_count() << endl;
    shared_ptr<A> q = p;
    cout << "p.use_count = " << p.use_count() << endl;
    cout << "q.use_count = " << q.use_count() << endl;

    p = nullptr;
    cout << "q.use_count = " << q.use_count() << endl;
    q = nullptr;
    cout << "end main" << endl;


    return 0;
}

ENDS(test1)

BEGINS(test2)

class A {
public:
    A() {
        cout << "default constructor" << endl;
    }
    ~A() {
        cout << "destructor" << endl;
    }
    shared_ptr<A> p;
};


int main() {
    /*
     * 构造环形引用
     *
     */
    shared_ptr<A> p = make_shared<A>();
    shared_ptr<A> q = make_shared<A>();
    p->p = q;
    q->p = p;
    p = nullptr;
    q = nullptr;
    cout << "end main" << endl;
    return 0;
}

ENDS(test2)

int main() {

    //test1::main();
    test2::main();

    return 0;
}
