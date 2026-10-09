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

/* Approach 1
Node* removeDuplicates(Node* head) {
    if(head == nullptr || head->next == nullptr)
        return head;
    Node* curr = head;
    while(curr != nullptr) {
        Node* duplicate = curr->next;
        Node* prev = curr;
        while(duplicate != nullptr) {
            Node* nextNode = duplicate->next;
            if(curr->data == duplicate->data) {
                prev->next = duplicate->next;
                delete duplicate;
            }
            else {
                prev = duplicate;
            }
            duplicate = nextNode;
        } 
        curr = curr->next;
    }
    return head;
}
*/

/*
Node* removeDuplicates(Node* head) {
    if(head == nullptr || head->next == nullptr)
        return head;
    unordered_set<int> visited;
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr) {
        Node* next = temp->next;
        if(visited.find(temp->data) != visited.end()) {
            prev->next = next;
            delete temp;
        }
        else {
            visited.insert(temp->data);
            prev = temp;
        }
        temp = next;
    }
    return head;
}
*/

/*Approach 2
Node* findMiddle(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    Node* slow = head;
    Node* fast = head->next;
    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr)
            fast = fast->next;
        else    
            break;
        slow = slow->next;
    }
    return slow;
}

Node* merge(Node* head1, Node* head2) {
    Node* head = nullptr;
    if (head1 == nullptr)
        return head2;
    if (head2 == nullptr)
        return head1;
    if (head1->data < head2->data) {
        head = head1;
        head->next = merge(head1->next, head2);
    }
    else {
        head = head2;
        head->next = merge(head1, head2->next);
    }
    return head;
}

Node* mergeSort(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    Node* mid = findMiddle(head);
    Node* nextHead = mid->next;
    mid->next = nullptr;
    Node* node1 = mergeSort(head);
    Node* node2 = mergeSort(nextHead);
    return merge(node1, node2);
}

Node* removeDuplicates(Node* head) {
    head = mergeSort(head);
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
*/

// Approach 3
Node* removeDuplicates(Node* head) {
    if(head == nullptr || head->next == nullptr) 
        return head;
    unordered_set<int> visited;
    Node* temp = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    while(temp != nullptr) {
        if(visited.find(temp->data) != visited.end()) {
            next = temp->next;
            prev->next = next;
            delete temp;
            temp = next;
        }
        else {
            visited.insert(temp->data);
            prev = temp;
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
    int arr1[] = {1, 2, 3, 2, 4, 1, 5};
    solve(arr1, 7);

    // 2. All elements same
    int arr2[] = {5, 5, 5, 5};
    solve(arr2, 4);

    // 3. No duplicates
    int arr3[] = {1, 4, 2, 5, 3};
    solve(arr3, 5);

    // 4. Duplicates scattered
    int arr4[] = {10, 20, 10, 30, 20, 40, 30};
    solve(arr4, 7);

    // 5. Single element
    int arr5[] = {100};
    solve(arr5, 1);

    return 0;
}