#include<bits/stdc++.h>
using namespace std;

int eGCD(int a, int b) {
    if (b == 0)
        return a;
    else
        return eGCD(b, a % b);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << eGCD(a, b);
    return 0;
}