	#include <bits/stdc++.h>
	#define ll long long int
	using namespace std;
	
	int main(){
		int x;
		cin >> x;
		vector <char> v, u;
		map <char, int> m;
		bool check = false;
		for (int i = 0; i < x; i++){
			char y;
			cin >> y;
			v.push_back(y);
		}	
		
		for (int i = 0; i < v.size(); i++){
			for (int j = 0; j < v.size(); j++){
				if (v[j] == 'S'){
					for (int k = j+1; k < v.size(); k++){
						if (v[k] == 'K'){
							v[k] = '`';
							check = true;
							break;
						}else {
							continue;
						}
					}if (check == false){
						for (int k = 0; k < j; k++){
							if (v[k] == 'K'){
								v[k] = '`';
								break;
							}else {
								continue;
							}
						}
					}check = false;
				}
				
				else if (v[j] == 'K'){
					for (int k = j+1; k < v.size(); k++){
						if (v[k] == 'S'){
							v[k] = '`';
							check = true;
							break;
						}else {
							continue;
						}
					}if (check == false){
						for (int k = 0; k < j; k++){
							if (v[k] == 'S'){
								v[k] = '`';
								break;
							}else {
								continue;
							}
						}
					}check = false;
				}
				
				else if (v[j] == '`'){
					continue;
				}
				
				m[v[j]]++;
			}
			
			if (m.size() != 1){
				u.clear();
				for (int i = 0; i < v.size(); i++){
					if (v[i] != '`'){
						u.push_back(v[i]);
					}
				}
				
				v.clear();
				
				for (int i = 0; i < u.size(); i++){
					v.push_back(u[i]);
				}
				
				m.clear();
			}else {
				break;
			}
		}
		
		for (int i = 0; i < v.size(); i++){
			if (v[i] == 'S'){
				cout << "SAKAYANAGI";
				break;
			}else {
				cout << "KATSURAGI";
				break;
			}
		}
	return 0;
	}
