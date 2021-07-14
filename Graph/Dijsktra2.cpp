#include <bits/stdc++.h>
#define deb(x) cout << '\n' \
                    << #x << " = " << x << endl

using namespace std;

unordered_map<int, vector<pair<int, int>>> adj;
unordered_map<int, int> d, p;
unordered_map<int, bool> vis;

void dijsktra(int start) {
    d[start] = 0;
    p[start] = INT_MAX;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto &[key, dist] : d)
        pq.push({dist, key});
    for (int i = 1; i <= vis.size(); i++) {
        // Find node with smallest d
        auto [dist, v] = pq.top();
        pq.pop();
        vis[v] = true;
        // Relax all the neighbours of the found node
        for (auto &[u, wt] : adj[v]) {
            if (vis[u])
                continue;
            if (d[u] > dist + wt) {
                d[u] = dist + wt;
                p[u] = v;
                pq.push({d[u], u});
            }
        }
    }
    int node;
    cin >> node;
    if (d[node] == INT_MIN) {
        cout << "No path exists" << endl;
        return;
    }
    cout << d[node] << endl;
    vector<int> path;
    while (node != INT_MAX) {
        path.push_back(node);
        node = p[node];
    }
    reverse(path.begin(), path.end());
    for (int &x : path)
        cout << x << "->";
    cout << "nullptr" << endl;
}

int main() {
    int E;
    cin >> E;
    for (int i = 1; i <= E; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        d[from] = d[to] = INT_MAX;
        vis[from] = vis[to] = false;
        adj[from].push_back({to, weight});
    }
    int start;
    cin >> start;
    dijsktra(start);
}