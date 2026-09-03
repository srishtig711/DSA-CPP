#include<iostream>
#include<string>
using namespace std;

bool checkPalindrome(string st, int i) {
    int n = st.length();
    if(i >= n/2)
        return true;
    if(st[i] != st[n-i-1])
        return false;
    else {
        return checkPalindrome(st, ++i);
    }
}

int main() {
    string st1 = "radar";
    if(checkPalindrome(st1, 0))
        cout << st1 << " is a palindrome";
    else {
        cout << st1 << " is not a palindrome";
    }
    cout << endl;
    string st2 = "tomato";
    if(checkPalindrome(st2, 0))
        cout << st2 << " is a palindrome";
    else {
        cout << st2 << " is not a palindrome";
    }
    return 0;
}