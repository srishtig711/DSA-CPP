#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* createList(vector<int> arr) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int val : arr) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

/* Approach 1
Node* sortList(Node* head) {
    int zero = 0;
    int one = 0;
    int two = 0;
    Node* temp = head;
    while(temp != nullptr) {
        if(temp->data == 0)
            zero++;
        else if(temp->data == 1)
            one++;
        else if(temp->data == 2)
            two++;
        temp = temp->next;
    }
    temp = head;
    while(temp != nullptr && zero) {
        temp->data = 0;
        zero--;
        temp = temp->next;
    }
    while(temp != nullptr && one) {
        temp->data = 1;
        one--;
        temp = temp->next;
    }
    while(temp != nullptr && two) {
        temp->data = 2;
        two--;
        temp = temp->next;
    }
    return head;
}
*/

// Approach 2

void insertAtTail(Node* &tail, Node* curr) {
    tail->next = curr;
    tail = curr;
}

Node* sortList(Node* head) {
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    Node* curr = head;
    while(curr != nullptr) {
        int value = curr->data;
        if(value == 0)
            insertAtTail(zeroTail, curr);
        else if(value == 1)
            insertAtTail(oneTail, curr);
        else if(value == 2) 
            insertAtTail(twoTail, curr);
        curr = curr->next;
    }
    if(oneHead->next != nullptr) 
        zeroTail->next = oneHead->next;
    else 
        zeroTail->next = twoHead->next;
    oneTail->next = twoHead->next;
    twoTail->next = nullptr;
    head = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return head;
}

int main() {
    vector<vector<int>> testCases = {
        {1, 0, 2, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {2, 2, 2, 2},
        {2, 1, 0},
        {0, 1, 2},
        {2, 0, 2, 1, 0, 1},
        {},
        {1},
        {0, 2}
    };

    for (int i = 0; i < testCases.size(); i++) {
        Node* head = createList(testCases[i]);

        cout << "Test case " << i + 1 << ":\n";
        cout << "Original: ";
        printList(head);

        head = sortList(head);

        cout << "Sorted:   ";
        printList(head);
        cout << endl;
    }

    return 0;
}
