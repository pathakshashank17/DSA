#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node* next;
};

// Floyd's cycle finding algorithm -> If slow and fast pointers meet, then we have a cycle
bool has_cycle(Node* head) {
    Node* slow = head;
    Node* fast = head->next;
    while (fast) {
        if (fast == slow)
            return true;
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return false;
}

int main() {
    // Generating driver list
    Node* a = new Node;
    Node* b = new Node;
    Node* c = new Node;
    Node* d = new Node;
    Node* head = a;

    a->data = 1;
    b->data = 2;
    c->data = 3;
    d->data = 4;
    a->next = b;
    b->next = c;
    c->next = d;
    // Creating loop
    d->next = a;

    // Check presence of cycle
    if (has_cycle(head))
        cout << "Cycle found\n";
    else
        cout << "No cycle found\n";
}