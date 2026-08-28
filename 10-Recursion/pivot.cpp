#include<iostream>
#include<vector>
using namespace std;

int pivot(vector<int>& arr, int s, int e) {
    if(s == e) 
        return s;
    int mid = s + (e-s)/2;
    if(arr[mid] >= arr[0]) {
        return pivot(arr, mid+1, e);
    }
    else {
        return pivot(arr, s, mid);
    }
}

int main() {
    vector<int> v = {3,8,10,17,1,2};
    cout << "Index of pivot element is " << pivot(v, 0, v.size()-1);
    return 0;
}