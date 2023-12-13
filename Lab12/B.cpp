#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll n, m;

vector <vector <pair<int, int>>> v;
int dijkstra(int s, int e){
    vector<int> v1(n);
    vector<bool> v2(n);
    
    for(int i = 0; i < n; i++){
		v1[i] = 1e9;
    }
	v1[s] = 0;
    priority_queue <pair <int, int>> q;
 	q.push(make_pair (0, s));
 	
	while (!q.empty()){
  		int x = q.top().second,  
		y = -q.top().first;
  		q.pop();
  		
  		if (y > v1[x]){
			continue;
		}
  		for (int j = 0; j < v[x].size(); j++) {
   			int z = v[x][j].first;
   			int w = v[x][j].second;
   			
			if (v1[x] + w < v1[z]){
    			v1[z] = v1[x] + w;
    			q.push(make_pair (-v1[z], z));
   			}
  		}
 	}
    return v1[e];
}

int main() {
	cin >> n >> m;
    v.resize(n);
    for(int i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }

    ll i, j, k, l;
    cin >> i >> j >> k >> l;
    i--, j--, k--, l--;
    ll path1 = dijkstra(i, j) + dijkstra(j, k) + dijkstra(k, l);
	ll path2 = dijkstra(i, k) + dijkstra(k, j) + dijkstra(j, l);


    ll ans = min(path1, path2);
    if(ans >= 1e9){
        cout << -1 << endl;
    }else cout << ans << endl;
    
    return 0;
}