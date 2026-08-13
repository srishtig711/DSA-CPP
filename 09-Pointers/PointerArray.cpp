#include<iostream>
using namespace std;

int Max(int* arr, int n) {
    int max_Element = *arr;
    for(int i = 1; i < n; i++) {
        if(*(arr+i) > max_Element) {
            max_Element = *(arr+i);
        }
    }
    return max_Element;
}

int main() {
    int array[5] = {4,0,-8,9,6};
    cout << "Maximum element of array is: " << Max(array, 5);
    return 0;
}