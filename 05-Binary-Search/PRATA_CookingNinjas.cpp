#include <bits/stdc++.h> 
using namespace std;
bool check(vector<int> &rank, int m, int mid) {
    int dishes = 0;
    for(int i = 0; i < rank.size(); i++) {
        int time = 0;
        for(int j = 1; j <= m; j++) {
            time += rank[i] * j;
            if(time <= mid) {
                dishes++;
                if(dishes >= m) {
                    return true;
                }
            }
            else {
                break;
            }
        }
    }
    return false;
}
int minCookTime(vector<int> &rank, int m) {
    int s = INT_MAX;
    int e = 0;
    int ans = 0;
    for(int x: rank) {
        s = min(s, x);
    }
    for(int i = 1; i <= m; i++) {
        e += s*i;
    }
    while(s <= e) {
        int mid = s + (e-s)/2;
        if(check(rank, m, mid)) {
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
    vector<int> rank1 = {10};
    int m1 = 1;
    cout << "Minimum time required is " << minCookTime(rank1, m1) << endl;
    vector<int> rank2 = {1,2,3,4};
    int m2 = 11;
    cout << "Minimum time required is " << minCookTime(rank2, m2) << endl;
    vector<int> rank3 = {1,2,3,4};
    int m3 = 10;
    cout << "Minimum time required is " << minCookTime(rank3, m3) << endl;
    vector<int> rank4 = {1,1,1,1,1,1,1,1};
    int m4 = 8;
    cout << "Minimum time required is " << minCookTime(rank4, m4) << endl;
    return 0;
}


// Optimal Version with better time complexity.

#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> &rank, int m, long long mid) {
    int dishes = 0;
    for (int r : rank) {
        long long low = 0;
        long long high = m;
        long long maxDishes = 0;
        while (low <= high) {
            long long k = low + (high - low) / 2;
            long long time = 1LL * r * k * (k + 1) / 2;
            if (time <= mid) {
                maxDishes = k;
                low = k + 1;
            } else {
                high = k - 1;
            }
        }
        dishes += maxDishes;
        if (dishes >= m)
            return true;
    }
    return false;
}
long long minCooktime(vector<int> &rank, int m) {
    long long minRank = *min_element(rank.begin(), rank.end());
    long long s = minRank;
    long long e = minRank * 1LL * m * (m + 1) / 2;
    long long ans = e;
    while (s <= e) {
        long long mid = s + (e - s) / 2;
        if (check(rank, m, mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}
int main() {
    vector<int> rank = {1, 2, 3, 4};
    int m = 11;
    cout << minCooktime(rank, m) << endl;
    return 0;
}