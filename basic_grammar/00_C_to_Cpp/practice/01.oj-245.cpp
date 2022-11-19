/*************************************************************************
	> File Name: 01.oj-245.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Sep 2021 11:17:08 PM CST
 ************************************************************************/

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int main() {

    int n;
    vector<int> arr;
    cin >> n;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());
    int p = arr[n / 2], sum = 0;
    for (int i = 0; i < n; i++) sum += abs(arr[i] - p);
    cout << sum << endl;
    return 0;
}

