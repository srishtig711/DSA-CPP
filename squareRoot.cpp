#include<iostream>
using namespace std;

int binary(int n, int s, int e) {
    if(s > e)
        return -1;
    int mid = s + (e-s)/2;
    long long square = 1LL * mid * mid;
    if(square == n) {
        return mid;
    }
    if(square < n) {
        int ans = binary(n, mid+1, e);
        if(ans == -1)
            return mid;
        return ans;
    }
    else {
        return binary(n, s, mid-1);
    }
}

int Sqr(int n) {
    if(n < 2)
        return n;
    return binary(n, 1, n/2);
}

int main() {
    cout << "Square root of 10 is " << Sqr(10) << endl;
    cout << "Square root of 5 is " << Sqr(5) << endl;
    cout << "Square root of 50 is " << Sqr(50) << endl;
    cout << "Square root of 36 is " << Sqr(36) << endl;
    cout << "Square root of 0 is " << Sqr(0) << endl;
    cout << "Square root of 1 is " << Sqr(1) << endl;
    cout << "Square root of 1056 is " << Sqr(1056) << endl;
    return 0;
}