#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	string s; 
	cin >> s;
	deque <int> d[50];
    for(int i=0; i < s.size(); i++) {
      d[s[i] - 'a' + 1].push_back(i+1);
   }

    for(int i = 1; i <= 26; i++){
		if(d[i].size() & 1) {
        	cout << "NO";
        	return 0;
    }
    while(d[i].size()){
        if((d[i].back() - d[i].front()) % 2 == 0) {
        	cout << "NO";
        	return 0;
        }
        d[i].pop_front();
        d[i].pop_back();
    }
    } 
	
	cout << "YES";
return 0;
}
