#include<iostream>
using namespace std;

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 5;
    int b = 2;
    int* p = &a;
    int* q = &b;
    cout << "Values before swapping: " << endl;
    cout << "a = " << a << " b = " << b << endl;
    swap(p, q);
    cout << "Values after swapping: " << endl;
    cout << "a = " << a << " b = " << b << endl;
    return 0;
}