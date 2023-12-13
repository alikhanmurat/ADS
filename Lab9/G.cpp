#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector <int> prefixFunction(string s1){
    vector <int> v(s1.size());
    for(int i = 1; i < s1.size(); i++){
        int j = v[i-1];
        while(j > 0 && s1[j] != s1[i]){
            j = v[j-1];
        }
        if(s1[j] == s1[i]){
            v[i] = j + 1;
        }
        else{
            v[i]=0;
        }
    }
    return v;
}

int main(){
    string s1;
    cin >> s1;
    string s2 = "";
    vector <int> v1;  
    vector <int> v2 = prefixFunction(s1);
    
    for(int i = 0; i < v2.size(); i++){
        v1.push_back(v2[i]);
    }
    cout << s1.size() - v1[s1.size()-1];
}