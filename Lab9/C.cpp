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

int cyclicShift(string s1, string s2){
    s1 = s2 + '#' + s1;
    vector <int> v = prefixFunction(s1);
    
    for(int i = 0; i < s1.size(); i++){
        if(v[i] == s2.size()){
            return (i - 2 * s2.size());
        }
    }
    return -1;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    
    if(cyclicShift(s1, s2) != -1){
        cout << s1.size();
        return 0;
    }
    s1 += s1;
    
    if(cyclicShift(s1, s2) != -1){
        cout << s2.size() - cyclicShift(s1, s2);
        return 0;
    }
    cout<<-1;
}