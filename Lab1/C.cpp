#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	string x, y, z = "", w = "";
	deque <int> d1;
	deque <int> d2;
	cin >> x >> y;
	
	for (int i = 0; i < x.length(); i++){
		if ('a' <= x[i] && x[i] <= 'z'){
			d1.push_back(x[i]);
		}else if (x[i] == '#'){
			if (!d1.empty()){
				d1.pop_back();
			}
		}
	}
	
	for (int i = 0; i < y.length(); i++){
		if ('a' <= y[i] && y[i] <= 'z'){
			d2.push_back(y[i]);
		}else if (y[i] == '#'){
			if (!d2.empty()){
				d2.pop_back();
			}
		}
	}
	
	while (!d1.empty()){
		z += d1.front();
		d1.pop_front();
	}
	
	while (!d2.empty()){
		w += d2.front();
		d2.pop_front();
	}
	
	if (z == w){
		cout << "Yes";
	}else {
		cout << "No";
	}
	
	return 0;
}
