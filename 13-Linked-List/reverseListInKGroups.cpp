/* Approach 1
#include <iostream>
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

void print(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

bool check(Node* head, int k) {
    int cnt = 1;
    Node* temp = head;

    while (temp != NULL && cnt <= k) {
        if (cnt == k)
            return true;

        temp = temp->next;
        cnt++;
    }

    return false;
}

Node* kReverse(Node* head, int k) {
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;

    for (int i = 0; i < k; i++) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    Node* tail = head;
    Node* newHead = curr;

    if (check(newHead, k)) {
        Node* oldHead = kReverse(newHead, k);
        tail->next = oldHead;
    }
    else {
        tail->next = newHead;
    }

    return prev;
}

void solve(int arr[], int n, int k) {
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        insertAtTail(head, tail, arr[i]);
    }

    cout << "Original: ";
    print(head);

    head = kReverse(head, k);

    cout << "k = " << k << " -> ";
    print(head);

    cout << "------------------------" << endl;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    solve(arr1, 5, 3);

    int arr2[] = {1, 2, 3, 4};
    solve(arr2, 4, 2);

    int arr3[] = {5, 4, 3, 7, 9, 2};
    solve(arr3, 6, 4);

    int arr4[] = {4, 3, 2, 8};
    solve(arr4, 4, 4);

    return 0;
}
*/

// Approach 2
#include <iostream>
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

void print(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

Node* kReverse(Node* head, int k) {
    if(head == NULL || k <= 1)
        return head;
    Node* curr = head;
    Node* prevTail = NULL;
    while(curr != NULL) {
        Node* kth = curr;
        for(int i = 1; i < k && kth != NULL; i++) {
            kth = kth->next;
        }
        if(kth == NULL) {
            break;
        }
        Node* nextHead = kth->next;
        Node* prev = nextHead;
        Node* node = curr;
        while(node != nextHead) {
            Node* forward = node->next;
            node->next = prev;
            prev = node;
            node = forward;
        }
        if(prevTail != NULL) {
            prevTail->next = kth;
        }
        else {
            head = kth;
        }
        prevTail = curr;
        curr = nextHead;
    }
    return head;
}

int main() {

    int arr1[] = {1, 2, 3, 4, 5};
    int n1 = 5;
    int k1 = 3;

    int arr2[] = {1, 2, 3, 4};
    int n2 = 4;
    int k2 = 2;

    int arr3[] = {5, 4, 3, 7, 9, 2};
    int n3 = 6;
    int k3 = 4;

    int arr4[] = {4, 3, 2, 8};
    int n4 = 4;
    int k4 = 4;

    Node* head1 = NULL;
    Node* tail1 = NULL;

    for (int i = 0; i < n1; i++) {
        insertAtTail(head1, tail1, arr1[i]);
    }

    head1 = kReverse(head1, k1);
    print(head1);


    Node* head2 = NULL;
    Node* tail2 = NULL;

    for (int i = 0; i < n2; i++) {
        insertAtTail(head2, tail2, arr2[i]);
    }

    head2 = kReverse(head2, k2);
    print(head2);


    Node* head3 = NULL;
    Node* tail3 = NULL;

    for (int i = 0; i < n3; i++) {
        insertAtTail(head3, tail3, arr3[i]);
    }

    head3 = kReverse(head3, k3);
    print(head3);


    Node* head4 = NULL;
    Node* tail4 = NULL;

    for (int i = 0; i < n4; i++) {
        insertAtTail(head4, tail4, arr4[i]);
    }

    head4 = kReverse(head4, k4);
    print(head4);

    return 0;
}