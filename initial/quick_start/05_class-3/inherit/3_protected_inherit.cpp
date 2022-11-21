/*
������ʽΪprotected�ļ̳г�Ϊ�����̳У������ּ̳з�ʽ�£�
�����public��Ա���������л���protected��Ա��
�����protected��private��Ա���������б���ԭ���ķ���Ȩ��
*/

#include <iostream>
using namespace std;

class Base{
    int x;
protected:
    int getx(){ return x; }
public:
    void setx(int n) {x = n;}
    void showx() {cout << x << endl;}
};

class Derived: protected Base{
    int y;
public:
    void sety(int n) {y = n;}
    void sety() {y = getx();}           // visit protected func in base class
    void showy() { cout << y << endl;}
};

int main(){
    Derived obj;
//    obj.setx(10);  // error
    obj.sety(20);
//    obj.showx();	  // error
    obj.showy(); 
}

/*
���ͣ�
��������������ʾ�������̳лὫ�����public��Ϊprotected��������protected��Ա��
�ⲿȥʹ�ñ�����Ա��ʱ�򣬻ᱨ������setx��showx���ʴ��󣬶����������࣬���ֱ�ӷ��ʻ���ı�����Ա��
���������У�y=getx()���������ʣ�
*/