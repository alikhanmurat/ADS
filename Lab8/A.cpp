#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll MOD = 1e9 + 7;
ll X = 11;

string hashString(string s) {
    ll hash = 0;
    ll cur = 1;
    for (int i = 0; i < s.size(); i++) {
        ll curHash = ((s[i] - 47) * cur) % MOD;
        hash = (hash + curHash) % MOD;
        cur = (cur * X) % MOD;
    }
    return to_string(hash);
}


int main() {
    ll x, cnt = 0;
    cin >> x;
    
    unordered_map<string, bool> m;
    vector<pair<string, string> > v;
    string s;
    for(int i = 0; i < 2 * x; i++){
        cin >> s;
        m[s] = true;
        v.push_back(make_pair(s, hashString(s)));
    }

    for(int i = 0; i < v.size(); i++){
        if(m[v[i].second]){
            cout << "Hash of string \"" << v[i].first  <<   "\" is " << v[i].second << endl;
            cnt++;
        }
        if(cnt == x)
		return 0;
    }

    return 0;
}