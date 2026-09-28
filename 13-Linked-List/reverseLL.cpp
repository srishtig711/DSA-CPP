#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

void print(Node* &head) {

    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

/* Iterative Approach
void reverse(Node* &head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;
    while(curr != NULL) {
        forward = curr->next;
        curr->next = prev;
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
    reverse1(head, curr->next, curr);
    curr->next = prev;
}

void reverse(Node* &head) {
    reverse1(head, head, NULL);
}
*/

// Recursive Approach 3

Node* reverse1(Node* &head) {
    if(head == NULL || head->next == NULL)
        return head;
    Node* newHead = reverse1(head->next);
    head->next->next = head;
    head->next = NULL;
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

    Node* node3 = new Node(30);
    node2->next = node3;

    Node* node4 = new Node(40);
    node3->next = node4;

    cout << "Original Linked List: ";
    print(head);

    reverse(head);

    cout << "Reversed Linked List: ";
    print(head);

    return 0;
}