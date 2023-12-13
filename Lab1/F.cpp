#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool Prime(int x){
	if (x < 2){
		return false;
	}
	
	for  (int i = 2; i < x; i++){
		if (x % i == 0){
			return false;
		}
	}
	
	return true;
}

void nth_Prime(int x){
	ll cnt1 = 0, cnt2 = 0;
	
	while (x){
		if (Prime(cnt1)){
			cnt2++;
		}
		
		if (cnt2 == x){
			break;
		}
		
		cnt1++;
	}
	
	cout << cnt1; 
}

int main(){
	ll x;
	cin >> x;
	nth_Prime(x);
return 0;
}
