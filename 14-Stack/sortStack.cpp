
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void sortedInsert(stack<int>& st, int x) {
    if(st.empty() || (!st.empty() && st.top() < x)) {
        st.push(x);
        return;
    }
    int n = st.top();
    st.pop();
    sortedInsert(st, x);
    st.push(n);
}

void sortStack(stack<int>& st) {
    if(st.empty()) 
        return;
    int num = st.top();
    st.pop();
    sortStack(st);
    sortedInsert(st, num);
}

void runTest(vector<int> arr) {
    stack<int> st;
    for (int x : arr) st.push(x);

    sortStack(st);

    cout << "Sorted (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << '\n';
}

int main() {
    runTest({3, 1, 4, 2, 5});
    runTest({5, 4, 3, 2, 1});
    runTest({1, 2, 3, 4, 5});
    runTest({10});
    runTest({});
    runTest({5, 5, 2, 2, 8});
    runTest({-5, 0, 10, -2, 3});
    runTest({1, 2});

    return 0;
}
