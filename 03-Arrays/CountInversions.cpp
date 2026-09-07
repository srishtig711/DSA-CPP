#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int merge(vector<int>& arr, int s, int e) {
        int mid = s + (e - s) / 2;
        int i = s;
        int j = mid + 1;
        vector<int> temp(e - s + 1);
        int k = 0;
        int count = 0;
        while(i <= mid && j <= e) {
            if(arr[i] > arr[j]) {
                count += (mid - i + 1);
                temp[k++] = arr[j++];
            }
            else {
                temp[k++] = arr[i++];
            }
        }
        while(i <= mid) {
            temp[k++] = arr[i++];
        }
        while(j <= e) {
            temp[k++] = arr[j++];
        }
        for(int x = 0; x < k; x++) {
            arr[s + x] = temp[x];
        }
        return count;
    }

    int mergeSort(vector<int>& arr, int s, int e) {
        if(s >= e)
            return 0;
        int mid = s + (e - s) / 2;
        int left = mergeSort(arr, s, mid);
        int right = mergeSort(arr, mid + 1, e);
        int mergeCount = merge(arr, s, e);
        return left + right + mergeCount;
    }

public:
    int inversionCount(vector<int>& arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};

int main() {
    vector<int> arr = {2,4,1,3,5};
    Solution obj;
    cout << "Inversion Count: " << obj.inversionCount(arr) << endl;
    return 0;
}