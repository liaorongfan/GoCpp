/*************************************************************************
	> File Name: 02_class.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Oct 2021 03:54:13 PM CST
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;

#define BEGINS(x) namespace x {
#define ENDS(x) } // end of namespace x    

BEGINS(haizei)


class People {
public:
    string name;
    int age;
    double height;
    double weight;

    void say(string name); 
    void run();
};

void People::say(string name) {
    cout << "my name is " << this->name << endl;
    cout << "my English name is " << name << endl;
}


ENDS(haizei)

void haizei::People::run() {
    cout << "runing ...." << endl;
}

int main() {
    haizei::People kevin;
    haizei::People henry;
    haizei::People tom; 
    kevin.name = "xiao ming";
    henry.name = "xiao hong";
    tom.name = "xiao li";
    kevin.say("kevin");
    henry.say("henry");
    tom.say("tom");
    kevin.run();

    return 0;
}

