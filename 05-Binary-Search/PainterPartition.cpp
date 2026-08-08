#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool check(vector<int> &boards, int k, int mid) {
    int painters = 1;
    int time = 0;
    for(int x : boards) {
        time += x;
        if(time <= mid) {
            continue;
        }
        else {
            time = x;
            painters++;
        }
    }
    if(painters <= k) return true;
    return false;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int s = 0;
    int e = 0;
    for(int x : boards) {
        s = max(s, x);
        e += x;
    }
    int ans = s;
    while(s <= e) {
        int mid = s + (e-s);
        if(check(boards, k, mid)) {
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
    vector<int> boards = {2,1,5,6,2,3};
    int painters = 2;
    int time = findLargestMinDistance(boards, painters);
    cout << "Minimum time required is " << time;
    return 0;
}