#include <bits/stdc++.h>
#define deb(x) cout << '\n' \
                    << #x << '=' << x
using namespace std;

class Node {
   public:
    int data;
    Node* next;
};

void printList(Node* head) {
    if (head == NULL)
        cout << "List empty\n";
    else {
        while (head) {
            cout << head->data << ' ';
            head = head->next;
        }
        cout << endl;
    }
}

void split(Node* head, Node** left, Node** right) {
    Node *fast = head->next, *slow = head;
    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

Node* merge(Node* left, Node* right) {
    Node* res = NULL;
    if (!left)
        return right;
    else if(!right)
        return left;
    if (left->data <= right->data) {
        res = left;
        res->next = merge(left->next, right);
    } else {
        res = right;
        res->next = merge(left, right->next);
    }
    return res;
}

void mergeSort(Node** headAdd) {
    Node* head = *headAdd;
    if (!head || !(head->next))
        return;
    Node *left, *right;
    split(head, &left, &right);
    mergeSort(&left);
    mergeSort(&right);
    *headAdd = merge(left, right);
}

int main() {
    int n;
    cin >> n;
    Node* head;
    Node* prevNode;
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
    mergeSort(&head);
    printList(head);
}