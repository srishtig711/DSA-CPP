#include<iostream>
using namespace std;

class Stack {
    public:
        int *arr;
        int top;
        int size;
        Stack(int s) {
            this->size = s;
            top = -1;
            arr = new int[s];
        }
        void push(int element) {
            if(top < size-1) {
                top++;
                arr[top] = element;
            }
            else {
                cout << "Stack overflow" << endl;
            }
        }
        void pop() {
            if(top >= 0) {
                top--;
            }
            else {
                cout << "Stack underflow" << endl;
            }
        }
        int peek() {
            if(top >= 0) {
                return arr[top];
            }
            else {
                cout << "Stack underflow";
                return -1;
            }
        }
        bool isEmpty() {
            return top == -1;
        }
        ~Stack() {
            delete[] arr;
        }
};

int main() {
    Stack st(5);
    st.push(5);
    st.push(2);
    st.peek();
    st.isEmpty();
    st.pop();
    st.peek();
    st.push(8);
    st.peek();
    st.push(100);
    st.push(40);
    st.pop();
    st.isEmpty();
    st.peek();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    return 0;
}