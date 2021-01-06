#include <bits/stdc++.h>

using namespace std;

// Properly assign adj, dis & visited
vector<vector<int>> adj;  // Adjancey List
vector<int> dis;     // dis List
vector<bool> visited;     // Visited matrix
queue<int> q;             // Nodes to be handles

void bfs(int node) {  // Perform BFS on node 'n' recursively
    visited[node] = 1;
    dis[node] = 0;
    q.push(node);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        // Process 'curr' node
        cout << curr + 1 << "->";
        for (auto x : adj[curr]) {
            if (visited[x])
                continue;
            visited[x] = 1;
            dis[x] = dis[curr] + 1;
            q.push(x);
        }
    }
}

int main() {
    int n, k;  // Number of nodes & edges
    cin >> n >> k;
    vector<vector<int>> a(n);
    vector<int> d(n);
    vector<bool> v(n, 0);
    adj = a;
    visited = v;
    dis = d;
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
    bfs(0);
}