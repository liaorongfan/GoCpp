/*************************************************************************
	> File Name: 02.0j-166.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Sep 2021 11:53:37 PM CST
 ************************************************************************/
#include<string>
#include<iostream>
using namespace std;


int main() {
    string a, b;
    int pos;
    cin >> a >> pos >> b;

    cout << min(100, (int)a.size()) << endl;

    a.insert(pos - 1, b);
    cout << a << endl;

    cout << a.size() - a.rfind("x") << endl;

    return 0;
}
