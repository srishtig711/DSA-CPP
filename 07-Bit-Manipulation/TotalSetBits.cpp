#include<iostream>
using namespace std;
int SetBits(int a, int b) {
    int count1 = 0, count2 = 0;
    while(a != 0) {
        a = a & (a-1);
        count1++;
    }
    while(b != 0) {
        b = b & (b-1);
        count2++;
    }
    return count1 + count2;
}
int main() {
    int a,b;
    cin >> a >> b;
    int total = SetBits(a,b);
    cout << "Total number of set bits in " << a << " and " << b << " is " << total;
    return 0;
}