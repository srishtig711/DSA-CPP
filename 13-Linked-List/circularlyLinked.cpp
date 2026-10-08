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

bool isCircular(Node* head){
    if (head == NULL)
        return true;
    Node* slow = head;
    Node* fast = head;
    do {
        fast = fast->next;
        if (fast == NULL)
            return false;
        else {
            fast = fast->next;
            slow = slow->next;
        }
    } while (slow != fast && fast != NULL);
    if(slow == fast && fast == head)
        return true;
    return false;
}

/* Approach 2
bool isCircular(Node* head){
    if(head == nullptr)
        return true;
    unordered_set<Node*> visited;
    Node* temp = head;
    while(temp!= nullptr) {
        if(visited.find(temp) != visited.end()) {
            if(temp == head)
                return true;
            return false;
        }
        visited.insert(temp);
        temp = temp->next;
    }
    return false;
}
*/

void solve(int arr[], int n, int cycleTo) {
    Node* head = NULL;
    Node* tail = NULL;

    for(int i = 0; i < n; i++) {
        insertAtTail(head, tail, arr[i]);
    }

    if(cycleTo != -1) {
        Node* temp = head;

        for(int i = 0; i < cycleTo; i++) {
            temp = temp->next;
        }

        tail->next = temp;
    }

    cout << (isCircular(head) ? "True" : "False") << endl;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 1};
    solve(arr1, 5, 0);

    int arr2[] = {1, 2, 3, 4, 5, 6, 7};
    solve(arr2, 7, -1);

    solve(NULL, 0, -1);

    int arr4[] = {1, 2, 5, 4, 3, 8, 1};
    solve(arr4, 7, 0);

    int arr5[] = {1, 2, 5, 4, 3, 8, 5};
    solve(arr5, 7, 2);

    int arr6[] = {1, 2, 7, 4, 8, 3};
    solve(arr6, 6, -1);

    return 0;
}