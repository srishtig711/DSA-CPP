#include<iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int row = 1;
    while(row <=n) {
        int col = 1;
        while(col <= (n-row+1)) {
            cout << col;
            col++;
        }
        int star = 1;
        while(star <= (2*(row-1))) {
            cout << "*";
            star++;
        }
        int cols = n-row+1;
        while(cols >= 1) {
            cout << cols;
            cols--;
        }
        cout << endl;
        row++;
    }
    return 0;
}