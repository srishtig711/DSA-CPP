#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int d) {
            this->data = d;
            this->next = this;
        }
        ~Node() {
            int value = this->data;
            if(next != NULL) {
                delete next;
                next = NULL;
            }
            cout << "Memory is free for data " << value << endl;
        }
};

void print(Node* &tail) {
    if(tail == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = tail;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != tail);
    cout << endl;
}

void insertNode(Node* &tail, int d, int element) {
    Node* temp = new Node(d);
    if(tail == NULL) {
        tail = temp;
        temp-> next = temp;
    }
    else {
        Node* curr = tail;
        while(curr->data != element) {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
        if(curr == tail) 
            tail = temp;
    }
}

void deleteNode(Node* &tail, int element) {
    if(tail == NULL) {
        cout <<"List is already empty." << endl;
        return;
    }
    Node* prev = tail;
    Node* curr = tail->next;
    while(curr->data != element) {
        prev = curr;
        curr = curr->next;
    }
    if(curr->next == curr) {
        curr->next = NULL;
        delete curr;
        tail = NULL;
    }
    else {
       if(curr == tail)
           tail = prev;  
       prev->next = curr->next;
       curr->next = NULL;
       delete curr;
    }
}

int main() {
    Node* node1 = new Node(10);
    Node* tail = node1;
    print(tail);
    insertNode(tail, 20, 10);
    print(tail);
    insertNode(tail, 15, 10);
    print(tail);
    insertNode(tail, 40, 20);
    print(tail);
    insertNode(tail, 35, 20);
    print(tail);
    deleteNode(tail, 15);
    print(tail);
    deleteNode(tail, 40);
    print(tail);
    deleteNode(tail, 20);
    print(tail);
    deleteNode(tail, 35);
    print(tail);
    deleteNode(tail, 10);
    print(tail);
    return 0;
}