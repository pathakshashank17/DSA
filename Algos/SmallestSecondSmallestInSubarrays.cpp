#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    stack<int> s;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // The code below accesses the smallest and second smallest values in all possible subarrays
    for (int i = 0; i < n; i++) {
        while (!s.empty()) {
            cout << s.top() << ' ' << a[i] << '\n';
            if (s.top() > a[i])
                s.pop();
            else
                break;
        }
        s.push(a[i]);
    }
    return 0;
}