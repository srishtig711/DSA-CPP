#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = nullptr;
    }
};

void insertAtTail(Node*& head, Node*& tail, int data) {
    Node* newNode = new Node(data);

    if (head == nullptr) {
        head = tail = newNode;
        tail->next = head;
        return;
    }

    tail->next = newNode;
    tail = newNode;
    tail->next = head;
}

void printCircularList(Node* head) {
    if (head == nullptr) {
        cout << "Empty list\n";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(back to head)\n";
}

Node* findMiddle(Node* head) {
    if(head == nullptr || head->next == head)
        return head;
    Node* slow = head;
    Node* fast = head->next;
    while(fast != head) {
        fast = fast->next;
        if(fast != head)
            fast = fast->next;
        else    
            break;
        slow = slow->next;
    }
    return slow;
}

// Implement this function
void splitCircularList(Node* head, Node*& head1, Node*& head2) {
    if(head == nullptr) {
        head1 = nullptr;
        head2 = nullptr;
        return;
    }
    if(head->next == head) {
        head1 = head;
        head2 = nullptr;
        head1->next = head1;
        return;
    }
    Node* mid = findMiddle(head);
    head1 = head;
    head2 = mid->next;
    Node* lastNode = mid;
    while(lastNode->next != head) 
        lastNode = lastNode->next;
    mid->next = head1;
    lastNode->next = head2;
}


int main() {
    // Test 1: Even number of nodes
    {
        Node* head = nullptr;
        Node* tail = nullptr;
        int values[] = {1, 2, 3, 4, 5, 6};

        for (int value : values)
            insertAtTail(head, tail, value);

        Node* head1 = nullptr;
        Node* head2 = nullptr;
        splitCircularList(head, head1, head2);

        cout << "Test 1 - Even (6 nodes):\n";
        printCircularList(head1);
        printCircularList(head2);
    }

    // Test 2: Odd number of nodes
    {
        Node* head = nullptr;
        Node* tail = nullptr;
        int values[] = {1, 2, 3, 4, 5};

        for (int value : values)
            insertAtTail(head, tail, value);

        Node* head1 = nullptr;
        Node* head2 = nullptr;
        splitCircularList(head, head1, head2);

        cout << "\nTest 2 - Odd (5 nodes):\n";
        printCircularList(head1);
        printCircularList(head2);
    }

    // Test 3: Two nodes
    {
        Node* head = nullptr;
        Node* tail = nullptr;
        int values[] = {10, 20};

        for (int value : values)
            insertAtTail(head, tail, value);

        Node* head1 = nullptr;
        Node* head2 = nullptr;
        splitCircularList(head, head1, head2);

        cout << "\nTest 3 - Two nodes:\n";
        printCircularList(head1);
        printCircularList(head2);
    }

    // Test 4: Single node
    {
        Node* head = nullptr;
        Node* tail = nullptr;
        insertAtTail(head, tail, 7);

        Node* head1 = nullptr;
        Node* head2 = nullptr;
        splitCircularList(head, head1, head2);

        cout << "\nTest 4 - Single node:\n";
        printCircularList(head1);
        printCircularList(head2);
    }

    // Test 5: Empty list
    {
        Node* head = nullptr;
        Node* head1 = nullptr;
        Node* head2 = nullptr;

        splitCircularList(head, head1, head2);

        cout << "\nTest 5 - Empty list:\n";
        printCircularList(head1);
        printCircularList(head2);
    }

    // Test 6: Three nodes
    {
        Node* head = nullptr;
        Node* tail = nullptr;
        int values[] = {4, 8, 12};

        for (int value : values)
            insertAtTail(head, tail, value);

        Node* head1 = nullptr;
        Node* head2 = nullptr;
        splitCircularList(head, head1, head2);

        cout << "\nTest 6 - Three nodes:\n";
        printCircularList(head1);
        printCircularList(head2);
    }

    return 0;
}

