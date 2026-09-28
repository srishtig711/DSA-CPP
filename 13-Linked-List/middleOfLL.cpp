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

void print(Node* head) {

    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

/* Approach 1
Node* findMiddle(Node* head) {
    if(head == NULL || head->next == NULL)
        return head;
    int len = 0;
    Node* temp = head;
    while(temp != NULL) {
        temp = temp->next;
        len++;
    }
    int ans = (len/2) + 1;
    temp = head;
    int cnt = 1;
    while(cnt < ans) {
        temp = temp->next;
        cnt++;
    }
    return temp;
}
*/

// Approach 2
Node* findMiddle(Node* head) {
    if(head == NULL || head-> next == NULL)
        return head;
    if(head->next->next == NULL) 
        return head->next;
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL)
            fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

int main() {

    Node* node1 = new Node(10);
    Node* head1 = node1;

    Node* node2 = new Node(20);
    node1->next = node2;

    Node* node3 = new Node(30);
    node2->next = node3;

    Node* node4 = new Node(40);
    node3->next = node4;

    Node* node5 = new Node(50);
    node4->next = node5;

    cout << "Odd length list: ";
    print(head1);

    Node* middle1 = findMiddle(head1);

    cout << "Middle: " << middle1->data << endl;

    Node* node6 = new Node(10);
    Node* head2 = node6;

    Node* node7 = new Node(20);
    node6->next = node7;

    Node* node8 = new Node(30);
    node7->next = node8;

    Node* node9 = new Node(40);
    node8->next = node9;

    cout << "\nEven length list: ";
    print(head2);

    Node* middle2 = findMiddle(head2);

    cout << "Middle: " << middle2->data << endl;

    return 0;
}