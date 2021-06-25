#include <bits/stdc++.h>

using namespace std;

void insertionSort(vector<int> &a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        int curr = i;
        while (a[curr - 1] > a[curr] && curr >= 1) {
            swap(a[curr - 1], a[curr]);
            curr--;
        }
    }
}

int main() {
    int n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    insertionSort(a);
    for (int &x : a)
        cout << x << ' ';
}