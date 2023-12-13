#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

void preprocess( int b[], int a[], int x) {
    b[0] = a[0];
    for (int i = 1; i < x; ++i) {
        b[i] = b[i - 1] + a[i];
    }
}

int findNumber(int b[], int w, int x) {
    int l = 0;
    int r = x - 1;

    while (l < r) {
        int m = l + (r - l) / 2;
        if (b[m] < w) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    return l + 1;
}

int main() {
    ll x, y;
    cin >> x >> y;
    int a[x];
    
    for (int i = 0; i < x; ++i) {
        cin >> a[i];
    }

    int b[x];
    preprocess(b, a, x);

    for (int i = 0; i < y; ++i) {
        int z;
        cin >> z;
        int w = findNumber(b, z, x);
        cout << w << endl;
    }
    return 0;
}
