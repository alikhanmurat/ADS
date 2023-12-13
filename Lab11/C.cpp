#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<pair<int, pair<int, int>>> v;
int p[10000];

int find(int x){
    if(p[x] == x){
		return x;
    }else{
        return p[x] = find(p[x]);
    } 
}

void merge(int l, int r){
    int root_l = find(l);
    int root_r = find(r);
    p[root_l] = p[root_r];
}

int main(){
    ll x, y, z ,w;
    cin >> x >> y >> z >> w;
    
	for(int i = 1; i <= y; i++){
        string s;
        ll a, b, c;
        cin >> s >> a >> b >> c;
        if(s == "both"){
			v.push_back({c * min(z, w), {a, b}});
        }else if(s == "small"){
			v.push_back({c * w, {a, b}});
        }else if(s == "big"){
			v.push_back({c * z, {a, b}});
		}
    }

    sort(v.begin(), v.end());
    
    for(int i = 0; i < x; i++){
        p[i] = i;
    }
    ll weight = 0;
    for(auto e : v){
        ll l = e.second.second, r = e.second.first, c = e.first;
        if(find(l) != find(r)){
            weight += c;
            merge(l, r);
        }
    }
    cout << weight;


}