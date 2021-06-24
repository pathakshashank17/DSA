#include <bits/stdc++.h>

using namespace std;

void dijsktra(int start, unordered_map<int, vector<pair<int, int>>> &adj) {
    int n = adj.size();
    unordered_map<int, int> d;
    unordered_map<int, int> p;
    unordered_map<int, bool> visited;
    for (auto &[key, vec] : adj) {
        d[key] = INT_MAX;
        visited[key] = false;
    }
    d[start] = 0;
    for (int i = 1; i <= n; i++) {
        int curr, dist = INT_MAX;
        // Find node with smallest distance
        for (auto [key, val] : d) {
            if (visited[key])
                continue;
            if (d[key] < dist) {
                dist = d[key];
                curr = key;
            }
        }
        // Relax neighbours
        visited[curr] = true;
        for (auto [node, wt] : adj[curr]) {
            if (visited[node])
                continue;
            if (d[curr] + wt < d[node]) {
                d[node] = d[curr] + wt;
                p[node] = curr;
            }
        }
    }
    // Displaying results
    for (auto &[key, val] : d)
        cout << key << ' ' << val << endl;
    int target;
    cout << "Get shortest path for: ";
    cin >> target;
    vector<int> path;
    while (target != start) {
        path.push_back(p[target]);
        target = p[target];
    }
    reverse(path.begin(), path.end());
    for (int &pathNode : path)
        cout << pathNode << ' ';
    cout << endl;
}

int main() {
    int E;
    cin >> E;
    unordered_map<int, vector<pair<int, int>>> adj;
    for (int i = 1; i <= E; i++) {
        int oneEnd, otherEnd, weight;
        cin >> oneEnd >> otherEnd >> weight;
        adj[oneEnd].push_back({otherEnd, weight});
        // adj[otherEnd].push_back({oneEnd, weight});
    }
    // To counter the issue that the node with no leaving
    // directed edges is not registeres in the adj
    adj[6].push_back({6, 0});
    dijsktra(1, adj);
}