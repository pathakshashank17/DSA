#include <bits/stdc++.h>
#define deb(x) cout << '\n' \
                    << #x << " = " << x << endl

using namespace std;

struct BIT {
    vector<int> bit;
    BIT(int n) {
        bit = vector<int>(n + 1, 0);
    }
    void update(int p, int v) {
        for (; p < bit.size(); p += p & (-p))
            bit[p] += v;
    }
    void update(int l, int r, int v) {
        update(l, v);
        update(r + 1, -v);
    }
    int query(int p) {
        int res = 0;
        for (; p > 0; p -= p & (-p))
            res += bit[p];
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    BIT b(n);
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        b.update(i, i, v);
    }
    while (1) {
        int t;
        cin >> t;
        if (t == 1) {
            int start, end, val;
            cin >> start >> end >> val;
            b.update(start, end, val);
        } else if (t == 2) {
            int pos;
            cin >> pos;
            cout << "Value at : " << b.query(pos) << endl;
        } else
            break;
    }
    return 0;
}