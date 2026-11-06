
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void insertAtBottom(stack<int>& st, int x) {
    if(st.empty()) {
        st.push(x);
        return;
    }
    int n = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(n);
}

void reverseStack(stack<int>& st) {
    if(st.empty())
        return;
    int num = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, num);
}

void runTest(vector<int> arr) {
    stack<int> st;
    for (int x : arr) st.push(x);

    reverseStack(st);

    cout << "Reversed (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << '\n';
}

int main() {
    runTest({1, 2, 3, 4, 5});
    runTest({1, 2, 3, 4});
    runTest({10});
    runTest({});
    runTest({5, 5, 5, 5});
    runTest({-1, 0, 10, -5});
    runTest({1, 2});

    return 0;
}
