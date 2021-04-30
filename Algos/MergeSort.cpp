#include <bits/stdc++.h>
#define deb(x) cout << '\n' \
                    << #x << " = " << x << endl

using namespace std;

void mergeVector(vector<int> &a, int start, int mid, int end) {
    vector<int> ans;
    int ix = start, iy = mid + 1;
    // Compare the arrays and insert
    while (ix <= mid && iy <= end) {
        if (a[ix] <= a[iy])
            ans.push_back(a[ix++]);
        else
            ans.push_back(a[iy++]);
    }
    // If any values are left, insert directly
    while (ix <= mid)
        ans.push_back(a[ix++]);
    while (iy <= end)
        ans.push_back(a[iy++]);
    for (int i = start; i <= end; i++)
        a[i] = ans[i - start];
}

void mergeSort(vector<int> &a, int start, int end) {
    // Break the vector into two disjoint vectors if start <= end
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(a, start, mid);
        mergeSort(a, mid + 1, end);
        mergeVector(a, start, mid, end);
    }
}

int main() {
    // int n;
    // cin >> n;
    vector<int> a = {25, 17, 31, 13, 2};
    mergeSort(a, 0, a.size() - 1);
    for (int &x : a)
        cout << x << ' ';
}