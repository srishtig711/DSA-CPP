#include<iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    cout << "Number of Rs.100 notes: " << n/100 << endl;
    n %= 100;
    cout << "Number of Rs.50 notes: " << n/50 << endl;
    n %= 50;
    cout << "Number of Rs.20 notes: " << n/20 << endl;
    n %= 20;
    cout << "Number of Rs.1 notes: " << n/1 << endl;
    n %= 1;
    return 0;
}