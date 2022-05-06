/*************************************************************************
	> File Name: 1-cat.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 31 Oct 2021 11:32:22 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define BEGINS(x) namespace x { // namespace of x
#define ENDS(x) } // namespace of x


BEGINS(test1)

class Base {

public:
    int x;

protected:
    int y;

private:
    int z;
};


class public_Base: public Base {
public:
    // 类内部的访问权限
    void main() {
        x = 2; // ok, x public
        y = 2; // ok, y protected, 子类可以访问父类的protected属性
        // z = 4; //no， private 子类不可以访问父类的private属性
    }    

};


class protected_Base: protected Base {
public:
    // 类内部的访问权限 
    void main() {
        x = 2;
        y = 2;
        // z = 7;  
    }
};

class private_Base: private Base {
public:
    void main() {
        x = 2;
        y = 3;
        // z = 4;
    }

};

int main() {
    // 类外部的访问权限
    public_Base a;
    a.x = 4; // ok, public inherit public       = public
    // a.y = 3; // no, public inherit protected = protected
    // a.z = 2; // no, public inherit private   = private
    protected_Base b;
    // b.x = 4; // no, public inherit protected  = protected
    
    

    return 0;
}

ENDS(test1)


BEGINS(test2)
// 如何理解子类会继承父类所有的方法
class Base {
public:
    Base(string name): class_name(name) {}
    int x;
    string class_name;
private:
    int y;
};

class A: public Base {
public:
    A(): Base("class_A") {}
};

class B: public Base {
public:
    B(): Base("class_B") {}
};
 
class C: public Base {
public:
    C(): Base("class_C") {}
};

void func(Base &b) {
    cout << "input class : " << b.class_name << endl;
    return ; 
}

int main() {
    /*
     * 在cpp中子类到父类存在隐式类型转换
     * 子类对象在概念上一定是个父类 狗是动物， 猫是动物， 鸟是动物 
     */
    A a;
    B b;
    C c;
    func(a);
    func(b);
    func(c);
    cout << "sizeof(Base) = " << sizeof(Base) << endl;
    cout << "sizeof(A)    = " << sizeof(A) << endl;
    return 0;
}

ENDS(test2)


BEGINS(test3) 
/*
 *  指针在继承场景下的表现
 *
 */
class Base {
public:
    Base(string name): class_name(name) {}
    int x;
    string class_name;
private:
    int y;
};

class A: public Base {
public:
    A(): Base("class_A") {}
};

class B: public Base {
public:
    B(): Base("class_B") {}
};
 
class C: public Base {
public:
    C(): Base("class_C") {}
};

void func(Base *b) {
    cout << "input class : " << b->class_name << endl;
    return ; 
}

int main() {
    /*
     * 在cpp中子类到父类存在隐式类型转换
     * 子类对象在概念上一定是个父类 狗是动物， 猫是动物， 鸟是动物 
     */
    A a;
    B b;
    C c;
    func(&a);
    func(&b);
    func(&c);
    cout << "sizeof(Base) = " << sizeof(Base) << endl;
    cout << "sizeof(A)    = " << sizeof(A) << endl;
    return 0;
}





ENDS(test3) 


BEGINS(test4)

class ATTR_BASE {
public:
    ATTR_BASE(string name): name(name) {
        cout << "constructor" << name << endl;
    }
    ~ATTR_BASE() {
        cout << "destructor : " << name << endl;
    }
    string name;  
};


class ATTR1: public ATTR_BASE {
public:
    ATTR1(string name): ATTR_BASE(name) {}
};

class ATTR2: public ATTR_BASE {
public:
    ATTR2(string name): ATTR_BASE(name) {}
};

class Base {
public:
    Base(): attr1("attr1 in Base"), attr2("attr2 in Base") {
        cout << "Base constructor done" << endl;
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
    ~A() {
        cout << "A destrctor done" << endl;
    }
private:
    ATTR1 attr1;
    ATTR2 attr2;
};


int main() {
    A a;
    return 0;
}

ENDS(test4)



/*
 * 继承的好处
 *   减少重复的代码量
 *   逻辑上的递进关系，逻辑清晰
 */


int main() {

    // test1::main();
    // test2::main();
    // test3::main();
    test4::main();
    return 0;
}
