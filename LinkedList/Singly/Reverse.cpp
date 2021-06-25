#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node* next;
};

void printList(Node* head) {
    while (head) {
        cout << head->data << ' ';
        head = head->next;
    }
    cout << endl;
}

Node* reverse(Node* head) {
    Node *prev = NULL, *curr = head, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        if (!next)
            break;
    }
    return prev;
}

int main() {
    int n;
    cin >> n;
    Node *head = NULL, *prevNode = NULL;
    for (int i = 0; i < n; i++) {
        Node* newNode = new Node;
        cin >> newNode->data;
        newNode->next = NULL;
        if (i == 0)
            head = newNode;
        else
            prevNode->next = newNode;
        prevNode = newNode;
    }
    printList(head);
    head = reverse(head);
    printList(head);
}