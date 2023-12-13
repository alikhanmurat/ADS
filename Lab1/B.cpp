	#include <bits/stdc++.h>
	#define ll long long int
	using namespace std;
	
	int main(){
		ll x;
		cin >> x;
		vector <int> v1;
		bool check = true;
		for (int i = 0; i < x; i++){
			ll y;
			cin >> y;
			v1.push_back(y);
		}
		
		for (int i = 0; i < v1.size(); i++){
			if (i == 0){
				cout << "-1" << ' ';
			}else if (v1[i] >= v1[i-1]){
			  cout << v1[i-1] << ' ';
			}else if (v1[i] < v1[i-1]){
				
				for (int j = i-1; j >= 0; j--){
					if (v1[i] < v1[j]){
						check = false;
					}
					else if (v1[i] >= v1[j]){
						cout << v1[j] << ' ';
						check = true;
						break;
					}
				}if (check == false){
				cout << "-1" << ' ';
			}
			}
		}
	}
