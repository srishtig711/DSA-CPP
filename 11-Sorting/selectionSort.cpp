#include<iostream>
#include<vector>
using namespace std;

void selection(vector<int>& arr, int n) {
    for(int i = 0; i < n-1; i++) {
        int minIndex = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
}

int main() {
    vector<int> arr = {1,6,20,4,0,9,-2};
    selection(arr, 7);
    for(int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}