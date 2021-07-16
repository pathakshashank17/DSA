#include <bits/stdc++.h>

using namespace std;

struct FenwickTree {
    vector<int> ft;
    FenwickTree(int n) {
        ft = vector<int>(n, 0);
    }
    void update(int i, int val) {
        i++;
        while (i < ft.size()) {
            ft[i] += val;
            i += i & (-i);
        }
    }
    int prefixSum(int i) {
        i++;
        int sum = 0;
        while (i > 0) {
            sum += ft[i];
            i -= i & (-i);
        }
        return sum;
    }
};

int main() {
    int n;
    cin >> n;
    FenwickTree ft(n);
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        ft.update(i, val);
    }
    int index;
    cin >> index;
    cout << ft.prefixSum(index) << endl;
}