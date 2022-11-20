#include<iostream> 
using namespace std; 

class Apple 
{ 
    public: 
        // 02_static member function
        static void printMsg() 
        { 
            cout<<"Welcome to Apple!"; 
        } 
}; 

// main function 
int main() 
{ 
    // invoking a 02_static member function
    Apple::printMsg(); 
} 

