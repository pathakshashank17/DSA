#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;  // Number of Nodes
    int k;  // Number of Edges
    cin >> n >> k;
    vector<vector<bool>> adj(n, vector<bool>(n, 0));  // Adjancey Matrix
    while (k--) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << adj[i][j] << ' ';
        cout << endl;
    }
}