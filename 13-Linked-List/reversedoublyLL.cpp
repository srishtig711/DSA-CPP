#include <iostream>
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
};

void print(Node* head) {

    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

/* Irerative Approach
void reverse(Node* &head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;
    while(curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        curr->prev = forward;
        prev = curr;
        curr = forward;
    }
    head = prev;
}
*/

/* Recursive Approach 1
void reverse1(Node* &head, Node* curr, Node* prev) {
    if(curr == NULL) {
        head = prev;
        return;
    }
    Node* forward = curr->next;
    reverse1(head, forward, curr);
    curr->next = prev;
    curr->prev = forward;
}

void reverse(Node* &head) {
    reverse1(head, head, NULL);
}
*/

// Recursive Approach 2
Node* reverse1(Node* & head) {
    if(head == NULL || head->next == NULL)
        return head;
    Node* newHead = reverse1(head->next);
    head->next->next = head;
    head->next->prev = head->next->next;
    head->next = NULL;
    head->prev = NULL;
    return newHead;
}

void reverse(Node* &head) {
    head = reverse1(head);
}

int main() {

    Node* node1 = new Node(10);
    Node* head = node1;

    Node* node2 = new Node(20);
    node1->next = node2;
    node2->prev = node1;

    Node* node3 = new Node(30);
    node2->next = node3;
    node3->prev = node2;

    Node* node4 = new Node(40);
    node3->next = node4;
    node4->prev = node3;

    cout << "Original Doubly Linked List: ";
    print(head);

    reverse(head);

    cout << "Reversed Doubly Linked List: ";
    print(head);

    return 0;
}