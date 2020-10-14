#include <bits/stdc++.h>

using namespace std;

// Comments suggest changes for conversion to modular exponentiation
long binExp(int x, int n) {
    long res = 1;
    while (n) {
        if (n % 2 == 1)
            res *= x;  // res = (res * x) % mod;
        x *= x;        // x = (x * x) % mod;
        n /= 2;
    }
    return res;
}

int main() {
    int num, n;
    cin >> num >> n;
    cout << binExp(num, n);
    return 0;
}