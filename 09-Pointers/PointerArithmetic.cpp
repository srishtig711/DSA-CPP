#include<iostream>
using namespace std;

int Sum(int* arr, int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += *(arr+i);
    }
    return sum;
}

int main() {
    int array[5] = {2,5,0,-1,6};
    cout << "Sum of all elements of array is: " << Sum(array, 5);
    return 0;
}