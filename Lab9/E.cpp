#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector <int> KMP(string s){
    vector <int> v(s.size());
    for(int i = 1; i < s.size(); i++){
        int j = v[i-1];
        while(j > 0 && s[j] != s[i]){
            j = v[j-1];
        }
        if(s[j] == s[i]){
            v[i] = j + 1;
        }
        else{
            v[i] = 0;
        }
    }
    return v;
}

int main(){
    int x; 
	cin >> x;
	
    for(int i = 0; i < x; i++){
        string s; 
		cin >> s;
        int y; 
		cin >> y;
        vector <int> v = KMP(s);

        cout << (s.size() - v[s.size()-1]) * (y - 1) + s.size() << endl;
    }
}