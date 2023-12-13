#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	ll cnt1 = 0, cnt2 = 0;
	queue <int> Nursik;
	queue <int> Boris;
	
	for (int i = 0; i < 5; i++){
		ll x;
		cin >> x;
		Boris.push(x);
	}
	
	for (int i = 0; i < 5; i++){
		ll x; 
		cin >> x;
		Nursik.push(x);
	}
	
	while (!Nursik.empty() and !Boris.empty()){
		ll y = Boris.front();
		ll z = Nursik.front();
		if (z == 0 and y == 9){
			cnt1++;
			Nursik.push(y);
			Nursik.push(z);
		}else if (y == 0 and z == 9){
			cnt2++;
			Boris.push(y);
			Boris.push(z);
		}else if (z > y){
			cnt1++;
			Nursik.push(y);
			Nursik.push(z);
		}else if (y > z){
			cnt2++;
			Boris.push(y);
			Boris.push(z);
		}
		
		Nursik.pop();
		Boris.pop();
		
		if(Nursik.empty() or Boris.empty()) {
			break;
		}
	}

	if (cnt1 + cnt2 >= 1000000){
		cout << "blin nichya";
	}else if (cnt2 > cnt1){
		cout << "Boris" << ' ' << cnt2 + cnt1;
	}else if (cnt1 > cnt2){
		cout << "Nursik" << ' ' << cnt1 + cnt2;
	}
return 0;
}
