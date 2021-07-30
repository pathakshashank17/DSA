#include <bits/stdc++.h>
using namespace std;

class SieveOfEratosthenes {
    vector<bool> sieve;

   public:
    SieveOfEratosthenes(int n) {
        sieve = vector<bool>(n + 1, true);
        sieve[0] = sieve[1] = false;
        for (int p = 2; p * p <= n; p++) {
            if (!sieve[p])
                continue;
            for (int i = p * p; i <= n; i += p)
                sieve[i] = false;
        }
    }
    bool isPrime(int x) {
        return sieve[x];
    }
};

int main() {
    int n;
    cin >> n;
    SieveOfEratosthenes sieve(n);
    if (sieve.isPrime(n))
        cout << n << " is a prime number";
    else
        cout << n << " is a composite number";
    return 0;
}