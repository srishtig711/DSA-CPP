#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isArmstrong(int n) {
        if(n == 0)
            return true;
        int num = n;
        int count = 0;
        int sum = 0;
        while(num) {
            num /= 10;
            count++;
        }
        num = n;
        while(num) {
            int digit = num % 10;
            sum += pow(digit, count);
            num /= 10;
        }
        return (sum == n);
    }
};

int main() {
    Solution sol;

    int n1 = 153;
    int n2 = 12;
    int n3 = 370;

    cout << n1 << " -> " << boolalpha << sol.isArmstrong(n1) << endl;
    cout << n2 << " -> " << boolalpha << sol.isArmstrong(n2) << endl;
    cout << n3 << " -> " << boolalpha << sol.isArmstrong(n3) << endl;

    return 0;
}