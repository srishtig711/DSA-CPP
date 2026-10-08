#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node*& head, Node*& tail, int data) {
    Node* newNode = new Node(data);

    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

bool detectCycle(Node* head) {
    Node* fast = head;
    Node* slow = head;
    while(fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            return true;
    } 
    return false;
}

Node* startNode(Node* head) {
    Node* fast = head;
    Node* slow = head;
    while(true) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            break;
    }
    fast = head;
    while(fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

// Remove the loop if one exists
void removeLoop(Node* head) {
    if(detectCycle(head)) {
        Node* temp = startNode(head);
        Node* prev = temp;
        while(prev->next != temp) {
            prev = prev->next;
        }
        prev->next = nullptr;
    }
    else 
        return;
}

// Creates a loop from tail to node at index loopTo.
// loopTo = -1 means no loop.
void createLoop(Node* head, Node* tail, int loopTo) {
    if (loopTo == -1)
        return;

    Node* temp = head;

    for (int i = 0; i < loopTo; i++)
        temp = temp->next;

    tail->next = temp;
}

void printList(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void solve(int arr[], int n, int loopTo) {
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++)
        insertAtTail(head, tail, arr[i]);

    createLoop(head, tail, loopTo);

    removeLoop(head);

    printList(head);
}

int main() {

    // 1. Loop starts at head
    int arr1[] = {1, 2, 3, 4, 5};
    solve(arr1, 5, 0);

    // 2. Loop starts in the middle
    int arr2[] = {10, 20, 30, 40, 50};
    solve(arr2, 5, 2);

    // 3. Loop starts at last node
    int arr3[] = {1, 2, 3, 4};
    solve(arr3, 4, 3);

    // 4. No loop
    int arr4[] = {5, 6, 7, 8};
    solve(arr4, 4, -1);

    // 5. Single node loop
    int arr5[] = {100};
    solve(arr5, 1, 0);

    return 0;
}