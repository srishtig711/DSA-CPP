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
int bookAllocation(vector<int>& arr, int m) {
    if (m > arr.size())
        return -1;
    int s = *max_element(arr.begin(), arr.end());
    int e = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (isPossible(arr, m, mid)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return ans;
}
int main() {
    vector<int> arr = {12, 34, 67, 90};
    int students = 2;
    cout << bookAllocation(arr, students);
    return 0;
}