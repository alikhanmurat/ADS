#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll MOD = 1e9 + 7;
ll X = 31;
vector <long long> v2;

vector<long long> getPrefix(string s) {
    vector<long long> hashes(s.size());
    ll curX = 1;
    for (int i = 0; i < s.size(); i++) {
        hashes[i] = (s[i] - 96) * curX % MOD; 
        if (i != 0) {
            hashes[i] = (hashes[i] + hashes[i - 1]) % MOD;
        }
        curX = (curX * X) % MOD;
    }
    return hashes;
}

bool rabinKarp(string s, ll small, vector <long long> hashes, int l, int r) {
    for(int i = 0; i < s.size() - r + 1; i++) {
        ll dif = hashes[i + r - 1];
        if(i != 0){
			dif -= hashes[i-1];
        }if(dif < 0){
			dif += MOD;
	 	}
        ll small2 = small;
        if(i < l){
            dif = (dif * v2[l - i]) % MOD;
        }
        else small2 = (small2 * v2[i - l]) % MOD;
        
        if(small2 == dif){
            return true;
        }
    }
    return false;
}

int main() {
    int x;
    cin >> x;
    string min = "";
    string s;
    vector<pair<string, vector<long long >>> v;
    int max = 0;
    for(int i = 0; i < x; i++){
        cin >> s;
        v.push_back(make_pair(s, getPrefix(s)));
        if(v[i].first.size() < 5000){
            if(min.size() == 0){
				min = v[i].first;
            }else {
                if(v[i].first.size() < min.size()){
					min = v[i].first;
				}
            }
        }
        if(v[i].first.size() > max){
			max = v[i].first.size();
		}
    }

    max += 5;
    v2.resize(max);
    v2[0] = 1;
    for(int i = 1; i < max; i++){
        v2[i] = (v2[i - 1] * 31 % MOD);
    }

    vector<long long> minHash = getPrefix(min);
    string res = "";

    for(int i = 0; i < min.size(); i++){
        int l = i, r = min.size() - 1, mid;
        while(l <= r){
            mid = l + (r - l) / 2;
            ll curh = minHash[mid];
            if(i != 0){
				curh -= minHash[i - 1];
            }if(curh < 0){
            	curh += MOD;
            }
			int bound = mid - i + 1;
            bool check = true;
            for(int j = 0; j < v.size(); j++){
                if(!rabinKarp(v[j].first, curh, v[j].second, i, bound)){
                    check = false;
                    break;
                }
            }
            if(check){
                if(bound > res.size()){
					res = min.substr(i, bound);
                }
				l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
    }
    cout << res << endl;
    return 0;
}