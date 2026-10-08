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


Node* getCycleStart(Node* head) {
    if(head == nullptr)
        return nullptr;
    Node* fast = head->next;
    Node* slow = head;
    while(fast != slow && fast != nullptr) {
        fast = fast->next;
        if(fast != nullptr)
            fast = fast->next;
        slow = slow->next;
    }
    if(fast == nullptr)
        return nullptr;
    if(fast == slow) {
        fast = head;
        slow = slow->next;
    }
    while(fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}


// Creates a cycle from tail to the node at index cycleTo.
// cycleTo = -1 means no cycle.
void createCycle(Node* head, Node* tail, int cycleTo) {
    if (cycleTo == -1)
        return;

    Node* temp = head;

    for (int i = 0; i < cycleTo; i++)
        temp = temp->next;

    tail->next = temp;
}

void printResult(Node* ans) {
    if (ans == NULL)
        cout << "No cycle" << endl;
    else
        cout << "Cycle starts at node: " << ans->data << endl;
}

void solve(int arr[], int n, int cycleTo) {
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++)
        insertAtTail(head, tail, arr[i]);

    createCycle(head, tail, cycleTo);

    Node* ans = getCycleStart(head);

    printResult(ans);
}

int main() {

    // 1. Cycle starts at head
    int arr1[] = {1, 2, 3, 4, 5};
    solve(arr1, 5, 0);

    // 2. Cycle starts in the middle
    int arr2[] = {10, 20, 30, 40, 50};
    solve(arr2, 5, 2);

    // 3. Cycle starts at last node itself
    int arr3[] = {1, 2, 3, 4};
    solve(arr3, 4, 3);

    // 4. No cycle
    int arr4[] = {5, 6, 7, 8};
    solve(arr4, 4, -1);

    // 5. Single node cycle
    int arr5[] = {100};
    solve(arr5, 1, 0);

    return 0;
}