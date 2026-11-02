#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int x) {
            this->data = x;
            this->next = nullptr;
        }
};

class Stack {
    public:
        Node* top;
        Stack() {
            top = nullptr;
        }
        void push(int x) {
            Node* newNode = new Node(x);
            newNode->next = top;
            top = newNode;
        }
        void pop() {
            if(top == nullptr) {
                cout << "Stack is empty";
                return;
            }
            Node* next = top->next;
            top->next = nullptr;
            delete top;
            top = next;
        }
        int peek() {
            if(top == nullptr) {
                cout << "Stack is empty";
                return -1;
            }
            return top->data;
        }
        bool isEmpty() {
            return top == nullptr;
        }
        ~Stack() {
            Node* curr = top;
            while(curr != nullptr) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
};

int main() {
    Stack st;
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