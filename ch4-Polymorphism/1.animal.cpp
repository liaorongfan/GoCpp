/*************************************************************************
	> File Name: 1.animal.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 08 Nov 2021 01:03:06 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;


/*
 * 多态：
 *     指为不同数据类型的实体提供统一的接口
 *
 *
 */


#define BEGINS(x) namespace x {  //  begin of namespace x
#define ENDS(x) }                //end of namespace x   

BEGINS(test1)


class Animal {
public:
    void run() {
        cout << "I don't know how to run " << endl;
        return ;
    }
};


class Cat: public Animal {
public:
    void run() {
        cout << "I can run with four legs" << endl;
        return ;
    }
};


int main() {
    Cat a;
    Animal &b = a;
    Animal *c = &a;
    a.run();  // let the cat run
    b.run();  // let the animal run
    c->run(); // let the animal run

    return 0;
}

/*
 * test1 的测试现象是为了说明：
 *     普通的成员方法是跟着类走的
 *
 *
 *
 */


ENDS(test1)


int main() {
  
    test1::main();


    return 0;
 }
