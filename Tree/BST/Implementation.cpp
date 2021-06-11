#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node* left;
    Node* right;
    int val;
    Node(int x) {
        left = nullptr;
        right = nullptr;
        val = x;
    }
};

void inOrder(Node* root) {
    if (!root)
        return;
    inOrder(root->left);
    cout << root->val << ' ';
    inOrder(root->right);
}

void preOrder(Node* root) {
    if (!root)
        return;
    cout << root->val << ' ';
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root) {
    if (!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << ' ';
}

struct Tree {
    Node* root;
    Tree() {
        root = nullptr;
    }
    void insert(int val);
    void del(int val);
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
};

void Tree::insert(int val) {
    if (!root) {
        root = new Node(val);
        return;
    }
    Node* r = root;
    while (r) {
        if (val < r->val) {
            if (!r->left) {
                r->left = new Node(val);
                return;
            } else
                r = r->left;
        } else {
            if (!r->right) {
                r->right = new Node(val);
                return;
            } else
                r = r->right;
        }
    }
}

void Tree::inOrderTraversal() {
    inOrder(root);
}

void Tree::preOrderTraversal() {
    preOrder(root);
}

void Tree::postOrderTraversal() {
    postOrder(root);
}

void Tree::del(int val) {
}

int main() {
    int n;
    cin >> n;
    Tree tree;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        tree.insert(val);
    }
    cout << "\nInorder traversal\n";
    tree.inOrderTraversal();
    cout << "\nPreorder traversal\n";
    tree.preOrderTraversal();
    cout << "\nPostorder traversal\n";
    tree.postOrderTraversal();
    return 0;
}