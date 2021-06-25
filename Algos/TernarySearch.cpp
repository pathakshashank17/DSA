#include <bits/stdc++.h>

using namespace std;

// Trisect search area
// Check each part for presence of req. value
int ternarySearch(vector<int> a, int x) {
    int start = 0, end = a.size() - 1, mid1, mid2;
    while (start <= end) {
        mid1 = start + (end - start) / 3;
        mid2 = end - (end - start) / 3;
        if (a[mid1] == x)
            return mid1;
        else if (a[mid2] == x)
            return mid2;
        else if (a[mid1] > x)
            end = mid1 - 1;
        else if (a[mid1] < x && a[mid2] > x) {
            start = mid1 + 1;
            end = mid2 - 1;
        } else {
            start = mid2 + 1;
        }
    }
    return -1;
}

int main() {
    fast;
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << ternarySearch(a, x);
}
