#include <bits/stdc++.h>
#define deb(x) cout << '\n' \
                    << #x << '=' << x
using namespace std;

void merge(int start, int mid, int end, vector<int> &a) {
    vector<int> left, right;

    for (int i = start; i <= mid; i++)
        left.push_back(a[i]);

    for (int i = mid + 1; i <= end; i++)
        right.push_back(a[i]);

    int leftItr = 0, rightItr = 0, arrItr = start;

    while (leftItr <= left.size() - 1 && rightItr <= right.size() - 1) {
        if (left[leftItr] <= right[rightItr]) {
            a[arrItr] = left[leftItr];
            leftItr++;
        } else {
            a[arrItr] = right[rightItr];
            rightItr++;
        }
        arrItr++;
    }

    while (leftItr <= left.size() - 1) {
        a[arrItr] = left[leftItr];
        arrItr++;
        leftItr++;
    }

    while (rightItr <= right.size() - 1) {
        a[arrItr] = right[rightItr];
        arrItr++;
        rightItr++;
    }
}

void mergeSort(int start, int end, vector<int> &a) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(start, mid, a);
        mergeSort(mid + 1, end, a);
        merge(start, mid, end, a);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    mergeSort(0, n - 1, a);
    for (auto x : a)
        cout << x << ' ';
    return 0;
}