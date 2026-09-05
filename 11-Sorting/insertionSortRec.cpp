#include<iostream>
using namespace std;

void insertion(int* arr, int n, int i) {
    if(i == n)
        return;
    int temp = arr[i];
    int j = i-1;
    while(j >= 0 && arr[j] > temp) {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = temp;
    insertion(arr, n, i+1);
}

int main() {
    int arr[] = {1,6,20,4,0,9,-2};
    insertion(arr, 7, 1);
    for(int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}