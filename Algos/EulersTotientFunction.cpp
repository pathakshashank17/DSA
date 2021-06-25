#include <bits/stdc++.h>

using namespace std;

int phi(int n) {
    // Create sieve
    vector<bool> sieve(n + 1, true);
    sieve[0] = false;
    sieve[1] = false;
    for (int i = 2; i <= n / 2; i++) {
        if (sieve[i]) {
            for (int j = 2; i * j <= n; j++)
                sieve[i * j] = false;
        }
    }
    // Find prime factors and calculate
    if (sieve[n])
        return n - 1;
    else {
        float res = n;
        for (int i = 2; i <= n; i++) {
            if (sieve[i] && n % i == 0) {
                res *= (1.0 - 1.0 / i);
            }
        }
        return res;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    cout << phi(n);
    return 0;
}