#include <bits/stdc++.h>

using namespace std;

int LISn2(vector<int> &a) {
    int n = a.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++)
            if (a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
    }
    return *max_element(dp.begin(), dp.end());
}

int LISnlogn(vector<int> &a) {
    int n = a.size(), ans;
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = INT_MIN;
    for (int i = 0; i < n; i++) {
        int pos = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        if (dp[pos - 1] < a[i] && a[i] < dp[pos])
            dp[pos] = a[i];
    }
    ans = lower_bound(dp.begin(), dp.end(), INT_MAX) - dp.begin() - 1;
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << LISn2(a) << endl
         << LISnlogn(a);
}