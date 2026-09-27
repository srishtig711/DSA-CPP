#include<iostream>
using namespace std;

class Node {
    public:     
        int data;
        Node* prev;
        Node* next;
        Node(int d) {
            this->data = d;
            this->prev = NULL;
            this->next = NULL;
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

void print(Node* &head) {
    if(head == NULL) {
        cout << "List is empty." << endl;
    }
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node* &head, Node* &tail, int d) {
    Node* temp = new Node(d);
    if(head == NULL) {
        head = temp;
        tail = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node* &head, Node* &tail, int d) {
    Node* temp = new Node(d);
    if(tail == NULL) {
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int d, int position) {
    if(position == 1) {
        insertAtHead(head, tail, d);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }
    if(temp->next == NULL) {
        insertAtTail(head, tail, d);
        return;
    }
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(Node* &head, int position) {
    if(position == 1) {
        Node* temp = head;
        if(temp->next == NULL) {
            delete temp;
            head = NULL;
            return;
        }
        temp->next->prev = NULL;
        head = temp->next;
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
        if(curr->next == NULL) {
            prev->next = NULL;
            curr->next = NULL;
            curr->prev = NULL;
            delete curr;
            return;
        }
        prev->next = curr->next;
        curr->next->prev = prev;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
}

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    insertAtHead(head, tail, 2);
    print(head);
    insertAtTail(head, tail, 19);
    print(head);
    insertAtPosition(head, tail, 14, 3);
    print(head);
    insertAtPosition(head, tail, 25, 5);
    print(head);
    deleteNode(head, 4);
    print(head);
    deleteNode(head, 1);
    print(head);
    deleteNode(head, 3);
    print(head);
    deleteNode(head, 2);
    print(head);
    deleteNode(head, 1);
    print(head);
    return 0;
}