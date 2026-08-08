#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int>& stalls, int cows, int mid) {
    int count = 1;
    int lastPos = stalls[0];
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPos >= mid) {
            count++;
            lastPos = stalls[i];
            if (count == cows)
                return true;
        }
    }
    return false;
}
int aggressiveCows(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    int s = 1;
    int e = stalls.back() - stalls.front();
    int ans = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (isPossible(stalls, cows, mid)) {
            ans = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return ans;
}
int main() {
    vector<int> stalls = {1, 2, 4, 8, 9};
    int cows = 3;
    cout << aggressiveCows(stalls, cows);
    return 0;
}