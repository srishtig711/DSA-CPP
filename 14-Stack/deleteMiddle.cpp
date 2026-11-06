
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void deleteMiddle(stack<int>& st, int count, int size) {
    if(count == size/2) {
        st.pop();
        return;
    }
    int num = st.top();
    st.pop();
    deleteMiddle(st, count + 1, size);
    st.push(num);
}

void runTest(vector<int> arr) {
    stack<int> st;
    for (int x : arr) st.push(x);

    deleteMiddle(st, 0, st.size());

    cout << "Result (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
}

int main() {
    runTest({1, 2, 3, 4, 5});
    runTest({1, 2, 3, 4});
    runTest({10});
    runTest({5, 5, 5, 5, 5});
    runTest({-5, 0, 10, -2, 8});
    runTest({1, 2});
    runTest({});

    return 0;
}
