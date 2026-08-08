#include<iostream>
#include<vector>
using namespace std;
void reverseArray(vector<int> &arr , int m) {
    int s = m + 1;
    int e = arr.size() - 1;
    while(s <= e) {
        swap(arr[s++], arr[e--]);
    }
}
void print(vector<int>& arr, int n) {
    for(int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}
int main() {
    vector<int> arr1 = {1,2,3,5,6,7};
    vector<int> arr2 = {3,5,2,6,10,4,0};
    int n1 = arr1.size();
    int n2 = arr2.size();
    int m1 = 2;
    int m2 = 4;
    reverseArray(arr1, m1);
    reverseArray(arr2, m2);
    print(arr1, n1);
    print(arr2, n2);
    return 0;
}