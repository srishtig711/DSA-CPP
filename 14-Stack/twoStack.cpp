#include <iostream>
#include <vector>
using namespace std;

class TwoStack {
    int* arr;
    int size;
    int top1;
    int top2;

public:
    TwoStack(int n) {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = n;
    }

    // TODO: Push into Stack 1
    void push1(int x) {
        if(top2 - top1 > 0) {
            top1++;
            arr[top1] = x;
        }
        else {
            cout << "Stack overflow" << endl;
        }
    }

    // TODO: Push into Stack 2
    void push2(int x) {
        if(top2 - top1 > 0) {
            top2--;
            arr[top2] = x;
        }
        else {
            cout << "Stack overflow" << endl;
        }
    }

    // TODO: Pop from Stack 1
    int pop1() {
        if(top1 >= 0) {
            int x = arr[top1];
            top1--;
            return x;
        }
        else {
            cout << "Stack underflow" << endl;
            return -1;
        }
    }

    // TODO: Pop from Stack 2
    int pop2() {
        if(top2 < size) {
            int x = arr[top2];
            top2++;
            return x;
        }
        else {
            cout << "Stack underflow" << endl;
            return -1;
        }
    }

    ~TwoStack() {
        delete[] arr;
    }
};

int main() {
    TwoStack st(5);

    // Test Case 1: Push into both stacks
    st.push1(10);
    st.push1(20);
    st.push2(90);
    st.push2(80);

    cout << "Pop Stack 1: " << st.pop1() << '\n'; // Expected: 20
    cout << "Pop Stack 2: " << st.pop2() << '\n'; // Expected: 80

    // Test Case 2: Push after popping
    st.push1(30);
    st.push2(70);

    cout << "Pop Stack 1: " << st.pop1() << '\n'; // Expected: 30
    cout << "Pop Stack 2: " << st.pop2() << '\n'; // Expected: 70

    // Test Case 3: Empty stack
    cout << "Pop Stack 1: " << st.pop1() << '\n'; // Expected: 10
    cout << "Pop Stack 1: " << st.pop1() << '\n'; // Underflow

    return 0;
}
