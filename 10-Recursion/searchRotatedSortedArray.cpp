#include<iostream>
#include<vector>
using namespace std;

int Pivot(vector<int>& arr, int s, int e) {
    if(s == e) 
        return s;
    int mid = s + (e-s)/2;
    if(arr[mid] >= arr[0]) {
        return Pivot(arr, mid+1, e);
    }
    else {
        return Pivot(arr, s, mid);
    }
}

int binary(vector<int>& arr, int s, int e, int k) {
    int mid = s + (e-s)/2;
    while(s <= e) {
        if(arr[mid] == k) {
            return mid;
        }
        if(arr[mid] < k) {
            s = mid + 1;
        }
        else {
            e = mid -1 ;
        }
    }
    return -1;
}

int find(vector<int>& arr, int n, int k) {
    int pivot = Pivot(arr, 0, arr.size()-1);
    if(k >= arr[pivot] && k <= arr[n-1]) {
        return binary(arr, pivot, n-1, k);
    }
    else {
        return binary(arr, 0, pivot-1, k);
    }
}

int main() {
    vector<int> v = {7,9,1,2,3};
    int key = 2;
    int ans = find(v, v.size(), key);
    if(ans != -1) {
        cout << "Element " << key << " found at index " << ans;
    }
    else {
        cout << "Element " << key << " not found.";
    }
    return 0;
}