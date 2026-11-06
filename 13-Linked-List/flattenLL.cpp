
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node() : data(0), next(nullptr), child(nullptr) {}
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node* next, Node* child)
        : data(x), next(next), child(child) {}
};

Node* merge(Node* &list1, Node* &list2) {
    Node dummy(-1);
    Node* tail = &dummy;

    while (list1 && list2) {
        if (list1->data < list2->data) {
            tail->child = list1;
            list1 = list1->child;
        }
        else if (list1->data > list2->data) {
            tail->child = list2;
            list2 = list2->child;
        }
        else {
            tail->child = list1;
            list1 = list1->child;

            tail = tail->child;
            tail->child = list2;
            list2 = list2->child;
        }

        tail = tail->child;
    }

    if (list1) {
        tail->child = list1;
    }

    if (list2) {
        tail->child = list2;
    }

    return dummy.child;
}

Node* flattenLinkedList(Node* head) {
    if (!head)
        return nullptr;

    Node* list1 = head;
    Node* list2 = list1->next;

    while (list2) {
        if (list1->next)
            list1->next = nullptr;

        Node* temp = list2->next;
        list2->next = nullptr;

        list1 = merge(list1, list2);
        list2 = temp;
    }

    return list1;
}

// Creates linked list with sorted child columns
Node* createList(vector<vector<int>> columns) {
    Node* head = nullptr;
    Node* prev = nullptr;

    for (auto &col : columns) {
        if (col.empty())
            continue;

        Node* colHead = nullptr;
        Node* tail = nullptr;

        for (int val : col) {
            Node* newNode = new Node(val);

            if (!colHead) {
                colHead = tail = newNode;
            }
            else {
                tail->child = newNode;
                tail = newNode;
            }
        }

        if (!head) {
            head = colHead;
        }
        else {
            prev->next = colHead;
        }

        prev = colHead;
    }

    return head;
}

// Prints flattened list using child pointers
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->child;
    }
    cout << '\n';
}

// Frees flattened list memory
void deleteList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->child;
        delete temp;
    }
}

void runTest(vector<vector<int>> columns) {
    Node* head = createList(columns);

    cout << "Input columns:\n";
    for (auto &col : columns) {
        for (int val : col)
            cout << val << " ";
        cout << '\n';
    }

    head = flattenLinkedList(head);

    cout << "Flattened list: ";
    printList(head);

    cout << "-------------------------\n";

    deleteList(head);
}

int main() {
    // Test 1: Standard case
    runTest({
        {1, 2, 3},
        {8, 10, 15},
        {18, 22},
        {29}
    });

    // Test 2: Interleaving values
    runTest({
        {4, 6},
        {5, 71},
        {7, 8, 9}
    });

    // Test 3: Single column
    runTest({
        {1, 3, 5, 7}
    });

    // Test 4: Single node
    runTest({
        {10}
    });

    // Test 5: Duplicate values
    runTest({
        {1, 3, 5},
        {1, 3, 6},
        {2, 3, 7}
    });

    // Test 6: Negative values
    runTest({
        {-10, -5, 0},
        {-8, -3, 2},
        {-6, 1, 5}
    });

    // Test 7: Empty columns
    runTest({
        {},
        {2, 4},
        {},
        {1, 3, 5}
    });

    // Test 8: Empty list
    runTest({});

    // Test 9: All columns have one node
    runTest({
        {5},
        {2},
        {8},
        {1}
    });

    return 0;
}
