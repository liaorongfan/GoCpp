/*************************************************************************
	> File Name: 03-cout.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Oct 2021 04:38:02 PM CST
 ************************************************************************/

#include<iostream>

#define BEGINS(x) namespace x {
#define ENDS(x) }

BEGINS(haizei)
// cout的本质是一个对象


class istream {
public:
    istream &operator>>(int &x);
};


class ostream {
public:
    ostream &operator<<(int x);
    ostream &operator<<(char ch);
 };


istream &istream::operator>>(int &x) {
    scanf("%d", &x);
    return *this;
}

ostream &ostream::operator<<(int x) {
    printf("%d", x);
    return *this;
}

ostream &ostream::operator<<(char x) {
    printf("%c", x);
    return *this;
}

istream cin;

ostream cout;
const char endl = '\n';


ENDS(haizei)



int main() {
    int n, m;
    std::cin >> n >> m;
    std::cout << n << m << std::endl;
    haizei::cin >> n >> m;
    haizei::cout << n << m << haizei::endl;
    return 0;
}
