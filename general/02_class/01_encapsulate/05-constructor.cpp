/*************************************************************************
	> File Name: 05-constructor.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Oct 2021 11:14:30 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
/*
 * cpp的学习重点是关注 程序的执行流程，不是语言语法特性
 * 
 *
 *
 *
 *
 */

class A {
public :
    /*
     * 编译器会自动添加
     * 1) 默认构造函数
     * 2) copy_constructor
     * 3) 默认析构函数
     * 4) 默认赋值运算符
     *
     */
    A(int x): x(x) {
        cout << this << " : 02_class A : " << x << endl;
    }
    A(const A &a) {
        /*
         * 拷贝构造：
         * 一）一定要传引用 &a 而不是型参 a 防止无限递归构造
         * 如果传型参：A(const a)
         *    A b = a；  
         *    表示 b 拷贝自 a, 
         *    1) b 会调用 a 的拷贝构造函数，而 a 也是 A 类型的,即
         *    它的拷贝构造函数 A(const a);
         *    2）编译器尝试将实参 a 拷贝给型参 A(const a)，即调用型参的
         *    拷贝构造 A(const a) 
         *    3) 型参A(const a)再调型参的拷贝构造A(const a)...
         *    无限递归错误
         *
         * 二）一定要用const 
         * int & 表示的引用不能用于绑定匿名对象
         * 1）兼容绑定匿名对像
         * 2）逻辑上的常量限制
         * 3）兼容const类型的拷贝
         *
         */
        cout << this << " : copy from  " << &a << endl;
    }
    void operator=(const A &a) {
        cout << this << " assign from " << &a << endl;
        return ;
    }
    int x;

};


class Data {
public :
    // 初始化列表： 规定了每一个成员属性的构造形式
    Data(): __x(100), __y(100), a(34) {
        cout << "default constructor " << endl;
    }

    int x() {return __x;}
    int y() {return __y;}

    ~Data() {
        cout << "destructor" << endl;
    }
private :
    int __x, __y;
    A a;

};



int main() {

    Data d;
    cout << d.x() << " " << d.y() << endl;
    /*
     * 只有一个参数的含参构造函数，也叫转换构造函数
     * 如下 A a = 45
     * 相当于将 整型 45 转换为 A 类型
     *  
     * 此转换构造函数， 执行了两步构造：
     * 1）构造A(45)的匿名对象，
     * 2）将匿名对象拷贝给对象 a 
     *
     */
    A a = 45;
    cout << "address: " << &a << endl;
    a = 78;
    return 0;
}
