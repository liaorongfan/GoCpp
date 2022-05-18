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


BEGINS(test2)
/*
 * cpp 编程语言的设计哲学是：
 *     用严格的语法逻辑将大多数的错误暴露在编译阶段
 */

class Animal {
public:
    virtual void run() {
        cout << "I don't know how to run " << endl;
        return ;
    }
    virtual void foo() {
        cout << "foo function" << endl;
        return ;  
    }
};


class Cat: public Animal {
public:
    // override 关键字 只是编码规范要求，而不做任何功能上的保证
    void run() override {
        cout << "I can run with four legs" << endl;
        return ;
    }

   // void f00() override {
   //     cout << "f00 function" << endl;
   //     return ;
   // }

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



ENDS(test2)

BEGINS(test3)

class Animal {
public:
    virtual void run() {
        cout << "I don't know how to run " << endl;
        return ;
    }
};


class Cat: public Animal {
public:
    // override 关键字 只是编码规范要求，而不做任何功能上的保证
    void run() override {
        cout << "I can run with four legs" << endl;
        return ;
    }
};

class Human: public Animal {
public:
    void run() override {
        cout << "I can run with two legs" << endl;
        return ;
    }
};

class Bird: public Animal {
public:
    void run() override {
        cout << "I can fly " << endl;
        return ;
    }
};


int main() {
    srand(time(0));
    Animal *arr[10];
    for (int i = 0; i < 10; i++) {
        switch (rand() % 3) {
            case 0: arr[i] = new Cat(); break;
            case 1: arr[i] = new Human(); break;
            case 2: arr[i] = new Bird(); break;
        }
    }
    for (int i = 0; i < 10; i++) {
        arr[i]->run();
    }
    return 0;
}



ENDS(test3)

BEGINS(test4)

class Animal {
public:
    virtual void run() {
        cout << "I don't know how to run " << endl;
        return ;
    }
    virtual ~Animal() {
        cout << "Animal destructor " << endl;
    }
};


class Cat: public Animal {
public:
    // override 关键字 只是编码规范要求，而不做任何功能上的保证
    void run() override {
        cout << "I can run with four legs" << endl;
        return ;
    }
    ~Cat() {
        cout << "Cat destructor" << endl;
    }
};

class Human: public Animal {
public:
    void run() override {
        cout << "I can run with two legs" << endl;
        return ;
    }
    ~Human() {
        cout << "Human destructor" << endl;
    }
};

class Bird: public Animal {
public:
    void run() override {
        cout << "I can fly " << endl;
        return ;
    }
    ~Bird() {
        cout << "Bird destructor" << endl;
    }
};


int main() {
    /*
     * 继承状态下常见的错误是，没办法正确地析构子类
     *
     *
     */
    srand(time(0));
    Animal *p;
    switch (rand() % 3) {
        case 0: p = new Cat();   break;
        case 1: p = new Human(); break;
        case 2: p = new Bird();  break;
    }
    p->run();
    delete p;
    return 0;

}



ENDS(test4)

BEGINS(test5)
/*
 * 纯虚函数：
 *     逻辑上表示父类不知道其子类如何实现该方法，或者它的实现根本不重要
 *     用作接口定义（接口：统一外部对程序内部数据的调用形式）
 *
 * 抽象类：
 *     用作接口定义 
 */


class Animal {
public:
    virtual void run() = 0;
};


class Cat: public Animal {
public:
    // override 关键字 只是编码规范要求，而不做任何功能上的保证
    void run() override {
        cout << "I can run with four legs" << endl;
        return ;
    }
};


int main() {
    Cat a;
    a.run();  // let the cat run
    return 0;
}

ENDS(test5)
int main() {
  
    // test1::main();
    // test2::main();
    // test3::main();
    // test4::main();
    test5::main();


    return 0;
 }
