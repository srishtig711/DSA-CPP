#include<iostream>
using namespace std;

const long long MOD = 1000000007;

int factorial(int n) {
    if(n <= 1) 
        return 1;
    return (1LL * factorial(n-1) * n) % MOD;
}

int main() {
    int n1 = 5;
    int n2 = 10;
    int n3 = 100;
    int n4 = 540;
    int n5 = 345;
    int n6 = 1;
    int n7 = 12466;
    cout << "Factorial of " << n1 << " is " << factorial(n1) << endl;
    cout << "Factorial of " << n2 << " is " << factorial(n2) << endl;
    cout << "Factorial of " << n3 << " is " << factorial(n3) << endl;
    cout << "Factorial of " << n4 << " is " << factorial(n4) << endl;
    cout << "Factorial of " << n5 << " is " << factorial(n5) << endl;
    cout << "Factorial of " << n6 << " is " << factorial(n6) << endl;
    cout << "Factorial of " << n7 << " is " << factorial(n7) << endl;
    return 0;
} 