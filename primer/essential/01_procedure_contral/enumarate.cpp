#include<iostream>
using namespace std;

enum weekday {
 s, m, t, w, thu, f, s1
};


void day() {
    weekday wek = s;
    cout << " ------ " << wek << endl;
    cout << " ------ " << s << endl;
    cout << " ------ " << f << endl;

    for(int i = s; i != f; i++) {
        cout << "current i : " << i << endl;
        cout << wek + i << endl;
        cout << "----------------" << endl;
    }
}

int main() {
    day();
    return 0;
}

