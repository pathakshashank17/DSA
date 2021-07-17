#include <bits/stdc++.h>

using namespace std;

void maxHeapify(int index, vector<int> &a) {
    int n = a.size();
    int left = 2 * index, right = 2 * index + 1, largest = index;
    if (left <= n && a[left] > a[largest])
        largest = left;
    if (right <= n && a[right] > a[largest])
        largest = right;
    if (largest != index) {
        swap(a[largest], a[index]);
        maxHeapify(largest, a);
    }
}

void minHeapify(int index, vector<int> &a) {
    int n = a.size();
    int left = 2 * index, right = 2 * index + 1, smallest = index;
    if (left <= n && a[left] < a[smallest])
        smallest = left;
    if (right <= n && a[right] < a[smallest])
        smallest = right;
    if (smallest != index) {
        swap(a[smallest], a[index]);
        minHeapify(smallest, a);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n / 2; i >= 1; i--)
        maxHeapify(i, a);
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    cout << endl;
    for (int i = n / 2; i >= 1; i--)
        minHeapify(i, a);
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}