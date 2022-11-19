/*************************************************************************
	> File Name: 08-deep_copy.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Oct 2021 01:15:30 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


class Vector {
public:
    Vector(int n = 100): n(n), data(new int[n]) {}

    /*
     * int & 表示返回的是 data[ind] 的引用，data[ind]的地址，
     * 不是它的值， 用于外部函数修改 data 数组中的内容
     *
     * 第31行 代码中 arr.at(i) = i; 才起到 将 i 赋值到数组data[i]
     * 的位置中
     */
    int &at(int ind) {return data[ind]; }
    
    int &operator[](int ind) {return data[ind]; }

    void output(int m = -1) {
        if (m == -1) m = n;
        cout << "arr " << this << " : ";
        for (int i = 0; i < m; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
        return ;
    }


private:
    int n;
    int *data;
};


int main() {
    Vector arr;
    //for (int i = 0; i < 10; i++ ) arr.at(i) = i;
    for (int i = 0; i < 10; i++ ) arr[i] = i;
    arr.output(10);
    /* 
     * 类的默认拷贝构造函数是浅拷贝：
     * 将 Vector 类型的对象 arr 拷贝到 Vector 类型的 arr2 对象中
     * 会调用 Vector类在的默认拷贝构造函数，
     * 默认拷贝构造函数将arr中的字段依次拷贝到arr2对应的字段中，
     * 但是arr 的成员data是 指针变量，指向某一个固定的地址，复制
     * 过程中 arr2 的成员属性data也是这一地址。所以在修改arr2中
     * data字段时，arr中的内容也会跟着一起变动。
     *
     *
     */
    Vector arr2(arr);
    arr2.output(10);

    arr2[3] = 10000;

    arr.output(10);
    arr2.output(10);

    return 0;
}
