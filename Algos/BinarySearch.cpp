#include <bits/stdc++.h>
#define name(x) (#x)

using namespace std;

// Returns the index of found element
// Return -1 if element not found
int binarySearch(vector<int> a, int x) {
    int start = 0, end = a.size() - 1, mid;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (a[mid] < x) {
            start = mid + 1;
        } else if (a[mid] > x) {
            end = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    int index = binarySearch(a, x);
    if (index == -1)
        cout << name(x) << " not found";
    else
        cout << name(x) << " found at " << index;
    return 0;
}