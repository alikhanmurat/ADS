#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll x;
    cin >> x;
    vector <int> v;
    ll min = 1e9, pos = -1e9;
    
	for(int i = 0; i < x; i++) {
        ll y;
        cin >> y;
        v.push_back(y);
        
		if(y < min){
            min = y;
            pos = i;
        }
    }

    ll sum = 0;
    
    for(int i = 0; i < x; i++){
        if(i != pos){
		sum += (v[i] + min);
		}
    }

    cout << sum << endl;

    return 0;
}