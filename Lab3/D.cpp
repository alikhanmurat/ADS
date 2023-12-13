#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int binarySearch( vector <ll> v, int l1, int r1, int l2, int r2) {
    int cnt = 0;
    for (ll num : v) {
        if (l1 <= num && num <= r1) {
            cnt++;
        } else if (l2 <= num && num <= r2) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ll x, y;
    cin >> x >> y;
    
    vector <ll> v(x);
    for (ll i = 0; i < x; ++i) {
        cin >> v[i];
    }

    for (ll i = 0; i < y; ++i) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        
        int ans = binarySearch(v, l1, r1, l2, r2);
        cout << ans << endl;
    }

    return 0;
}
