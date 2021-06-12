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

struct Tree {
    Node* root;
    Tree() {
        root = nullptr;
    }
    void insert(int val);
    Node* del(Node* root, int val);
    Node* find(int val);
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    Node* inorderSuccessor(Node* node);
};

Node* minNode(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

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

Node* Tree::del(Node* root, int val) {
    if (!root)
        return nullptr;
    if (val < root->val)
        root->left = del(root->left, val);
    else if (val > root->val)
        root->right = del(root->right, val);
    else {
        // Leaf Node
        if (!root->left && !root->right)
            return nullptr;
        // One child
        if (!root->right) {
            Node* leftNode = root->left;
            free(root);
            return leftNode;
        } else {
            Node* rightNode = root->right;
            free(root);
            return rightNode;
        }
        // Two child
        Node* minn = minNode(root->right);
        root->val = minn->val;
        root->right = del(root->right, minn->val);
    }
    return root;
}

Node* Tree::find(int val) {
    Node* r = root;
    while (r && r->val != val) {
        if (val <= r->val)
            r = r->left;
        else
            r = r->right;
    }
    return r;
}

Node* Tree::inorderSuccessor(Node* node) {
    // If has no right child
    if (!node->right) {
        Node *ancestor = root, *successor = nullptr;
        while (ancestor != node) {
            if (node->val < ancestor->val) {
                successor = ancestor;
                ancestor = ancestor->left;
            } else
                ancestor = ancestor->right;
        }
        return successor;
    }
    // If has a right child
    else
        return minNode(node->right);
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

int main() {
    int n;
    cin >> n;
    Tree tree;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        tree.insert(val);
    }
    cout << "Inorder traversal\n";
    tree.inOrderTraversal();
    cout << "\nPreorder traversal\n";
    tree.preOrderTraversal();
    cout << "\nPostorder traversal\n";
    tree.postOrderTraversal();
    int valToDelete;
    cin >> valToDelete;
    tree.root = tree.del(tree.root, valToDelete);
    tree.inOrderTraversal();
    cout << endl;
    int val;
    cin >> val;
    cout << tree.inorderSuccessor(tree.find(val))->val;
    return 0;
}