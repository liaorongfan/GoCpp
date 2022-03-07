//
// Created by rongfan on 2022/2/27.
//
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <thread>
#include <functional>
#include <vector>
#include <unordered_map>
#include <queue>
#include <mutex>
#include <condition_variable>
using namespace std;

#define BEGINS(x) namespace x {
#define ENDS(x) }


BEGINS(task_test)

class Task {
public:
    template<typename FUNC_T, typename ...ARGS>
    Task(FUNC_T func, ARGS ...args) {
        this->func = bind(func, forward<ARGS>(args)...);
    }

    void run() {
        func();
        return ;
    }

private:
    function<void()> func;
};

void test() {
    cout << "hello world: function test" << endl;
    return ;
}

void func(int a, int b) {
    cout << "function " << a << " " << b << endl;
    return ;
}

void add_one(int &n) {
    n += 1;
    return ;
}

int main() {
    Task t(func, 3, 4);
    t.run();
    t.run();
    Task t2(test);
    t2.run();

    int n = 1;
    cout << "n = " << n << endl;
//    Task t3(add_one,  n);
    Task t3(add_one,  ref(n));
    t3.run();
    t3.run();
    t3.run();
    t3.run();
    cout << "n = " << n << endl;
    return 0;
}

ENDS(task_test)

BEGINS(thread_pool_test)


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

class Task {
    public:
        template<typename FUNC_T, typename ...ARGS>
        Task(FUNC_T func, ARGS ...args) {
            this->func = bind(func, forward<ARGS>(args)...);
        }

        void run() {
            func();
            return ;
        }

    private:
        function<void()> func;
    };

class ThreadPool {
public:
    ThreadPool(int n = 1)
    : thread_size(n), threads(n), starting(false) {
        this->start();
        return ;
    }

    void worker() {
        // fetch task and execute
        auto id = this_thread::get_id();
        running[id] = true;
        while(running[id]) {
            Task *t = get_task();
            t->run();
            delete t;
        }
    }

    void start() {
        if (starting == true) return ;
        for (int i = 0; i < thread_size; i++) {
            threads[i] = new thread(&ThreadPool::worker, this);
        }
        starting = true;
        return ;
    }

    void stop() {
        if (starting == false) return ;
        for (int i = 0; i < threads.size(); i++) {
            this->add_task(&ThreadPool::stop_running, this);
        }
        for (int i = 0; i < threads.size(); i++) {
            threads[i]->join();
        }
        for (int i = 0; i < threads.size(); i++) {
            delete threads[i];
            threads[i] = nullptr;
        }
        starting = false;
        return ;
    }

    template<typename FUNC_T, typename ...ARGS>
    void add_task(FUNC_T func, ARGS ...args) {
        unique_lock<mutex> lock(m_mutex);
        tasks.push(new Task(func, forward<ARGS>(args)...));
        m_cond.notify_one();
        return ;
    }

    ~ThreadPool() {
        this->stop();
        while (!tasks.empty()) {
            delete tasks.front();
            tasks.pop();
        }
        return ;
    }
private:
    Task *get_task() {
        unique_lock<mutex> lock(m_mutex);
        while (tasks.empty()) m_cond.wait(lock);
        Task *t = tasks.front();
        tasks.pop();
        return t;
    }

    void stop_running() {
        auto id = this_thread::get_id();
        running[id] = false;
        return ;
    }

    bool starting;
    int thread_size;
    std::mutex m_mutex;
    std::condition_variable m_cond;
    vector<thread *> threads;
    unordered_map<decltype(this_thread::get_id()), bool> running;
    queue<Task *> tasks;
};

int main() {
    #define batch 5000000
    ThreadPool tp(5);

    int ret[10];
    for (int i = 0, j = 1; i < 10; i++, j += batch) {
        tp.add_task(worker, j, j + batch - 1, ref(ret[i]));
    }
    tp.stop();

    int ans = 0;
    for (auto x : ret) ans += x;
    cout << ans << endl;

    return 0;
}

ENDS(thread_pool_test)



int main() {
    thread_pool_test::main();
    return 0;
}
