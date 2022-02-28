//
// Created by rongfan on 2022/2/27.
//
/*************************************************************************
	> File Name: 4.template_args.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time:
 ************************************************************************/

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
#define ENDS(x) }

BEGINS(test1)

    class A {
    public :
        A(int x, int y) : x(x), y(y) {}
        int x, y;
    };

    ostream &operator<<(ostream &out, const A &a) {
        out << "Class A : " << a.x << ", " << a.y;
        return out;
    }

    template<typename T>
    void Print(T a) {
        cout << a << endl;
        return ;
    }

    template<typename T, typename ...ARGS>
    void Print(T a, ARGS... args) {
        cout << a << " | ";
        Print(args...);
        return ;
    }

    int main() {
        A a(5, 6);
        Print("hello world");
        Print("hello world", 3, 3.4, a);
        Print(a, 6.7, "hello haizei");
        return 0;
    }

ENDS(test1)

BEGINS(test2)

    template<typename T, typename ...ARGS>
    struct ARG {
        typedef T type;
        typedef ARG<ARGS...> rest;
    };

    template<typename T>
    struct ARG<T> {
        typedef T type;
    };

    template<typename T, typename ... ARGS>
    class Test {
    public :
        T operator()(typename ARG<ARGS...>::type a, typename ARG<ARGS...>::rest::type b) {
            return a + b;
        }
    };

    int main() {
        Test<int, int, int> t1;
        Test<double, double, int> t2;
        cout << t1(3, 4) << endl;
        cout << t2(3.5, 4) << endl;
        return 0;
    }

ENDS(test2)

BEGINS(test3)

    template<typename T, typename ...ARGS>
    struct ARG {
        typedef T type;
        typedef ARG<ARGS...> rest;
    };

    template<typename T>
    struct ARG<T> {
        typedef T type;
        typedef T ftype;
    };

    template<typename T, typename ... ARGS>
    class Test {
    public :
        T operator()(
                typename ARG<ARGS...>::type a,
                typename ARG<ARGS...>::rest::ftype b) {
            return a + b;
        }
    };

    int main() {
        Test<int, int, int> t1;
        Test<double, double, int> t2;
        // Test<double, int, int, int> t3;
        cout << t1(3, 4) << endl;
        cout << t2(3.5, 4) << endl;
        return 0;
    }

ENDS(test3)

BEGINS(test4)

    template<typename T, typename ...ARGS>
    struct ARG {
        typedef T type;
        typedef ARG<ARGS...> rest;
    };

    template<typename T>
    struct ARG<T> {
        typedef T type;
        typedef T ftype;
    };

    template<typename T, typename ... ARGS> class Test;
    template<typename T, typename ... ARGS>
    class Test<T(ARGS...)> {
    public :
        T operator()(
                typename ARG<ARGS...>::type a,
                typename ARG<ARGS...>::rest::ftype b) {
            return a + b;
        }
    };

    int main() {
        Test<int(int, int)> t1;
        Test<double(double, int)> t2;
        // Test<double, int, int, int> t3;
        cout << t1(3, 4) << endl;
        cout << t2(3.5, 4) << endl;
        return 0;
    }

ENDS(test4)

BEGINS(test5)

    template<int M>
    void Print() {
        cout << M << ", ";
        Print<M - 1>();
        return ;
    }

    template<>
    void Print<1>() {
        cout << 1 << endl;
        return ;
    }

    int main() {
        Print<10>();
        Print<5>();
        Print<6>();
        return 0;
    }

ENDS(test5)

BEGINS(test6)

    template<int N, typename T, typename ...ARGS>
    struct ARG {
        typedef typename ARG<N - 1, ARGS...>::type type;
    };

    template<typename T, typename ...ARGS>
    struct ARG<1, T, ARGS...> {
        typedef T type;
    };

    template<typename T>
    struct ARG<1, T> {
        typedef T type;
    };

    template<typename T, typename ...ARGS>
    struct NUM_ARGS {
        static constexpr int r = NUM_ARGS<ARGS...>::r + 1;
    };

    template<typename T>
    struct NUM_ARGS<T> {
        static constexpr int r = 1;
    };

    template<int N>
    struct Zero {
        typedef int no;
    };

    template<>
    struct Zero<0> {
        typedef int yes;
    };

    template<typename T, typename ... ARGS> class Test;
    template<typename T, typename ... ARGS>
    class Test<T(ARGS...)> {
    public :
        typedef typename Zero<2 - NUM_ARGS<ARGS...>::r>::yes TYPE_NUM_2;
        T operator()(
                typename ARG<1, ARGS...>::type a,
                typename ARG<2, ARGS...>::type b) {
            return a + b;
        }
    };

    int main() {
        Test<int(int, int)> t1;
        cout << t1(3, 4) << endl;
        return 0;
    }

ENDS(test6)

int main() {
    // test1::main();
    // test2::main();
    // test3::main();
    // test4::main();
    // test5::main();
    test6::main();
    return 0;
}


