#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	ll x;
	cin >> x;
	
	if (x == 1){
		cout << "NO ";
		return 0;
	}else{
	for (int i = 2; i < x; i++){
		if (x % i == 0){
			cout << "NO";
			return 0;
		}
	}
	}cout << "YES";
	return 0;
}