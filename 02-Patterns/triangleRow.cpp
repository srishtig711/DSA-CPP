#include<iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;
    int row = 1;
    while(row <= n) {
        int j = row;
        while(j <= (row+row-1)) {
            cout << j << " ";
            j += 1;
        }
        cout << endl;
        row += 1;
    }
    return 0;
}