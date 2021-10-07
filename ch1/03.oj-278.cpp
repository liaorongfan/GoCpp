/*************************************************************************
	> File Name: 03.oj-278.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 01 Oct 2021 12:22:21 AM CST
 ************************************************************************/
#include<set>
#include<iostream>
using namespace std;


typedef pair<int, int> PII;

int main() {

    set<PII> s;
    int n, t = 0;
    cin >> n;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        s.insert(PII(a, t++));
    }
    int sum = 0;
    for (int i = 1; i < n; i++) {
        int a = s.begin()->first; s.erase(s.begin());
        int b = s.begin()->first; s.erase(s.begin());
        sum += a + b;
        s.insert(PII(a + b, t++));
    }
    cout << sum << endl;
    return 0;
}

