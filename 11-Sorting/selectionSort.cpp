#include<iostream>
using namespace std;

void selection(int* arr, int n, int i) {
    if(i == n-1)
        return;
    int minIndex = i;
    for(int j = i+1; j < n; j++) {
        if(arr[j] < arr[minIndex])
            minIndex = j;
    }
    swap(arr[i], arr[minIndex]);
    selection(arr, n, i+1);
}

int main() {
    int arr[] = {1,6,20,4,0,9,-2};
    selection(arr, 7, 0);
    for(int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}