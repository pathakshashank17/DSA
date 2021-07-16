#include <bits/stdc++.h>

using namespace std;

void dfs(int u, stack<int> &stk, unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &vis) {
    if (vis[u])
        return;
    vis[u] = true;
    for (auto &v : adj[u]) {
        if (vis[v])
            continue;
        dfs(v, stk, adj, vis);
    }
    stk.push(u);
}

// Toposort: -> For every unvisited node, perform DFS on that node and push that node into stack
vector<int> toposort(unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &vis) {
    vector<int> res;
    stack<int> stk;
    for (auto &[key, val] : vis) {
        if (val)
            continue;
        dfs(key, stk, adj, vis);
    }
    while (!stk.empty()) {
        res.push_back(stk.top());
        stk.pop();
    }
    return res;
}

int main() {
    int E;
    cin >> E;
    unordered_map<int, vector<int>> adj;
    unordered_map<int, bool> vis;
    for (int i = 1; i <= E; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        vis[from] = vis[to] = false;
    }
    auto v = toposort(adj, vis);
    for (int &x : v)
        cout << x << ' ';
    cout << endl;
}