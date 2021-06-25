#include <bits/stdc++.h>

using namespace std;

vector<int> computeLPS(string &pattern) {
    // lps[i] stores longest proper prefix that is also a suffix
    vector<int> lps(pattern.size(), 0);
    int i = 1, len = 0;
    while (i < pattern.size()) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int findPattern(string &s, string &pattern) {
    vector<int> lps = computeLPS(pattern);
    int i = 0, j = 0;
    while (i < s.size()) {
        if (s[i] == pattern[j]) {
            i++;
            j++;
        }
        if (j == pattern.size()) {
            // Remove return & uncomment below to find further occurances
            return (i - j);
            // j = lps[j - 1];
        } else if (i < s.size() && s[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return -1;
}

int main() {
    string s, pattern;
    cin >> s >> pattern;
    int index = findPattern(s, pattern);
    cout << index;
    return 0;
}