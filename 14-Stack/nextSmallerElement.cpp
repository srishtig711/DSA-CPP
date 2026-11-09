#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElement(vector<int>& arr) {
    int n = arr.size();
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i = n-1; i >= 0; i--) {
        while(s.top() && s.top() >= arr[i]) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(arr[i]);
    }
    return ans;
}

void runTest(vector<int> arr) {
    vector<int> ans = nextSmallerElement(arr);

    cout << "Array: ";
    for (int x : arr)
        cout << x << " ";

    cout << "\nNext Smaller: ";
    for (int x : ans)
        cout << x << " ";

    cout << "\n----------------------\n";
}

int main() {
    runTest({4, 8, 5, 2, 25});
    runTest({13, 7, 6, 12});
    runTest({5, 4, 3, 2, 1});
    runTest({1, 2, 3, 4, 5});
    runTest({2, 2, 2, 2});
    runTest({-1, 3, 0, -2, 5});
    runTest({10});
    runTest({});

    return 0;
}
