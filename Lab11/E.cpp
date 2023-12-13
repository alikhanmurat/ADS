#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int p[1000000];

int find(int z){
    if(p[z] == z){
		return z;
    }else{
        return p[z] = find(p[z]);
    } 
} 

bool merge(int l, int r){
    int root_l = find(l);
    int root_r = find(r);
    if(root_l == root_r){
		return false;
    }
    p[root_l] = root_r;
    return true;
}

int main(){
    ll x, y; 
	cin >> x >> y;
    vector <int> v[x];
    
    for(int i = 0; i < x; i++){
        p[i] = i;
    }
    for(int i = 0; i < y; i++){
        ll a, b; 
		cin >> a >> b;
        a--; 
		b--;
        v[a].push_back(b);
        v[b].push_back(a);
    
    }
    vector <long long> ans; 
    ll cnt = 0;
    for(int i = x-1; i >= 0; i--){
        ans.push_back(cnt++);
        
		for(auto j:v[i]){
            if(j > i){
                if(merge(i, j)){
                    cnt--;
                }
            }
        }
    }

    for(int i = ans.size() - 1; i>= 0; i--){
        cout << ans[i] << endl;
    }
}
