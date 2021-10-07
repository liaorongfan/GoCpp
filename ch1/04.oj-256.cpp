/*************************************************************************
	> File Name: 04.oj-256.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Oct 2021 12:59:38 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


struct Data {                              //定义保存数据的结构体      
    int a, b;
};


bool cmp(const Data &a, const Data &b) {  //比较函数
    return a.a * a.b < b.a * b.b;
}


class BigInt: public vector<int> {        //继承自动态数组
public:
    
    BigInt(int x) {                       //类构造函数
        push_back(x);
        process_digit();
    }

    bool operator<(const BigInt &a) {
        // 谁长 谁大
        if (size() - a.size()) return size() < a.size();
        for (int i = size() - 1; i >= 0; --i) {
            if (at(i) - a[i]) return at(i) < a[i];
        }
        return false;
    }

    void operator*=(int x) {
        for (int i = 0; i < size(); i++) at(i) *= x;
        process_digit();
        return ;
    }
    
    void operator/=(int x) {
        int y = 0;
        for (int i = size() - 1; i >=0; --i) {
            y = y * 10 + at(i);
            at(i) = y / x;
            y %= x;
        }
        process_digit();
        return ;
    }

    BigInt operator/(int x) {
        BigInt ret(*this);
        ret /= x;
        return ret;
    }

private:
    
    void process_digit() {//处理大整数进位 at(i):表示vector 第i个索引里的内容
        for (int i = 0; i < size(); i++) {
            if (at(i) < 10) continue;
            if (i + 1 == size()) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        while (size() > 1 && at(size() - 1) == 0) pop_back();//去除前导0
        return ;
    }

};

// 系统不支持 我们自定义的BigInt 数据类型输出， 我们重载 << 运算符
ostream &operator<<(ostream &out, const BigInt &a) {
    
    for (int i = a.size() - 1; i >= 0; --i) {//倒着输出的
        out << a[i];
    }
    return out;
}


int main() {
    int n;                                 //读入数据   
    vector<Data> arr;
    cin >> n;
    for (int i = 0; i <= n; i++){
        Data temp;
        cin >> temp.a >> temp.b;
        arr.push_back(temp);
    }

    sort(arr.begin() + 1, arr.end(), cmp); //排序比较，国王站在第一位不排序

    BigInt ans = 0, p = arr[0].a;             //更新最大值
    for (int i = 1; i <= n; i++) {
        BigInt temp = p / arr[i].b;
        if (ans < temp) ans = temp;
        p *= arr[i].a;
    }
    cout << ans << endl;
    return 0;
}
