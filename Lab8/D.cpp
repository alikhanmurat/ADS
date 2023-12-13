#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll MOD = 1e9 + 9;
ll X = 31;

long long getHash(string s){
    ll hash = 0;
    ll curX = 1;
    for(int i = 0; i < s.size(); i++){
        ll curHash = (s[i] - 'a' + 1) * curX % MOD;
        hash = (hash + curHash) % MOD;
        curX = (curX * X) % MOD;
    }
    return hash;
}
vector <long long> getPrefixHashes(string s){
    vector <long long> hashes(s.size());
    ll curX = 1;
    for(int i = 0; i < s.size(); i++){
        hashes[i] = (s[i] - 'a' + 1) * curX % MOD;
        if(i != 0){
            hashes[i] = (hashes[i] + hashes[i-1]) % MOD;
        }
        curX = (curX * X) % MOD;
    }
    return hashes;
} 

void rabinKarp(string s, pair<string,int> &patterns,int &mx){
    ll smallHash = getHash(patterns.first);
    vector <long long> hashes = getPrefixHashes(s);
    for(int i = 0; i < s.size() - patterns.first.size() + 1; i++){
        ll hashDiff = hashes[i + patterns.first.size() - 1];
        if(i != 0){
		hashDiff -= hashes[i-1];
        }if(hashDiff < 0){
		hashDiff += MOD;
        }if(i != 0){
		smallHash=(smallHash * X) % MOD;
        }if(smallHash == hashDiff){
            patterns.second++;
            mx = max(mx, patterns.second);
        }
    }
}

int main(){
    while(true){
        int x; 
		cin >> x;
        if(x == 0){
		break;
        }
		pair<string, int> pattern[x];
        for(int i = 0; i < x; i++){
            cin >> pattern[i].first;
        }
        int mx = 0;
        string s; 
		cin >> s;
        for(int i = 0;i < x; i++){
            rabinKarp(s, pattern[i], mx);
        }  
        cout << mx << " " << endl;
        
        for(int i = 0; i < x; i++){
            if(pattern[i].second == mx){
                cout << pattern[i].first << endl;
            }
        }
    }
}