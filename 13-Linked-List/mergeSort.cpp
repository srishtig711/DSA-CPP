#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* createList(const vector<int>& arr) {
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

void printList(Node* head) {
    Node* curr = head;

    while (curr != nullptr) {
        cout << curr->data;
        if (curr->next != nullptr) cout << " -> ";
        curr = curr->next;
    }

    cout << '\n';
}

Node* findMid(Node* head) {
    Node* slow = head;
    Node* fast = head->next;
    while(fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node* merge(Node* left, Node* right) {
    if(left == nullptr)
        return right;
    if(right == nullptr)
        return left;
    Node* ans = new Node(-1);
    Node* temp = ans;
    while(left != nullptr && right != nullptr) {
        if(left->data < right->data) {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    while(left != nullptr) {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while(right != nullptr) {
        temp->next = right;
        temp = right;
        right = right->next;
    }
    ans = ans->next;
    return ans;
}

// TODO: Implement merge sort
Node* mergeSort(Node* head) {
    if(head == nullptr || head->next == nullptr)
        return head;
    Node* mid = findMid(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = nullptr;
    left = mergeSort(left);
    right = mergeSort(right);
    head = merge(left, right);
    return head;
}

void deleteList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    vector<vector<int>> testCases = {
        {4, 2, 1, 3},
        {5},
        {},
        {5, 4, 3, 2, 1},
        {1, 2, 3, 4, 5},
        {3, 3, 3, 3},
        {-5, 10, 0, -2, 8},
        {2, 1},
        {7, -1, 7, 0, -1, 4},
        {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}
    };

    for (int i = 0; i < (int)testCases.size(); i++) {
        Node* head = createList(testCases[i]);

        cout << "Test case " << i + 1 << ":\n";
        cout << "Before: ";
        printList(head);

        head = mergeSort(head);

        cout << "After:  ";
        printList(head);
        cout << "--------------------\n";

        deleteList(head);
    }

    return 0;
}
