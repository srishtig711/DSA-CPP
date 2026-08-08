#include<iostream>
using namespace std;
int sum(int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}                             
int main() {
    int n;
    int arr[100];
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter elements of array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Sum of array elements is " << sum(arr ,n);
    return 0;
}