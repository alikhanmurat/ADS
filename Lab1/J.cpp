#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	deque <int> d;
	while(true){
		char x;
		cin >> x;
		if (x == '+'){
			ll y;
			cin >> y;
			d.push_front(y);
		}else if (x == '-'){
			ll y;
			cin >> y;
			d.push_back(y);
		}else if (x == '*'){
			if (d.size() == 0){
				cout << "error" << endl;
			}else if (d.size() == 1){
				cout << d.front() + d.back() << endl;
				d.pop_front();
			}else{
			cout << d.front() + d.back() << endl;
			d.pop_front();
			d.pop_back();
		}
		}else if (x == '!'){
			break;
		}
	}
return 0;
}
