
#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class MinStack {
    stack<long long> s;
    int mini;

public:
    MinStack() {
    }

    void push(int data) {
        if (s.empty()) {
            s.push(data);
            mini = data;
            return;
        }

        if (data < mini) {
            s.push(2LL * data - mini);
            mini = data;
        }
        else {
            s.push(data);
        }
    }

    int pop() {
        if (s.empty())
            return -1;

        long long element = s.top();
        s.pop();

        if (element < mini) {
            int top = mini;
            mini = 2LL * mini - element;
            return top;
        }
        else {
            return element;
        }
    }

    int top() {
        if (s.empty())
            return -1;

        long long element = s.top();

        if (element < mini)
            return mini;
        else
            return element;
    }

    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        if (s.empty())
            return -1;

        return mini;
    }
};

int main() {

    // Test Case 1
    cout << "Test Case 1\n";
    MinStack st1;

    st1.push(10);
    st1.push(5);
    st1.push(3);
    st1.push(7);

    cout << "Top: " << st1.top() << endl;
    cout << "Minimum: " << st1.getMin() << endl;
    cout << "Popped: " << st1.pop() << endl;
    cout << "Top: " << st1.top() << endl;
    cout << "Minimum: " << st1.getMin() << endl;

    // Test Case 2: Duplicate minimum
    cout << "\nTest Case 2\n";
    MinStack st2;

    st2.push(4);
    st2.push(2);
    st2.push(2);
    st2.push(6);

    cout << "Minimum: " << st2.getMin() << endl;
    cout << "Popped: " << st2.pop() << endl;
    cout << "Minimum: " << st2.getMin() << endl;
    cout << "Popped: " << st2.pop() << endl;
    cout << "Minimum: " << st2.getMin() << endl;

    // Test Case 3: Negative numbers
    cout << "\nTest Case 3\n";
    MinStack st3;

    st3.push(-5);
    st3.push(-10);
    st3.push(-3);

    cout << "Top: " << st3.top() << endl;
    cout << "Minimum: " << st3.getMin() << endl;
    cout << "Popped: " << st3.pop() << endl;
    cout << "Minimum: " << st3.getMin() << endl;

    // Test Case 4: Integer limits
    cout << "\nTest Case 4\n";
    MinStack st4;

    st4.push(INT_MAX);
    st4.push(INT_MIN);
    st4.push(0);

    cout << "Top: " << st4.top() << endl;
    cout << "Minimum: " << st4.getMin() << endl;
    cout << "Popped: " << st4.pop() << endl;
    cout << "Minimum: " << st4.getMin() << endl;

    // Test Case 5: Empty stack
    cout << "\nTest Case 5\n";
    MinStack st5;

    cout << "Is empty: " << st5.isEmpty() << endl;
    cout << "Pop: " << st5.pop() << endl;
    cout << "Top: " << st5.top() << endl;
    cout << "Minimum: " << st5.getMin() << endl;

    return 0;
}
