#include <bits/stdc++.h>
#define INF 1000

using namespace std;

vector<vector<int>> floydwarshall(int N, vector<vector<int>> &adj) {
    vector<vector<int>> d(N, vector<int>(N, INF));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j)
                d[i][j] = 0;
            if (adj[i][j] == -1)
                continue;
            d[i][j] = adj[i][j];
        }
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (d[i][k] < INF && d[k][j] < INF)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    return d;
}

// 6 6
// 0 4 2
// 0 1 1
// 4 5 3
// 2 4 4
// 3 2 6
// 3 5 5
// 3 4

int main() {
    int N, E;
    cin >> N >> E;
    vector<vector<int>> adj(N, vector<int>(N, -1));
    for (int i = 1; i <= E; i++) {
        int from, to, wt;
        cin >> from >> to >> wt;
        adj[from][to] = wt;
    }
    auto d = floydwarshall(N, adj);
    int start, end;
    cin >> start >> end;
    cout << "Min distance b/w " << start << " & " << end << " is : " << d[start][end] << endl;
    return 0;
}