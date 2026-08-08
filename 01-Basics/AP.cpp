#include<iostream>
using namespace std;
int AP(int n) {
    int N = 3 * n + 7;
    return N;
}
int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;
    int ans = AP(n);
    cout << n << "th term of AP is " << ans;
    return 0;
}