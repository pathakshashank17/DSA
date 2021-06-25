#include <bits/stdc++.h>

using namespace std;

struct Node {
    unordered_map<char, Node*> m;
    bool isWord;
    Node() {
        isWord = false;
    }
};

// TODO - Deletion
class Trie {
   public:
    Node* root;
    Trie() {
        root = new Node;
    }

    void insert(string word) {
        Node* curr = root;
        Node* prevNode;
        for (auto& ch : word) {
            prevNode = curr;
            if (curr->m.find(ch) == curr->m.end())
                curr->m[ch] = new Node;
            curr = curr->m[ch];
        }
        prevNode->isWord = true;
    }

    bool search(string word) {
        Node* curr = root;
        Node* prevNode;
        for (auto& ch : word) {
            if (curr->m.find(ch) == curr->m.end())
                return false;
            prevNode = curr;
            curr = curr->m[ch];
        }
        return prevNode->isWord;
    }

    bool startsWith(string prefix) {
        Node* curr = root;
        for (auto& ch : prefix) {
            if (curr->m.find(ch) == curr->m.end())
                return false;
            curr = curr->m[ch];
        }
        return true;
    }
};

int main() {
    Trie* root = new Trie();
    int cmd;
    while (cin >> cmd) {
        // 1: Insert into Trie
        if (cmd == 1) {
            string s;
            cin >> s;
            root->insert(s);
            cout << "Inserted " << s << endl;
        }
        // 2: Search into Trie
        else if (cmd == 2) {
            string s;
            cin >> s;
            cout << (root->search(s) ? "Found" : "Not Found") << endl;
        }
        // 3: Check presence of a prefix
        else if (cmd == 3) {
            string s;
            cin >> s;
            cout << (root->startsWith(s) ? "Found" : "Not Found") << endl;
        }
        // Default
        else
            break;
    }
    return 0;
}