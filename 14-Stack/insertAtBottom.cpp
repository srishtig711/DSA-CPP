#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void insertAtBottom(stack<int>& st, int x) {
    if(st.empty()) {
        st.push(x);
        return;
    }
    int num = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(num);
}

void runTest(vector<int> arr, int x) {
    stack<int> st;
    for (int val : arr) st.push(val);

    insertAtBottom(st, x);

    cout << "Result (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << '\n';
}

int main() {
    runTest({10, 20, 30, 40}, 5);
    runTest({1}, 99);
    runTest({}, 50);
    runTest({5, 5, 5}, 5);
    runTest({-10, 0, 10}, -20);
    runTest({1, 2}, 3);

    return 0;
}
