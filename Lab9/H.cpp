#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector <int> prefixFunction(string s){
    vector <int> v(s.size());
    for(int i = 1; i < s.size(); i++){
        int j = v[i-1];
        while(j > 0 && s[j] != s[i]){
            j = v[j-1];
        }
        if(s[j] == s[i]){
            v[i] = j+1;
        }
        else{
        	v[i]=0;
        }
    }
    return v;
}


int main(){
    string s; 
	cin >> s;
    vector <int> v1;
    int cnt = 0;
    vector <int> v2 = prefixFunction(s);
    for(int i = 0; i < v2.size(); i++){
        v1.push_back(v2[i]);
    }
    for(int i = 1; i < s.size()-1; i = i + 2){
        int x = i + 1;
        int y = x - v1[i];
        int isEven = x/y;
        if(isEven % 2==0){
            cnt++;
        } 
    }
    cout << cnt << endl;
}
