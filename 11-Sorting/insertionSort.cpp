#include<iostream>
#include<vector>
using namespace std;

void insertion(vector<int>& arr, int n) {
    for(int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i-1;
        while(j >= 0) {
            if(arr[j] > temp)
                arr[j+1] = arr[j];
            else 
                break;
            j--;
        }
        arr[j+1] = temp;
    }
}

int main() {
    vector<int> arr = {1,6,20,4,0,9,-2};
    insertion(arr, 7);
    for(int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}