#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector <pair<int, int>> v[100000];
bool check[100000];

int main(){
    ll x; 
	cin >> x;
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= x; j++){
            ll y; 
			cin >> y;
            if(i != j){
                v[i].push_back({j, y});
            }
        }
    }
    int weight = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    while(!q.empty()){
        pair<int, int> c = q.top();
        q.pop();

        ll mst = c.first, z = c.second;
        if(check[z]){
			continue;
        }
		check[z] = true;
        weight += mst;
        for(pair<int, int> e:v[z]){
            ll u = e.first, lenght = e.second;
            
			if(!check[u]){
                q.push({lenght, u});
            }
        }
    }
    cout << weight << endl;
}