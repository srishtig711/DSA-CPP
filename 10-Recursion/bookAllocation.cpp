#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& arr, int m, int mid) {
    int student = 1;
    int pages = 0;
    for (int x : arr) {
        if (pages + x <= mid) {
            pages += x;
        }
        else {
            student++;
            if (student > m || x > mid)
                return false;
            pages = x;
        }
    }
    return true;
}

int binary(vector<int>& arr, int s, int e, int m) {
    if(s > e)
        return -1;
    int mid = s + (e - s) / 2;
    if(isPossible(arr, m, mid)) {
        int possible = binary(arr, s, mid-1, m);
        if(possible == -1)
            return mid;
        return possible;
    }
    else {
        return binary(arr, mid+1, e, m);
    }
}

int bookAllocation(vector<int>& arr, int m) {
    if (m > arr.size())
        return -1;
    int s = *max_element(arr.begin(), arr.end());
    int e = accumulate(arr.begin(), arr.end(), 0);
    return binary(arr, s, e, m);
}

int main() {
    vector<int> arr = {12, 34, 67, 90};
    int students = 2;
    cout << bookAllocation(arr, students);
    return 0;
}