#include<iostream>
#include<vector>
using namespace std;
void reverse(vector<int>& arr) {
    int s = 0;
    int e = arr.size() - 1;
    while(s < e) {
        swap(arr[s++], arr[e--]);
    }
}
vector<int> sum(vector<int>& arr1, vector<int>& arr2) {
    vector<int> ans;
    int i = arr1.size() - 1;
    int j = arr2.size() - 1;
    int carry = 0;
    while(i >= 0 && j >= 0) {
        int sum = arr1[i] + arr2[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
        j--;
    }
    while(i >= 0) {
        int sum = arr1[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }
    while(j >= 0) {
        int sum = arr2[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }
    if(carry) {
        ans.push_back(carry);
    }
    reverse(ans);
    return ans;
}
void print(vector<int>& arr) {
    for(int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}
int main() {
    vector<int> a1 = {1,2,3,4};
    vector<int> b1 = {6};
    vector<int> ans1 = sum(a1, b1);
    vector<int> a2 = {9,9,9};
    vector<int> b2 = {9,9,9};
    vector<int> ans2 = sum(a2, b2);
    vector<int> a3 = {8};
    vector<int> b3 = {2,5,6,1};
    vector<int> ans3 = sum(a3, b3);
    print(ans1);
    print(ans2);
    print(ans3);
    return 0;
}