#include<iostream>
#include<array>
using namespace std;

void bubble(int* arr, int n) {
    if(n == 0 || n == 1)
        return;
    for(int i = 0; i < n-1; i++) {
        if(arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);
    }
    bubble(arr, n-1);
}

int main() {
    int arr[] = {1,6,20,4,0,9,-2};
    bubble(arr, 7);
    for(int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}