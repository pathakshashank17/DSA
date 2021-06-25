#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
     int data;
     Node* next;
     Node* prev;
     Node () {
         next = NULL;
         prev = NULL;
     }
};

void printList(Node* head) {
    while (head) {
        cout << head->data << ' ';
        head = head->next;
    }
    cout << endl;
}

// We'll reverse by breaking the links and then placing the next-node behind the curr-node by re-linking
Node* reverse(Node* head) {
    Node *prev = NULL, *curr = head, *next = NULL;
    while (curr) {
        next = curr->next;  
        curr->next = prev;  
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main() {
    int n;
    cin >> n;
    Node *head, *prevNode;
    for (int i = 0; i < n;i++) {
        Node* newNode = new Node();
        cin >> newNode->data;
        if (i == 0)
            head = newNode;
        else {
            newNode->prev = prevNode;
            prevNode->next = newNode;
        }
        prevNode = newNode;
    }
    printList(head);
    head = reverse(head);
    printList(head);
    return 0;
}