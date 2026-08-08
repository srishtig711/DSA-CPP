#include<iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int row = 1;
    while(row <= n) {
        int space = row - 1;
        while(space) {
            cout << " ";
            space--;
        }
        int col = row;
        while(col <= n) {
            cout << col;
            col++;
        }
        cout << endl;
        row++;
    }
    return 0;
}