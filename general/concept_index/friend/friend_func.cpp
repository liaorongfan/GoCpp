/**
 * @file friend_func.cpp
 * @brief friend
 * @author 光城
 * @version v1
 * @date 2019-08-06
 */

#include <iostream>

using namespace std;

class A
{
public:
    A(int _a):a(_a){};
    friend int geta(A &ca);  ///< friend
private:
    int a;
};

int geta(A &ca) 
{
    return ca.a;
}

int main()
{
    A a(3);    
    cout<<geta(a)<<endl;

    return 0;
}
