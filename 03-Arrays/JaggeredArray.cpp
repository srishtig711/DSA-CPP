#include<iostream>
using namespace std;

int main() {
    int row;
    cout << "Enter number of rows: ";
    cin >> row;
    cout << endl;
    int** arr = new int*[row];
    int* a = new int[row];
    for(int i = 0; i < row; i++) {
        int col;
        cout << "Enter number of columns for row " << i << ": ";
        cin >> col;
        a[i] = col;
        arr[i] = new int[col];
    }
    cout << "Enter elements: " << endl;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < a[i]; j++) {
            cin >> arr[i][j];
        }
    }
    cout << "Array is: " << endl;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < a[i]; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < row; i++) {
        delete [] arr[i];
    }
    delete [] arr;
    delete [] a;
    return 0;
}