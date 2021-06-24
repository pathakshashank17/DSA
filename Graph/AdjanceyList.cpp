#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;  // Number of nodes & edges
    cin >> n >> k;
    vector<vector<int>> adj(n);  // Adjancey List
    while (k--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        cout << i << ' ';
        for (auto node : adj[i])
            cout << node << ' ';
        cout << endl;
    }
}