#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<int> v_road[405]; 
vector<int> v_air[405]; 
int arr[405][405]; 

int main(){ 
    ll x, y; 
	cin >> x >> y; 
    for(int i = 0; i < y; i++){ 
        ll a, b; 
		cin >> a >> b; 
        a--; b--; 
        v_road[a].push_back(b); 
        v_road[b].push_back(a); 
        arr[a][b] = 1; 
        arr[b][a] = 1; 
    } 
    for(int i = 0; i < x; i++){ 
        for(int j = 0; j < x; j++){ 
            if(arr[i][j] == 0){ 
                v_air[i].push_back(j); 
            } 
        } 
    } 
    queue <int> q1; 
    vector <int> v1(x+1); 
    vector <bool> used1(x+1); 
    q1.push(0); 
    used1[0] = true; 
    while(!q1.empty()){ 
        ll z = q1.front(); 
        q1.pop(); 
        for(int i = 0; i < v_road[z].size(); i++){ 
            int w = v_road[z][i]; 
            if(!used1[w]){ 
                used1[w] = true; 
                q1.push(w); 
                v1[w] = v1[z] + 1; 
            } 
        } 
    } 
    queue <int> q2; 
    vector <int> v2(x+1); 
    vector <bool> used2(x+1); 
    q2.push(0); 
    used2[0] = true; 
    while(!q2.empty()){ 
        int z = q2.front(); 
        q2.pop(); 
        for(int i = 0; i < v_air[z].size(); i++){ 
            int w = v_air[z][i]; 
            if(!used2[w]){ 
                used2[w] = true; 
                q2.push(w); 
                v2[w] = v2[z]+1; 
            } 
        } 
    } 
    if(!used1[x-1] || !used2[x-1]){ 
        cout << -1; 
        return 0;
    }  
    cout << max(v1[x-1], v2[x-1]); 
}
