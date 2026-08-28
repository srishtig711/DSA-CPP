#include<iostream>
#include<vector>
using namespace std;

int Peak(vector<int>& arr, int s, int e) {
    if(s == e)
        return s;
    int mid = s + (e-s)/2;
    if(arr[mid] < arr[mid+1]) {
        return Peak(arr, mid+1, e);
    }
    else {
        return Peak(arr, s, mid);
    }
}

int main() {
    vector<int> v = {1,3,5,7,6,4,2};
    cout << "Index of peak element is " << Peak(v, 0, v.size()-1);
    return 0;
} 