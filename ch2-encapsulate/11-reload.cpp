/*************************************************************************
	> File Name: 11-reload.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Oct 2021 03:18:36 PM CST
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<cstdlib>
#include<stdio.h>
#include<cstring>
using namespace std;
/*
 * 如果在一个作用域中 几个函数名字形同 但是参数列表不同 称为函数重载
 * 与返回值没有关系
 *
 * 精细化地选择函数处理流程 
 *
 * 功能：
 *     根据参数类型选择函数功能
 *     通过参数列表提示函数用法
 *     拓展已有功能
 */

int func(int x) {
    return 2 * x;
}


double func(double x) {
    return x + 1000;
}

int ABS(int x) {
    return abs(x);
}

double ABS(double x) {
    return fabs(x);
}

void output_permutation(int ind, int n, int *buff, int *num) {
    if (ind == n) {
        for (int i = 0; i < n; i++) {
            cout << buff[i] << " ";
        }
        cout << endl;
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (num[i]) continue;
        buff[ind] = i;
        num[i] = 1;
        output_permutation(ind + 1, n, buff, num);
        num[i] = 0;
    }
    return ;
}

void output_permutation(int n) {  // 接口
    int num[n + 1], buff[n];
    memset(num, 0, sizeof(num));
    memset(buff, 0, sizeof(buff));
    output_permutation(0, n, buff, num); // 功能实现
    return ;  
}

int main() {
    cout << func(2) << endl;
    cout << func(2.0) << endl;
    cout << ABS(-2.3) << endl;
    cout << ABS(-3) << endl; 
    output_permutation(4);
    return 0;
}
