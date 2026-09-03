#include<iostream>
#include<string>
using namespace std;

void reverse(string& str, int i) {
    int n = str.length();
    if(i >= n/2) 
        return;
    swap(str[i], str[n-i-1]);
    i++;
    reverse(str, i);
}

int main() {
    string st1 = "abcde";
    string st2 = "abcdef";
    reverse(st1, 0);
    reverse(st2, 0);
    cout << st1 << endl;
    cout << st2 << endl;
    return 0;
}