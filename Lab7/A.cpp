#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool cmp(string s1, string s2){
    if(s1.size() <= s2.size()){
        return true;
    }
    if(s1.size() == s2.size() && s1 <= s2){
        return true;
    }
    return false;
}

void merge(vector <string> &v, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    vector <string> L(n1);
    vector <string> R(n2);
    for(int i = 0; i < n1; i++){
        L[i] = v[l + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = v[m + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while(i < n1 && j < n2){
        if(cmp(L[i], R[j])){
            v[k] = L[i];
            i++;
        }
        else{
            v[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        v[k++] = L[i++];
    }
    while(j < n2){
        v[k++] = R[j++];
    }
}

void mergeSort(vector <string> &v, int l, int r){
    if (l < r){
        int m = (l + r) / 2;
        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);
        merge(v, l, m, r);
    }
}

int main(){
    int x;
    cin >> x;
    for(int i = 0; i < x; i++){   
        string s;
        vector <string> v;
        getline(cin >> ws, s); 
        string space = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                v.push_back(space);
                space = "";
            } else {
                space += s[i];
            }
        }
        v.push_back(space);
        mergeSort(v, 0, v.size() - 1);
        
        for(auto i : v){
            cout << i << " ";
        }
        cout << endl;
    }
}
