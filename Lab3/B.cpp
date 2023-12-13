#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool isPossible(ll m, ll a[], ll x, ll y) {
    ll cnt = 0;
    ll sum = 0;

    for (int i = 0; i < x; ++i) {
        if (a[i] > m) {
            return false;
        }

        sum += a[i];

        if (sum > m) {
            cnt++;
            sum = a[i];  
        }
    }

    cnt++;  
    
    return cnt <= y;
}

int main() {
    ll x, y;
    cin >> x >> y;

    ll a[x];
    ll sum = 0;

    for (ll i = 0; i < x; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    ll l = 0;
    ll r = sum;
    ll ans = sum;

    while (l <= r) {
        ll m = l + (r - l) / 2;

        if (isPossible(m, a, x, y)) {
            ans = min(ans, m);
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << ans;

    return 0;
}
