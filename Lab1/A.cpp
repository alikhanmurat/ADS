#include <bits/stdc++.h>
#define ll long long int
using namespace std;


int main(){
	ll x;
	cin >> x;
	
	for (int i = 0; i < x; i++){
		deque <int> d;
		ll y;
		cin >> y;
		
		for (int k = y; k > 0; k--){
			ll z;
			z = k;
			d.push_back(z);
		
			if (z % 2 == 0){
				for (int j = 0; j < z+1; j++){
					ll w;
					w = d.back();
					d.pop_back();
					d.push_front(w);
				}
			}else if (z % 2 == 1){
				for (int j = 0; j < z+1; j++){
					ll w;
					w = d.back();
					d.pop_back();
					d.push_front(w);
				}
			}
		}
		
		while (!d.empty()){
			cout << d.front() << ' ';
			d.pop_front();
		}
		
		cout << endl;
		
	}
	

return 0;
}
