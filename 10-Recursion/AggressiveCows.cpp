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

int binary(vector<int>& stalls, int s, int e, int cows) {
    if(s > e) 
        return -1;
    int mid = s + (e-s)/2;
    if(isPossible(stalls, cows, mid)) {
        int ans = binary(stalls, mid+1, e, cows);
        if(ans == -1)
            return mid;
        return ans;
    }
    else {
        return binary(stalls, s, mid-1, cows);
    }
}

int aggressiveCows(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    int s = 1;
    int e = stalls.back() - stalls.front();
    return binary(stalls, s, e, cows);
}
int main() {
    vector<int> stalls = {1, 2, 4, 8, 9};
    int cows = 3;
    cout << aggressiveCows(stalls, cows);
    return 0;
}