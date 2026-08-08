#include<iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;
    int i = 1;
    int j = 1;
    while(i <= n) {
        int count  = 1;
        while(count <= i) {
            cout << j << " ";
            j += 1;
            count += 1;
        }
        cout << endl;
        i += 1;
    }
    return 0;
}