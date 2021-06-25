#include <bits/stdc++.h>

using namespace std;

int LSS(vector<int> &a) {
    int n = a.size();
    int curr = a[0], maxx = a[0];
    for (int i = 1; i < n; i++) {
        curr = max(a[i], a[i] + curr);
        maxx = max(maxx, curr);
    }
    return maxx;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << LSS(a);
    return 0;
}