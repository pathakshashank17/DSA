#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int from, to, cost;
};

void BellmanFord(int source, vector<Edge> &edges, unordered_map<int, int> &d, unordered_map<int, int> &p) {
    d[source] = 0;
    for (int i = 0; i < edges.size(); i++) {
        bool madeChanges = false;
        for (Edge &e : edges) {
            if (d[e.from] < 1000 && d[e.from] + e.cost < d[e.to]) {
                d[e.to] = d[e.from] + e.cost;
                p[e.to] = e.from;
                madeChanges = true;
            }
        }
        if (!madeChanges)
            break;
    }
}

int main() {
    int E;
    cin >> E;
    vector<Edge> edges(E);
    unordered_map<int, int> d, p;
    for (int i = 0; i < E; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].cost;
        d[edges[i].from] = d[edges[i].to] = 1000;
        p[edges[i].from] = p[edges[i].to] = -1;
    }
    int source;
    cin >> source;
    BellmanFord(source, edges, d, p);
    int destination;
    cin >> destination;
    vector<int> path;
    if (d[destination] != 1000) {
        cout << d[destination] << endl;
        while (1) {
            path.push_back(destination);
            destination = p[destination];
            if (destination == -1)
                break;
        }
        reverse(path.begin(), path.end());
        for (int &x : path)
            cout << x << "->";
    }
    cout << "END\n";
    return 0;
}