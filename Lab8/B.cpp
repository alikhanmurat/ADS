#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll MOD = 1e9+7;
ll X = 11;
map<int,int> m;
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
vector <long long> getPrefiPHashes(string s){
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
int cnt = 0;

void rabinKarp(string s, string t){
    ll smallHash = getHash(t);
    vector <long long> hashes = getPrefiPHashes(s);
    for(int i = 0; i < s.size() - t.size() + 1; i++){
        ll hashDiff = hashes[i + t.size() - 1];
        if(i != 0){ 
			hashDiff -= hashes[i-1];
		}if(hashDiff < 0){
			hashDiff += MOD;
        }if(i != 0){
			smallHash = (smallHash * X) % MOD;
        }if(smallHash == hashDiff){
            if(m.find(i) != m.end()){
                cnt++;
            }
            m[i]=1;
        }
    }
}
int main(){
    string s, t, x;
    cin>> s >> t >> x;
    rabinKarp(s, x);
    rabinKarp(t, x);
    cout << cnt;
}