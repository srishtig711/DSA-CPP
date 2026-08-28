#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
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

int binary(vector<int>& boards, int s, int e, int k) {
    if(s > e)
        return -1;
    int mid = s + (e-s)/2;
    if(check(boards, k, mid)) {
        int ans = binary(boards, s, mid-1, k);
        if(ans == -1) 
            return mid;
        return ans;
    }
    else {
        return binary(boards, mid+1, e, k);
    }
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int s = *max_element(boards.begin(), boards.end());
    int e = accumulate(boards.begin(), boards.end(), 0);
    return binary(boards, s, e, k);
}
int main() {
    vector<int> boards = {2,1,5,6,2,3};
    int painters = 2;
    int time = findLargestMinDistance(boards, painters);
    cout << "Minimum time required is " << time;
    return 0;
}