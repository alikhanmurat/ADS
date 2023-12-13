#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool Prime(int x) {
    if (x < 2) {
        return false;
    }
    for (int i = 2; i < x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int nth_Prime(int x) {
    ll cnt = 0;
    for (int i = 2; ; i++) {
        if (Prime(i)) {
            cnt++;
            if (cnt == x) {
                return i;
            }
        }
    }
}

bool SuperPrime(int x) {
    return Prime(x);
}

int nth_Super_Prime(int x) {
    ll cnt = 0;
    for (int i = 2; ; i++) {
        if (SuperPrime(i)) {
            cnt++;
            if (cnt == x) {
                return i;
            }
        }
    }
}

int main() {
    ll x;
    cin >> x;
    int nthPrime = nth_Prime(x);
    int nthSuperPrime = nth_Super_Prime(nthPrime);
    cout << nthSuperPrime;
    return 0;
}
