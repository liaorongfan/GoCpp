//
// Created by rongfan on 2022/2/27.
//
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <thread>
using namespace std;

#define BEGINS(x) namespace x {
#define ENDS(x) }

BEGINS(thread_usage)

void func() {
    cout << "hello world" << endl;
    return ;
}

void print(int a, int b) {
    cout << a << " " << b << endl;
    return ;
}

int main() {
    thread t1(func);         // t1: thread object
    t1.join();               // wait for t1
    thread t2(print, 3, 4);  // another thread | pass parameters to a thread
    t2.join();               // wait for t2
    return 0;
}


ENDS(thread_usage)


BEGINS(prime_count_test)

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int prime_count(int l, int r) {
    int ans = 0;
    for (int i = l; i <= r; i++) {
        ans += is_prime(i);
    }
    return ans;
}

// entry func for multi-thread processing
void worker(int l, int r, int &ret) {
    cout << this_thread::get_id() << " begin" << endl;
    ret = prime_count(l, r);
    cout << this_thread::get_id() << " done" << endl;
    return ;
}

int main() {
    #define batch 5000000
    thread *t[10];
    int ret[10];
    for (int i = 0, j = 1; i < 10; i++, j += batch) {
        t[i] = new thread(worker, j, j + batch - 1, ref(ret[i]));
    }
    for (auto x : t) x->join();  // wait for all threads

    int ans = 0;
    for (auto x : ret) ans += x;
    for (auto x : t) delete x;   // delete every thread object
    cout << ans << endl;
    return 0;
}

ENDS(prime_count_test)
/*
 * when compile using command
 * $ g++ -pthread thread_pool.cpp
 */

#include <mutex>
int ans = 0;
std::mutex m_mutex;
BEGINS(prime_count_test1)

    bool is_prime(int x) {
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    void prime_count(int l, int r) {
        cout << this_thread::get_id() << " begin" << endl;
        for (int i = l; i <= r; i++) {
            unique_lock<mutex> lock(m_mutex);
            ans += is_prime(i);
            lock.unlock();
        }
        cout << this_thread::get_id() << " done" << endl;
        return ;
    }

    int main() {
        #define batch 5000000
        thread *t[10];
        for (int i = 0, j = 1; i < 10; i++, j += batch) {
            t[i] = new thread(prime_count, j, j + batch - 1);
        }
        for (auto x : t) x->join();  // wait for all threads
        for (auto x : t) delete x;   // delete every thread object
        cout << ans << endl;
        return 0;
    }

ENDS(prime_count_test1)


BEGINS(prime_count_test2)

    bool is_prime(int x) {
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    void prime_count(int l, int r) {
        cout << this_thread::get_id() << " begin" << endl;
        for (int i = l; i <= r; i++) {
            int ret = is_prime(i);
            __sync_fetch_and_add(&ans, ret);
        }
        cout << this_thread::get_id() << " done" << endl;
        return ;
    }

    int main() {
        #define batch 5000000
        thread *t[10];
        for (int i = 0, j = 1; i < 10; i++, j += batch) {
            t[i] = new thread(prime_count, j, j + batch - 1);
        }
        for (auto x : t) x->join();  // wait for all threads
        for (auto x : t) delete x;   // delete every thread object
        cout << ans << endl;
        return 0;
    }

ENDS(prime_count_test2)

int main() {
//    thread_usage::main();
//    prime_count_test::main();
//    prime_count_test1::main();
    prime_count_test2::main();
    return 0;
}
