#include <bits/stdc++.h>
#define deb(x) cout << '\n' \
                    << #x << '=' << x
using namespace std;

class Node {
   public:
    int data;
    Node *next;
};

void printList(Node* head) {
    while (head) {
        cout << head->data << ' ';
        head = head->next;
    }
    cout << endl;
}

Node* endPtr(Node* head) {
    while (head->next) {
        head = head->next;
    }
    return head;
}

bool isLess(Node* a, Node* b) {
    while (a) {
        if (a->next == b)
            return true;
        a = a->next;
    }
    return false;
}

Node* prevAdd(Node* ptr, Node* head) {
    while (head->next != ptr && head != ptr) {
        head = head->next;
    }
    return head;
}

void swapData(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

Node* part(Node* head, Node* end) {
    Node* pivotAdd = head;
    for (Node* i = head; isLess(i, end); i = i->next) {
        if (i->data < end->data) {
            swapData(i, pivotAdd);
            pivotAdd = pivotAdd->next;
        }
    }
    swapData(end, pivotAdd);
    return pivotAdd;
}

void quickSort(Node* head, Node* end) {
    if (isLess(head, end)) {
        Node* pivotAdd = part(head, end);
        quickSort(head, prevAdd(pivotAdd, head));
        quickSort(pivotAdd->next, end);
    }
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
    Node* copyOfHead = head;
    printList(head);
    quickSort(head, endPtr(head));
    printList(head);
}