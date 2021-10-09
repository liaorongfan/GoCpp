/*************************************************************************
	> File Name: 12-friend.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Oct 2021 04:46:31 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


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
    friend void output(Point &); // 告诉Point类 他的邻居，隔壁老王
    friend ostream &operator<<(ostream &, const Point &);

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

int main() {
    Point p(3, 4);
    p.output();
    output(p);
    cout << p << endl;
    return 0;
}
