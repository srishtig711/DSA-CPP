#include<iostream>
#include<vector>
using namespace std;

void bubble(vector<int>& arr, int n) {
    for(int i = 1; i < n; i++) {
        bool swapped = false;
        for(int j = 0; j < n-i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false)
            break;
    }
}

int main() {
    vector<int> arr = {1,6,20,4,0,9,-2};
    bubble(arr, 7);
    for(int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}