/*************************************************************************
	> File Name: 12-friend.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Oct 2021 04:46:31 PM CST
 ************************************************************************/

#include<iostream>
#include<functional>
using namespace std;

#define BEGINS(x) namespace x {
#define ENDS(x) } // end of namespace x


BEGINS(haizei)
class Point {
public:
    /*
     * 类的有参构造函数：Point(int x, int y): x(x), y(y) {}
     *
     * x(x): 括号内的x表示Point(int x, int y)中的型参
     * 括号外的x 表示成员属性 x
     *
     */
    Point(int x, int y): x(x), y(y) {} 
    
    void output() {
        cout << "INNER: " << x << " " << y << endl;
        return ;
    }
    // 这里返回的是一个临时对象，不可以返回引用，而返回值
    Point operator+(int x) const {  
        return Point(this->x + x, this->y + x);
    }
    // 运算符 返回类型 取决与函数功能设计
    Point &operator+=(int x) {
        this->x += x;
        this->y += x;
        return *this;
    }
    // p++ 将P值加1，但返回加1之前的p值，这里要返回的是值
    // 不需传引用
    Point operator++(int) {
        Point ret(*this);
        this->x += 1;
        this->y += 1;
        return ret;
    }
    // ++p 
    Point &operator++() {
        this->x += 1;
        this->y += 1;
        return *this;
    }
    friend void output(Point &); 
    friend ostream &operator<<(ostream &, const Point &);
    friend Point operator+(const Point &, const Point &);

private:
    int x, y;

};

void output(Point &a) {
    cout << "OUTER: " << a.x << " " << a.y << endl;
    return ;
}

/*
 * 重载输出运算符 << 时， 返回值为 ostream 类型的引用
 * 是方便 运算符的连续使用 << a << b << c;
 *
 */
ostream &operator<<(ostream &out, const Point &p) {
    out << "Point(" << p.x << ", " << p.y << ")";
    return out;
}
/*
 * 类外重载 + 法运算符
 */
Point operator+(const Point &a, const Point &b) {
    return Point(a.x + b.x, a.y + b.y);
}

ENDS(haizei)

BEGINS(test1)
using namespace haizei;
int main() {
    Point p(3, 4), q(5, 6);
    p.output();
    output(p);
    cout << p << endl;
    cout << (p + q) << endl;
    cout << (p + 5) << endl; // 编译器对于 p + 5 => p.operator+(5)
    return 0;
}
ENDS(test1)



BEGINS(test2)
using namespace haizei;

int main() {
    // +=
    Point p(3, 4);
    cout << (p += 5) << endl;
    // p++ , ++p
    cout << "p++ = " << (p++) << endl; 
    cout << "p = " << p << endl;
    cout << "++p = " << (++p) << endl;
    (++p)++;
    cout << "(++p)++" << p << endl;
    return 0;
}

ENDS(test2)


BEGINS(array_object)
/*
 * 数组对像
 *
 *
 */

class Array {
public:
    Array(int n = 100): n(n), data(new int[n]) {}
    // 通过函数重载兼容两种情况 const 和 非 const 类型对象
    int &operator[](int ind) {
        return data[ind];
    }

    const int &operator[](int ind) const {
        return data[ind];
    }

private:
    int n;
    int *data;
};

int main() {
    Array arr;
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    const Array arr2;
    for (int i = 0; i < 10; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}

ENDS(array_object)


BEGINS(function_object)

class Function {
public:
    int operator()(int a, int b) {
        cout << "INNER CLASS : ";
        return a + b;
    }
private:

};

int func1(int a, int b) {
    cout << "INNER FUNC1 : "; 
    return a + b;
}


int main() {
    Function func;
    cout << func(3, 4) << endl;
    /*
     * 函数指针本质上，他在指向一类具有相同外在表现的函数
     * int (*p)(int, int) 表现为 输入两个int类型参数 输出
     * 一个  int类型 返回值
     * 
     * 函数对象：本质上是一个重载了 () 运算符的 对象 
     *
     * Cpp中的函数指针对象 （由function 关键字定义）
     *
     */
    int (*p)(int, int) = func1; // 函数指针定义 
    cout << p(3, 4) << endl;    // 函数指针调用
    function<int(int, int)> q;  // q 函数指针对象
    q = func1;  // 指向 指针函数
    cout<< "q pointer : " << q(3, 4) << endl;
    q = func;   // 指向 函数对象
    cout << "q pointer : " << q(3, 4) << endl;
    return 0;
}



ENDS(function_object)


BEGINS(pointer_object)

struct A {
    A(): x(0), y(0) {}  // 默认构造函数初始化 x , y 为0
    int x, y;
};

ostream &operator<<(ostream &out, const A &a) {
    out << a.x << " " << a.y;
    return out;
}

class Pointer {
public:
    Pointer(A *p = nullptr): p(p) {}
    A *operator->() {return p; } // 返回的是 一个 A 类对象的地址 A* 
    A *operator->() const {return p; } // 返回的是 一个 A 类对象的地址 A* 

    A &operator*() {return *p; } // 返回一个 A 类对象的引用 
    A &operator*() const {return *p; } // 返回一个 A 类对象的引用 

    A *operator+(int n) {return p + n; }
    A *operator+(int n) const {return p + n; }

    A *operator-(int n) {return p - n; }
    A *operator-(int n) const {return p - n; }

    A &operator[](int ind) { return *(p + ind); }
    A &operator[](int ind) const { return *(p + ind); }

    int operator-(const Pointer &p) { return this-> p - p.p;}
    friend ostream &operator<<(ostream &, const Pointer &);

private:
    A *p;
};

ostream &operator<<(ostream &out, const Pointer &p) {
    out << p.p;
    return out;
}

int main() {
    A a, b;
    Pointer p = &a, q = &b;
    cout << a << endl;
    p->x = 3;           // -> 间接引用运算符 . 直接引用运算符
    p->y = 4;
    cout << a << endl;
    cout << *p << endl; // *q * 取值运算符， 取出p地址中的内容
    cout << p << endl;
    cout << (p + 1) << endl;
    cout << (p - 1) << endl;
    cout << (p - q) << endl;   
    cout << p[0] << endl;     
    const Pointer cp = &a;
    cout << *cp << endl;       
    cout << (cp - 1) << endl;
    cout << (cp + 1) << endl;  
    cout << cp[0] << endl;
    return 0;
}



ENDS(pointer_object)




int main() {

    //test2::main();
    //array_object::main();
    //function_object::main();
    pointer_object::main();
    return 0;
}















