#include <bits/stdc++.h>

using namespace std;

int LCS(string a, string b) {
    int n = a.size(), m = b.size();
    // Create a DP array, init with ZERO
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    //  dp[i][j] means length of largest common subsequence b/w a[0...i-1] & b[0...j-1]
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // If the chars in a & b match, increment the length in previous indices by one
            // Else the max length upto current indices is the max b/w a[0...i-1] & b[0...j-2] AND a[0...i-2] & b[0...j-1]
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Return the max length upto the end of the respective strings
    return dp[n][m];
}

int main() {
    fast;
    string a, b;
    cin >> a >> b;
    cout << LCS(a, b);  // LCS: Longest Common Subsequence
}