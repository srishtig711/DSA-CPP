#include<iostream>
#include<vector>
using namespace std;
bool check(vector<int> &heights, int m, int mid) {
    long long wood = 0;
    for(int x: heights) {
        if(x > mid) {
            wood += (x-mid);
        }
    }
    if(wood >= m) return true;
    return false;
}
int Length(vector<int> &heights, int m) {
    int s = 0;
    int e = heights[0];
    int ans = 0;
    for(int x: heights) {
        e = max(e, x);
    }
    while(s <= e) {
        int mid = s + (e-s)/2;
        if(check(heights, m, mid)) {
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
    vector<int> heights1 = {20,15,10,17};
    int m1 = 7;
    cout << "Maximum height of saw blade required is " << Length(heights1, m1) << endl;
    vector<int> heights2 = {4,42,40,26,46};
    int m2 = 20;
    cout << "Maximum height of saw blade required is " << Length(heights2, m2) << endl;
    return 0;
}