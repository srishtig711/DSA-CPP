#include<iostream>
#include<vector>
using namespace std;

int firstPos(int arr[], int s, int e, int k) {
    if(s > e)
        return -1;
    int first = -1;
    int mid = s + (e-s)/2;
    if(arr[mid] == k) {
        first = mid;
        int leftResult = firstPos(arr, s, mid-1, k);
        if(leftResult != -1)
            first = leftResult;
    }
    else if(arr[mid] < k) {
        return firstPos(arr, mid+1, e, k);
    }
    else {
        return firstPos(arr, s, mid-1, k);
    }
    return first;
}

int lastPos(int arr[], int s, int e, int k) {
    if(s > e)
        return -1;
    int last = -1;
    int mid = s + (e-s)/2;
    if(arr[mid] == k) {
        last = mid;
        int rightResult = lastPos(arr, mid+1, e, k);
        if(rightResult != -1)
            last = rightResult;
    }
    else if(arr[mid] < k) {
        return lastPos(arr, mid+1, e, k);
    }
    else {
        return lastPos(arr, s, mid-1, k);
    }
    return last;
}

vector<int> Pos(int arr[], int size, int k) {
    return {firstPos(arr, 0, size-1, k), lastPos(arr, 0, size-1, k)};
}

void print(vector<int>& v) {
    for(int x: v)
        cout << x << " ";
}

int main() {
    int arr[11] = {1,3,3,5,5,5,7,9,13,25,30};
    int n = 11;
    int key = 5;
    cout << "First and last positions are ";
    vector<int> ans = Pos(arr, n, key);
    print(ans);
    return 0;
}