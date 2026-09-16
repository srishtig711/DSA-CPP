#include<iostream>
using namespace std;

class A {
    public:
        int a = 5;
        void fun1() {
            cout << "Class A" << endl;
        }
    };

class D {
    public:
        int b = 2;
        void fun2() {
            cout << "Class D" << endl;
        }
};

class B: public A {
    public:
        void fun3() {
            cout << "Value of a is " << a << endl;
            cout << "Class B" << endl;
        }
};

class C: public A, public D {
    public:
        int sum() {
            cout << "Sum is ";
            return a+b;
        }
        void fun4() {
            cout << "Class C" << endl;
        }
};

int main() {
    C obj;
    cout << obj.a << endl;
    cout << obj.b << endl;
    obj.fun1();
    obj.fun2();
    obj.fun4();
    cout << obj.sum() << endl;
    return 0;
}