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

// Remove duplicates from sorted linked list
Node* removeDuplicates(Node* head) {
    if(head == nullptr)
        return head;
    Node* temp = head;
    while(temp != nullptr && temp->next != nullptr) {
        if(temp->data == temp->next->data) {
            Node* duplicate = temp->next;
            temp->next = temp->next->next;
            delete duplicate;
        }
        else {
            temp = temp->next;
        }
    }
    return head;
}


// Print linked list
void printList(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void solve(int arr[], int n) {
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++)
        insertAtTail(head, tail, arr[i]);

    head = removeDuplicates(head);

    printList(head);
}

int main() {

    // 1. Multiple duplicates
    int arr1[] = {1, 1, 2, 2, 3, 3};
    solve(arr1, 6);

    // 2. All elements same
    int arr2[] = {5, 5, 5, 5};
    solve(arr2, 4);

    // 3. No duplicates
    int arr3[] = {1, 2, 3, 4, 5};
    solve(arr3, 5);

    // 4. Duplicates at beginning/end
    int arr4[] = {1, 1, 1, 2, 3, 4, 4};
    solve(arr4, 7);

    // 5. Single element
    int arr5[] = {10};
    solve(arr5, 1);

    return 0;
}