#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int d) {
            this->data = d;
            this->next = NULL;
        }
        ~Node() {
            int value = this->data;
            if(this->next != NULL) {
                delete next;
                this->next = NULL;
            }
            cout << "Memory is free for data " << value << endl;
        }
};

void print(Node* &head) {
    if(head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int d, int position) {
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }
    if(temp->next == NULL) {
        insertAtTail(tail, d);
        return;
    }
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(Node* &head, int position) {
    if(position == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else {
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main() {
    Node* node1 = new Node(5);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    insertAtHead(head, 2);
    print(head);
    insertAtTail(tail, 7);
    print(head);
    insertAtPosition(head, tail, 4, 2);
    print(head);
    deleteNode(head, 2);
    print(head);
    deleteNode(head, 3);
    print(head);
    deleteNode(head, 1);
    print(head);
    deleteNode(head, 1);
    print(head);
    return 0;
}