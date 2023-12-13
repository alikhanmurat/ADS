#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

int main(){
    ll x; 
	cin >> x;
    ll arr1[x];
    
    for(int i = 0; i < x; i++){
        cin >> arr1[i];
    }
    ll y; 
	cin >> y;
    ll arr2[y];
    for(int i = 0; i < y; i++){
        cin >> arr2[i];
    }
    for(int i = 0; i < y; i++){
        int sum = 0, cnt = 0;
        for(int j = 0; j < x; j++){
            if(arr2[i] >= arr1[j]){
                cnt++;
                sum+=arr1[j];
            }
        }
        cout << cnt << " " << sum << endl;
    }
}