#include <bits/stdc++.h>

using namespace std;

struct Node {
    int parent;
    int rank;
    Node() {
        this->parent = -1;
        this->rank = 0;
    }
};

int getRoot(int key, unordered_map<int, Node> &dsu) {
    if (dsu[key].parent == -1)
        return key;
    dsu[key].parent = getRoot(dsu[key].parent, dsu);
    return dsu[key].parent;
}

void makeUnion(int from, int to, unordered_map<int, Node> &dsu) {
    int root1 = getRoot(from, dsu);
    int root2 = getRoot(to, dsu);
    if (dsu[root1].rank == dsu[root2].rank) {
        dsu[root1].parent = root2;
        dsu[root2].rank++;
    } else if (dsu[root1].rank < dsu[root2].rank) {
        dsu[root1].parent = root2;
    } else {
        dsu[root2].parent = root1;
    }
}

int getMinCost(int A, vector<vector<int>> &B) {
    int minCost = 0;
    vector<vector<int>> edges;
    unordered_map<int, Node> dsu;
    // Kruskal's method
    sort(B.begin(), B.end(), [&](auto &x, auto &y) { return x[2] < y[2]; });
    for (auto &e : B) {
        int from = e[0], to = e[1], wt = e[2];
        // If incoming edge forms a loop, do not add it
        if (getRoot(from, dsu) == getRoot(to, dsu))
            continue;
        minCost += wt;
        edges.push_back({from, to, wt});
        makeUnion(from, to, dsu);
    }
    // for (auto &e : edges)
    //     cout << e[0] << "<->" << e[1] << endl;
    return minCost;
}

int main() {
    int A;
    cin >> A;
    int E;
    cin >> E;
    vector<vector<int>> B(E, vector<int>(3));
    for (auto &v : B)
        cin >> v[0] >> v[1] >> v[2];
    cout << getMinCost(A, B) << endl;
}