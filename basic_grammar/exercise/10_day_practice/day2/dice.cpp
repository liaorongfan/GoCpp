#include<iostream>
#include<cstdlib>

using namespace std;

int roll_dice();

int main(int argc, char const *argv[]) {
    int flag;
    unsigned seed;
    cout << "please input an unsigned int num: " << endl;
    cin >> seed;
    srand(seed);
    int sum = roll_dice();
    int selfdim;

    switch(sum) {
        case 7:
        case 11:
            flag=1;
            break;
        case 2:
        case 3:
        case 12:
            flag=2;
            break;
        default:
            flag=0;
            selfdim = sum;
            break;
    }

    while(flag == 0) {
        sum = roll_dice();
        if(sum == selfdim) {
            flag = 1;
        } else if(sum == 7) {
            flag = 2;
        }
    }

    if(flag == 1) {
        cout<<"player win\n";
    } else {
        cout<<"player loses\n";
    }

    return 0;
}


int roll_dice() {
    int sum=0;
    int dim1 = rand() % 6 + 1;
    int dim2 = rand() % 6 + 1;
    sum = dim1 + dim2;
    cout << "sum = " << dim1 << "+" << dim2 << endl;
    return sum;
}