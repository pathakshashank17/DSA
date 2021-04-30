#include <bits/stdc++.h>
#define deb(x) cout << '\n' \
                    << #x << " = " << x << endl

using namespace std;

int part(vector<int> &a, int start, int end) {
    int pi = end;
    int index = start;
    for (int i = start; i < end; i++) {
        if (a[i] < a[pi])
            swap(a[i], a[index++]);
    }
    swap(a[pi], a[index]);
    return index;
}

void quickSort(vector<int> &a, int start, int end) {
    if (start < end) {
        int pi = part(a, start, end);
        quickSort(a, start, pi - 1);
        quickSort(a, pi + 1, end);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    quickSort(a, 0, a.size() - 1);
    for (int &x : a)
        cout << x << ' ';
}