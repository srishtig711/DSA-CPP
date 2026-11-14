#include <bits/stdc++.h>
using namespace std;

class NStack
{
    int *arr;
    int *next;
    int *top;
    int n;
    int s;
    int freeSpot;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        next = new int[s];
        top = new int[n];
        freeSpot = 0;
        for(int i = 0; i < n; i++) {
            top[i] = -1;
        }
        for(int i = 0; i < s; i++) {
            next[i] = i + 1;
        }
        next[s-1] = -1;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if(freeSpot == -1)
            return false;
        int index = freeSpot;
        arr[index] = x;
        freeSpot = next[index];
        next[index] = top[m-1];
        top[m-1] = index;
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(top[m-1] == -1)
            return -1;
        int index = top[m-1];
        top[m-1] = next[index];
        next[index] = freeSpot;
        freeSpot = index;
        return arr[index];
    }
};

int main()
{
    NStack st(3, 6);

    cout << boolalpha;

    cout << "Push 10 into Stack 1: " << st.push(10, 1) << endl;
    cout << "Push 20 into Stack 1: " << st.push(20, 1) << endl;
    cout << "Push 30 into Stack 2: " << st.push(30, 2) << endl;
    cout << "Push 40 into Stack 3: " << st.push(40, 3) << endl;
    cout << "Push 50 into Stack 2: " << st.push(50, 2) << endl;
    cout << "Push 60 into Stack 3: " << st.push(60, 3) << endl;

    // Overflow test
    cout << "Push 70 into Stack 1: " << st.push(70, 1) << endl;

    cout << "\n--- Pop operations ---\n";

    cout << "Pop Stack 1: " << st.pop(1) << endl;
    cout << "Pop Stack 2: " << st.pop(2) << endl;
    cout << "Pop Stack 3: " << st.pop(3) << endl;

    // Push after freeing positions
    cout << "\n--- Push after pop ---\n";
    cout << "Push 70 into Stack 1: " << st.push(70, 1) << endl;

    cout << "\n--- Remaining elements ---\n";
    cout << "Pop Stack 1: " << st.pop(1) << endl;
    cout << "Pop Stack 1: " << st.pop(1) << endl;
    cout << "Pop Stack 1: " << st.pop(1) << endl;

    cout << "Pop Stack 2: " << st.pop(2) << endl;
    cout << "Pop Stack 2: " << st.pop(2) << endl;

    cout << "Pop Stack 3: " << st.pop(3) << endl;
    cout << "Pop Stack 3: " << st.pop(3) << endl;

    return 0;
}
