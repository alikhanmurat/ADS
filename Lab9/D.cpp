#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int prefixFunction(string s){
    vector <ll> v(s.size());
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
    return v[v.size()-1];
}

int main() {
    string s;
    cin >> s;
    s[0] += 32;
    int mx = 1;
    int x;
    cin >> x;
    vector <string> v;
    for(int i = 0; i < x; i++){
        string t; 
		cin >> t;
        string w = t; 
        w[0] = (w[0] + 32);
        w = w + '#' + s;
        int last = prefixFunction(w);
        if(mx == last){
			v.push_back(t);
        }if(mx < last){
            v.clear();
            v.push_back(t);
            mx = last;
        }
    }
    cout << v.size() << endl;
    for(auto i : v){
        cout << i << endl;
    }
    return 0;
}