#include<iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;
    int row = 1;
    char ch = 'A';
    while(row <= n) {
        int j = 1;
        while(j <= n) {
            cout << ch;
            j += 1;
            ch += 1;
        }
        cout << endl;
        row += 1;
    }
    return 0;
}