#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr, int s, int e) {
    int pivot = arr[s];
    int cnt = 0;
    for(int i = s+1; i <= e; i++) {
        if(arr[i] <= pivot) 
            cnt++;
    }
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);
    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex) {
        while(arr[i] <= pivot) {
            i++;
        }
        while(arr[j] > pivot) {
            j--;
        }
        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(vector<int>& arr, int s, int e) {
    if(s >= e)
        return;
    int p = partition(arr, s, e);
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}

int main() {
    vector<int> arr = {1,6,20,4,0,9,-2};
    quickSort(arr, 0, arr.size()-1);
    for(int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}