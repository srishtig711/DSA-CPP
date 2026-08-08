#include<iostream>
#include<vector>
using namespace std;

vector<int> Wave(vector<vector<int>> arr, int nRows, int mCols) {
    vector<int> ans;
    for(int col = 0; col < mCols; col++) {
        if(col & 1) {
            for(int row = nRows - 1; row >= 0; row--) {
                ans.push_back(arr[row][col]);
            }
        }
        else {
            for(int row = 0; row < nRows; row++) {
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}

void Print(vector<int>& arr, int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<vector<int>> nums = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    vector<int> ans = Wave(nums, 3,4);
    Print(ans, 12);
    return 0;
}