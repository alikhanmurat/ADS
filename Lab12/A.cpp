#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int INF = 1e9;
int a[505][505];
int b[505][505];
int c[1000000];
int d[1000000];

void solve(){
    ll x; 
	cin >> x;
	for(int i = 1; i <= x; i++) {
		for(int j = 1; j <= x; j++) {
			cin >> a[i][j];
			b[i][j] = INF;
		}
	}
	for(int i = 1; i <= x; i++) {
		cin >> c[i];
		int ans = 0;
		for(int j = 1; j <= i; j++) {
			b[c[j]][c[i]] = a[c[j]][c[i]];
			b[c[i]][c[j]] = a[c[i]][c[j]];
		}
		for(int k = 1; k <= i; k++) {
			for(int t = 1; t <= i; t++) {
				b[c[t]][c[i]] = min(b[c[t]][c[i]] , b[c[t]][c[k]] + b[c[k]][c[i]]);
			}
		}
		for(int k = 1; k <= i; k++) {
			for(int t = 1; t <= i; t++) {
				b[c[i]][c[t]] = min(b[c[i]][c[t]] , b[c[i]][c[k]] + b[c[k]][c[t]]);
			}
		}
		for(int k = 1; k <= i; k++) {
			for(int t = 1; t <= i; t++) {
				b[c[k]][c[t]] = min(b[c[k]][c[t]] , b[c[k]][c[i]] + b[c[i]][c[t]]);
				if(b[c[k]][c[t]] < INF) {
					ans = max(ans, b[c[k]][c[t]]);
				}
			}
		}
		cout << ans << endl;
	}
}
int main() {
    solve();
}