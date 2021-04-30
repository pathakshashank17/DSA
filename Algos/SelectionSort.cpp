#include <bits/stdc++.h>

using namespace std;

void selectionSort(vector<int> &a) {
    int n = a.size(), index = 0;
    for (int i = 0; i < n; i++) {
        int si = i;
        for (int j = i; j < n; j++)
            if (a[j] < a[si])
                si = j;
        swap(a[si], a[i]);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    selectionSort(a);
    for (int &x : a)
        cout << x << ' ';
}