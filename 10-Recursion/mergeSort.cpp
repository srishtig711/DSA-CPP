#include<iostream>
using namespace std;

void merge(int arr[], int s, int e) {
    int mid = s + (e-s)/2;
    int i = s;
    int j = mid + 1;
    int* temp = new int[e-s+1];
    int k = 0;
    while(i <= mid && j <= e) {
        if(arr[i] < arr[j]) 
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while(i <= mid) {
        temp[k++] = arr[i++];
    }
    while(j <= e) {
        temp[k++] = arr[j++];
    }
    for(int x = 0; x < k; x++){
        arr[s+x] = temp[x];
    }
    delete []temp;
}

void mergeSort(int arr[], int s, int e) {
    if(s >= e)
        return;
    int mid = s + (e-s)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    merge(arr, s, e);
}

int main() {
    int arr[] = {1,6,20,4,0,9,-2};
    int n = 7;
    mergeSort(arr, 0, n-1);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}