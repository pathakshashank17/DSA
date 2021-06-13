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

struct AVLTree {
    Node* root;
    AVLTree() {
        root = nullptr;
    }
    Node* insert(Node* root, int val);
    Node* remove(Node* root, int val);
    Node* find(int val);
    Node* minNode(Node* root);
    Node* balanceTree(Node* root);
    Node* LL(Node* parent);
    Node* LR(Node* parent);
    Node* RL(Node* parent);
    Node* RR(Node* parent);
    int height(Node* root);
    void inOrderTraversal(Node* root);
};

Node* AVLTree::find(int val) {
    Node* r = root;
    while (r) {
        if (r->val == val)
            return r;
        if (val < r->val)
            r = r->left;
        else
            r = r->right;
    }
    return nullptr;
}

Node* AVLTree::minNode(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

Node* AVLTree::LL(Node* parent) {
    // Break parent's connection -> Pull the child to top
    auto leftChild = parent->left;
    parent->left = leftChild->right;
    leftChild->right = parent;
    return leftChild;
}
Node* AVLTree::LR(Node* parent) {
    // Perform left rotation to make LL -> then balance
    auto leftChild = parent->left;
    parent->left = RR(leftChild);
    return LL(parent);
}
Node* AVLTree::RL(Node* parent) {
    // Perform right rotation tp make RR -> then balance
    auto rightChild = parent->right;
    parent->right = LL(rightChild);
    return RR(parent);
}
Node* AVLTree::RR(Node* parent) {
    // Break parent's connection -> Pull child to top
    auto rightChild = parent->right;
    parent->right = rightChild->left;
    rightChild->left = parent;
    return rightChild;
}

Node* AVLTree::balanceTree(Node* root) {
    int factor = height(root->left) - height(root->right);
    // If left is longer
    if (factor > 1) {
        // If left subtree is longer
        if (height(root->left->left) - height(root->left->right) > 0)
            root = LL(root);
        // If right subtree is longer
        else
            root = LR(root);
    }
    // If right is longer
    else if (factor < -1) {
        // If left subtree is longer
        if (height(root->right->left) - height(root->right->right) > 0)
            root = RL(root);
        // If right subtree is longer
        else
            root = RR(root);
    }
    return root;
}

Node* AVLTree::insert(Node* root, int val) {
    // Basic BST insertion
    if (!root) {
        root = new Node(val);
        return root;
    }
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    // Balance the AVLTree
    root = balanceTree(root);
    return root;
}

// BUG - Issue with root deletion
Node* AVLTree::remove(Node* root, int val) {
    // Perfrom BST deletion
    if (!root)
        return nullptr;
    if (val < root->val)
        root->left = remove(root->left, val);
    else if (val > root->val)
        root->right = remove(root->right, val);
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
        root->right = remove(root->right, minn->val);
    }
    // Balance node
    root = balanceTree(root);
    return root;
}

int AVLTree::height(Node* root) {
    int maxHeight = 0;
    if (root)
        maxHeight = max(height(root->left), height(root->right)) + 1;
    return maxHeight;
}

void AVLTree::inOrderTraversal(Node* root) {
    if (!root) {
        cout << "At nullptr" << endl;
        return;
    }
    cout << "Traversing left" << endl;
    inOrderTraversal(root->left);
    cout << root->val << endl;
    cout << "Traversing right" << endl;
    inOrderTraversal(root->right);
}

int main() {
    int n;
    cin >> n;
    AVLTree tree;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        tree.root = tree.insert(tree.root, val);
    }
    cout << "Inorder:\n";
    tree.inOrderTraversal(tree.root);
    int val;
    cin >> val;
    cout << "Inorder:\n";
    tree.root = tree.remove(tree.root, val);
    tree.inOrderTraversal(tree.root);
    return 0;
}