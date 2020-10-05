#include <bits/stdc++.h>
using namespace std;

class SieveOfEratosthenes {
    vector<bool> sieve;

   public:
    SieveOfEratosthenes(int n) {
        vector<bool> s(n + 1, true);
        s[1] = false;
        for (int i = 2; i <= n; i++) {
            for (int j = 2; i * j <= n; j++)
                s[i * j] = false;
        }
        sieve = s;
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