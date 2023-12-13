#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector <long long> prefixFunction(string s1){
    vector <long long> v(s1.size());
    for(int i = 1; i < s1.size(); i++){
        int j = v[i-1];
        while(j > 0 && s1[j] != s1[i]){
            j = v[j-1];
        }
        if(s1[j] == s1[i]){
            v[i] = j + 1;
        }
        else{
            v[i] = 0;
        }
    }
    return v;
}

bool repeat(string s1, string s2){
    s1 = s2 + '#' + s1;
    vector <long long> v = prefixFunction(s1);
    for(int i = 0; i < s1.size(); i++){
        if(v[i] == s2.size()){
            return true;
        }
    }
    return false;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int cnt=0;
    
    string temp = "";
    while(temp.size() < s2.size()){
        temp += s1;
        cnt++;
    }


    if(repeat(temp, s2)){
        cout << cnt++;
    }else{
        temp += s1;
        if(repeat(temp, s2)){
            cout << cnt + 1;
        }else{
			cout << -1;
		}
    }
    
    return 0;
}