#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    int x, y; 
	cin >> x >> y;
    vector<pair<int, pair<int, int>>> v;
    int mst = 2;
    
    for(int i = 0; i < y; i++){
        int l, r, c; 
		cin >> l >> r >> c;
        v.push_back(make_pair(c, make_pair(l,r)));
    }
    ll cnt = 0;
    sort(v.begin(), v.end());
    
	while(mst <= x){
		
        for(auto e : v){
            int a = e.second.first;
            int b = e.second.second;
            int z = e.first;
            if(a < mst && mst <= b){
                cnt += z;
                mst++;
                break;
            }
        }
    }
    cout<<cnt;
}