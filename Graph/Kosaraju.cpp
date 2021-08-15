#include <bits/stdc++.h>

using namespace std;

// Used for creating the order
void dfs1(int u, unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &vis, stack<int> &stk) {
    if (vis[u])
        return;
    vis[u] = true;
    for (int &v : adj[u])
        if (!vis[v])
            dfs1(v, adj, vis, stk);
    stk.push(u);
}

// Used for traversing a SCC
void dfs2(int u, unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &vis) {
    if (vis[u])
        return;
    vis[u] = true;
    cout << u << ' ';
    for (int &v : adj[u])
        if (!vis[v])
            dfs2(v, adj, vis);
}

unordered_map<int, vector<int>> reverseEdges(unordered_map<int, vector<int>> &adj) {
    unordered_map<int, vector<int>> res;
    for (auto &[u, vec] : adj) {
        for (int &v : vec)
            res[v].push_back(u);
    }
    return res;
}

void kosaraju(unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &vis) {
    // Fill the stack with the dfs traversal in the order of finishing time
    stack<int> stk;
    dfs1(adj.begin()->first, adj, vis, stk);
    
    // Reverse the edges of the graph
    auto rev = reverseEdges(adj);

    // Prepare for another traversal
    for (auto &[u, val] : vis)
        val = false;
    
    // For any unvisited node, perform dfs (the nodes that will be reachable will be in the same SCC)
    while (!stk.empty()) {
        int v = stk.top();
        stk.pop();
        if (vis[v])
            continue;
        dfs2(v, rev, vis);
        cout << endl;
    }
}

int main() {
    int E;
    cin >> E;
    unordered_map<int, vector<int>> adj;
    unordered_map<int, bool> vis;
    for (int i = 0; i < E; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        vis[from] = vis[to] = false;
    }
    kosaraju(adj, vis);
    return 0;
}