#include <bits/stdc++.h>

using namespace std;

int binexp(int x, int n) {
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return binexp(x * x, n / 2);
    else
        return x * binexp(x * x, (n - 1) / 2);
}

int main() {
    int num, n;
    cin >> num >> n;
    cout << binexp(num, n);
    return 0;
}