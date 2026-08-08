#include<iostream>
using namespace std;
int main() {
    char c;
    cout << "Enter character: ";
    cin >> c;
    if((c >= 'a') && (c <= 'z')) {
        cout << "This is lowercase.";
    }
    else if((c >= 'A') && (c <= 'Z')) {
        cout << "This is uppercase.";
    }
    else if((c >= '0') && (c <= '9')) {
        cout << "This is numeric.";
    }
    return 0;
}