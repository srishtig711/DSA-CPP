#include<bits/stdc++.h>
using namespace std;
int beautifulTriplets(int d, vector<int> arr) {
    unordered_set<int> seen;
    int count = 0;
    for(int x : arr) {
        seen.insert(x);
    }
    for(int x : arr) {
        if((seen.count(x + d)) && (seen.count(x + 2*d))) {
            count++;
        }
    }
    return count;
}
int main() {
    vector<int> arr = {1,2,4,5,7,8,10};
    int d = 3;
    cout << "Number of beautiful triplets are " << beautifulTriplets(d, arr);
    return 0;
}