#include <bits/stdc++.h>

using namespace std;

void updateFT(vector<int> &FT, int val, int index) {
    while (index < FT.size()) {
        FT[index] += val;
        // i + i & (-i) = gets next node
        index += index & (-index);
    }
}

vector<int> createFT(vector<int> &a) {
    int n = a.size();
    vector<int> FT(n + 1, 0);
    for (int i = 0; i < n; i++)
        updateFT(FT, a[i], i + 1);
    return FT;
}

int prefixSum(int index, vector<int> &FT) {
    int sum = 0;
    index++;
    while (index > 0) {
        sum += FT[index];
        // i - i & (-i) = i & (i - 1) = gets parent node
        index -= index & (-index);
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    int index;
    cin >> index;
    auto FT = createFT(a);
    // for (auto &x : FT)
    //     cout << x << ' ';
    // cout << endl;
    cout << prefixSum(index, FT);
    return 0;
}