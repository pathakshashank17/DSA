#include <bits/stdc++.h>

using namespace std;

// Properly assign adj & visited
vector<vector<int>> adj;  // Adjancey List
vector<bool> visited;     // Visited matrix

void dfs(int node) {  // Perform DFS on node 'n' recursively
    if (visited[node]) {
        // cout << node + 1 << "->";
        return;
    } else
        visited[node] = 1;
    cout << node + 1 << "->";  // Process the node
    for (auto x : adj[node])
        dfs(x);
}

int main() {
    int n, k;  // Number of nodes & edges
    cin >> n >> k;
    vector<vector<int>> a(n);
    vector<bool> v(n, 0);
    adj = a;
    visited = v;
    while (k--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "-->";
        for (auto node : adj[i])
            cout << node + 1 << ' ';
        cout << endl;
    }
    dfs(0);
}