#include<iostream>
using namespace std;

int Sum(int arr[], int size) {
    if(size == 0)
        return 0;
    if(size == 1) 
        return arr[0];
    return (arr[0] + Sum(arr+1, size-1));
}

int main() {
    int arr[7] = {4,8,3,1,5,3,0};
    int n = 7;
    int sum = Sum(arr, n);
    cout << "Sum is " << sum;
    return 0;
}