/*************************************************************************
	> File Name: 01.namespace.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Oct 2021 03:49:13 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;


namespace haizei {

    int a, b;

} // end of namespace haizei

namespace haizei {
    int c, d;
}

using namespace haizei;

int main() {
    haizei::a = haizei::b = haizei::c = haizei::d = 1;
    std::cout << haizei::b << std::endl;
    a = b = c = d = 2;
    std::cout << b <<std::endl;
    return 0;
}

