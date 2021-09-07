#include <bits/stdc++.h>

using namespace std;

int cross(vector<int> &O, vector<int> &A, vector<int> &B) {
    return (A[0] - O[0]) * (B[1] - O[1]) - (A[1] - O[1]) * (B[0] - O[0]);
}

vector<vector<int>> getConvexHull(vector<vector<int>> &points) {
    int n = points.size(), k = 0;
    if (n <= 3)
        return points;
    vector<vector<int>> H(2 * n);
    sort(points.begin(), points.end(), [&](auto &t1, auto &t2) {
        return t1[0] < t2[0] || (t1[0] == t2[0] && t1[1] < t2[1]);
    });
    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross(H[k - 2], H[k - 1], points[i]) <= 0)
            k--;
        H[k++] = points[i];
    }
    for (int i = n - 1, t = k + 1; i > 0; i--) {
        while (k >= t && cross(H[k - 2], H[k - 1], points[i - 1]) <= 0)
            k--;
        H[k++] = points[i - 1];
    }
    H.resize(k - 1);
    return H;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(2));
    for (auto &v : points)
        cin >> v[0] >> v[1];
    auto convexHull = getConvexHull(points);
    cout << convexHull.size() << endl;
    for (auto &v : convexHull)
        cout << v[0] << ' ' << v[1] << endl;
    return 0;
}