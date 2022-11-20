//
// Created by rongfan on 2022/2/27.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

#define BEGINS(x) namespace x {
#define ENDS(x) } // end of namespace x

BEGINS(test1)

    template<typename T>
    T add(T a, T b) {
        return a + b;
    }

    template<>
    int add<int>(int a, int b) {
        cout << "int template" << endl;
        return a + b;
    }

    int main() {
        cout << add(3, 4) << endl; // add<int>
        cout << add(3.1, 4.2) << endl; // add<double>
        return 0;
    }

ENDS(test1)

BEGINS(test2)

    template<typename T, typename U>
    class Test {
    public :
        Test() {
            cout << "normal template<T, U>" << endl;
        }
    };

    template<typename T>
    class Test<int, T> {
    public :
        Test() {
            cout << "partial specialization template<int, T>" << endl;
        }
    };

    template<>
    class Test<int, double> {
    public :
        Test() {
            cout << "specialization template<int, double>" << endl;
        }
    };

    int main() {
        Test<string, int> t1;
        Test<int, double> t2; // ?
        Test<int, string> t3;
        return 0;
    }

ENDS(test2)

BEGINS(test3)

    class A {};
    class B {};

    class yes_constructor {
    public :
        static const char *has_constructor;
    };
    const char *yes_constructor::has_constructor = "yes";

    class no_constructor {
    public :
        static const char *has_constructor;
    };
    const char *no_constructor::has_constructor = "no";


    template<typename T>
    class type_trais : public yes_constructor {};

    template<typename T>
    class type_trais<T *> : public no_constructor {};

    template<>
    class type_trais<int> : public no_constructor {};

    template<>
    class type_trais<double> : public no_constructor {};

#define TEST(type) \
    cout << #type << " : " << type_trais<type>::has_constructor << endl;

    int main() {
        TEST(int);
        TEST(A);
        TEST(double);
        TEST(B);
        TEST(string);
        TEST(string *);
        return 0;
    }

#undef TEST

ENDS(test3)

BEGINS(test4)

    class A {};
    class B {};

    class yes_constructor {};
    class no_constructor {};

    template<typename T>
    class type_trais {
    public :
        typedef yes_constructor has_constructor;
    };

    template<typename T>
    class type_trais<T *> {
    public :
        typedef no_constructor has_constructor;
    };

    template<>
    class type_trais<int> {
    public :
        typedef no_constructor has_constructor;
    };

    template<>
    class type_trais<double> {
    public :
        typedef no_constructor has_constructor;
    };

    ostream &operator<<(ostream &out, const yes_constructor &) {
        out << "yes";
        return out;
    }

    ostream &operator<<(ostream &out, const no_constructor &) {
        out << "no";
        return out;
    }

#define TEST(type) \
    cout << #type << " : " << type_trais<type>::has_constructor() << endl;

    int main() {
        TEST(int);
        TEST(A);
        TEST(double);
        TEST(B);
        TEST(string);
        TEST(string *);
        return 0;
    }

#undef TEST

ENDS(test4)

int main() {
    // test1::main();
    // test2::main();
    test3::main();
    return 0;
}



