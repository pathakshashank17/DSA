#include <bits/stdc++.h>
#define deb(x) cout << '\n' \
                    << #x << '=' << x
using namespace std;

int partition(int start, int end, vector<int> &a) {
    int pivotIndex = start;
    for (int i = start; i < end; i++) {
        if (a[i] < a[end]) {
            swap(a[i], a[pivotIndex]);
            pivotIndex++;
        }
    }
    swap(a[end], a[pivotIndex]);
    return pivotIndex;
}

void quickSort(int start, int end, vector<int> &a) {
    if (start < end) {
        int pivotIndex = partition(start, end, a);
        quickSort(start, pivotIndex - 1, a);
        quickSort(pivotIndex + 1, end, a);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    quickSort(0, n - 1, a);
    for (auto x: a)
        cout << x << ' ';
    return 0;
}