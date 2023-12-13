#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll MOD=1e9+7;
ll X = 31;

long long getHash(string s){
    ll hash=0;
    ll curX=1;
    for(int i = 0; i < s.size(); i++){
        ll curHash = (s[i] - 'a' + 1) * curX % MOD;
        hash = (hash + curHash) % MOD;
        curX = (curX * X) % MOD;
    }
    return hash;
}
vector <long long> getPrefixHashes(string s){
    vector <long long> hashes(s.size());
    ll curX=1;
    for(int i = 0; i < s.size(); i++){
        hashes[i]=(s[i] - 'a' + 1) * curX % MOD;
        if(i != 0){
            hashes[i]=(hashes[i] + hashes[i-1]) % MOD;
        }
        curX = (curX * X) % MOD;
    }
    return hashes;
}
void rabinKarp(string s, string t, vector <long long> &hashes, bool check[]){
    ll smallHash = getHash(t);
    for(int i = 0; i < s.size() - t.size() + 1; i++){
        ll hashDiff = hashes[i + t.size() - 1];
        if(i != 0){
		hashDiff -= hashes[i-1];
        }if(hashDiff < 0){
		hashDiff += MOD;
        }if(i != 0){
		smallHash = (smallHash * X) % MOD;
        }if(smallHash == hashDiff){
            for(int j = i; j < i + t.size(); j++){
                check[j] = true;
            }
        }
    }
}
int main(){
    string s;
    cin >> s;
    ll x; 
	cin >> x;
    vector <long long> hashes = getPrefixHashes(s);
    bool check[s.size()] = {false};
    for(int i = 0; i < x; i++){
        string t;
        cin >> t;
        rabinKarp (s, t, hashes, check);
    }
    for(int i = 0; i < s.size(); i++){
        if(!check[i]){
            cout << "NO";
            return 0;
        }
    }
    cout<< "YES";
    return 0;
}