#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll MOD = 1e15 + 7;
ll X = 31;
vector <long long> hashes;

ll hashString(string s, int l, int r) {
    ll hash = 0;
    ll curX = 1;
    for (int i = l; i < r + 1; i++) {
        ll curHash = ((s[i] - 96) * curX) % MOD;
        hash = (hash + curHash) % MOD;
        curX = (curX * X) % MOD;
    }
    return hash;
}

void getPrefix(string s) {
    ll curX = 1;
    for (int i = 0; i < s.size(); i++) {
        hashes[i] = (s[i] - 'a' + 1) * curX % MOD;
        if (i != 0) {
            hashes[i] = (hashes[i] + hashes[i - 1]) % MOD;
        }
        curX = (curX * X) % MOD;
    }
}

int rabinKarp(string s, int l, int r) {
    ll small = hashString(s, l, r);
    int res = 0;

    for (int i = 0; i < s.size() - r + l; i++) {
        ll dif = hashes[i + r - l];
        if (i != 0) {
            dif -= hashes[i - 1];
            if (dif < 0){
			dif += MOD;
            }
			small = (small * X) % MOD;
        }
        if (small == dif) {
            res++;
        }
    }
    return res;
}


int main() {
    string s;
    cin >> s;
    hashes.resize(s.size());
    getPrefix(s);
    
    int x;
    cin >> x;
    while(x--){
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << rabinKarp(s, l, r) << endl;
    }
}