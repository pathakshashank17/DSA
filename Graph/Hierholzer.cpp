#include <bits/stdc++.h>

using namespace std;

// One issue still persists 👇
// How to choose the starting vertex? (for the case with two vertices having odd degree)
vector<int> hierholzer(unordered_map<int, vector<int>> &adj) {
    vector<int> circuit;
    stack<int> currPath;
    // int u = adj.begin()->first; // Can be changed to start from a wanted vertex
    int u = 0;
    currPath.push(u);
    while (!currPath.empty()) {
        u = currPath.top();
        if (adj[u].size()) {
            currPath.push(adj[u].back());
            adj[u].pop_back();
        } else {
            circuit.push_back(currPath.top());
            currPath.pop();
        }
    }
    reverse(circuit.begin(), circuit.end());
    return circuit;
}

int main() {
    int E;
    cin >> E;
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < E; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
    }
    auto circuit = hierholzer(adj);
    for (int &v : circuit)
        cout << v << "->";
    cout << "END\n";
    return 0;
}