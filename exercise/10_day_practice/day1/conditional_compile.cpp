#include<iostream>
//using namespace std;

//һ����������ָ��ע��


//��һ��ע�ͷ���
#if 0
//asd
//std::cout << "conditional compile one" << std::endl;

void a_print() {
    int i, j, k, f;
    for (i = 1; i <= 4; i++){
        for (j = 1; j <=30 ; j++) {
            std::cout << " ";
        }
        for (k = 1; k <= 8 - 2 * i; k++) {
            std::cout << " ";
        }
        for (f = 1; f <= 2 * i; f++) {
            std::cout << '#';
        }
        std::cout << std::endl;
    }
    for(i = 1; i <= 3; i++){
        for (j = 1; j <= 30; j++) {
            std::cout << " ";
        }
        for (f = 1; f <= 7 - 2 * i; f++) {
            std::cout << '#';
        }
        std::cout << std::endl;
    }
}

#endif

//��ע��
//��������ָ��
#if 1
//asData

void a_print()
{
    int i, j, k, f;
    for (i = 1; i <= 4; i++){
        for (j = 1; j <=30 ; j++) {
            std::cout << " ";
        }
        for (k = 1; k <= 8 - 2 * i; k++) {
            std::cout << " ";
        }
        for (f = 1; f <= 2 * i; f++) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
    for(i = 1; i <= 3; i++){
        for (j = 1; j <= 30; j++) {
            std::cout << " ";
        }
        for (f = 1; f <= 7 - 2 * i; f++) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
}
#endif

int main() {
    std::cout << "conditional compile" << std::endl;
    a_print();
    return 0;
}



