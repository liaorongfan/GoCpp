/*************************************************************************
	> File Name: 07-const_method.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Oct 2021 11:46:19 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define BEGINS(x) namespace x {

#define ENDS(X) }

BEGINS(test1)

class A {
public:
    A() {x = 23800;}
    /*
     * const 在Cpp中得到了一些拓展，使其可以用于修饰方法
     * 当定义 一个对象为 const 类型时：const A a;
     * 逻辑上表示：我们不想修改 对象 a 的成员属性和方法
     * 而一般的成员方法是允许修改成员属性的
     * 所以 逻辑上 将成员方法设定成const类型 限制修改
     * 
     * 如果确实要修改某个成员属性 可用 mutable 修饰
     *
     * Cpp 的一个重要思想：
     * 用严格准确的逻辑将错误暴露在编译阶段
     *
     * 尽量多的访问权限控制可以将错误暴露在编译阶段，编译
     * 器帮助我们找到错误
     *
     * Cpp的设计思想不是以实现功能为目标，而是以准确的逻辑
     * 表述为目标：“不仅要说话， 还要把话说清楚（漂亮）”
     *
     */
    void say() const {
        x = 30000;
        cout << x << endl;
    }
    mutable int x;
};


void main() {
    A a;
    a.say();
    return ;
}

ENDS(test1)

int main() {

    test1::main();

    return 0;
}
