#include<iostream>
using namespace std;

int i=1;  // i Ϊȫ�ֱ��������о�̬�����ڡ�
void other(void);

int main(void)
{ 
    static int a;  // ��̬�ֲ���������ȫ���������ֲ��ɼ���
    int b = -10;  // b, cΪ�ֲ����������ж�̬�����ڡ�
    int c = 0;
    cout << "---MAIN---\n";
    cout <<" i: " << i << " a: " << a << " b: " << b << " c: " << c << endl;//1 0 -10 0
    c = c + 8;
    other();// 33 4 0 15
    cout << "---MAIN---\n";
    cout << " i: " << i << " a: " << a << " b: " << b <<" c: " << c << endl;//33 0 -10 8
    i = i + 10;
    other();  //75 6 4 15
    return 0;
}

void other(void)
{
    static int a = 2;
    static int b;
    // a,bΪ��̬�ֲ�����������ȫ���������ֲ��ɼ���
    //ֻ��һ�ν��뺯��ʱ����ʼ����
    int c = 10;   // CΪ�ֲ����������ж�̬������
    //ÿ�ν��뺯��ʱ����ʼ����
//    a = a + 2;
    i = i + 99;
//    c = c + 5;
    cout << "---OTHER---\n";
    cout << " i: " << i <<" a: "<< a <<" b: " << b << " c: " << c << endl;
    b = a;
}
