#include<bits/stdc++.h>

using namespace std;

int gcd, x, y;

void extGCD(int a, int b) {
    if (b == 0) {
        gcd = a;
        x = 1;
        y = 0;
    } else {
        extGCD(b, a % b);
        int temp = x;
        x = y;
        y = temp - (a / b) * y;
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    extGCD(a, b);
    cout << "We have " << a << " * " << x << " + " << b << " * " << y << " = " << gcd;
}