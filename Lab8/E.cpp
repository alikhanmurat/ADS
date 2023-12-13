#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll MOD = 1e9 + 7;
ll X = 2;
ll pows[55];

void degree(){
    pows[0] = 1;
    for(int i = 1; i <= 55; i++){
        pows[i] = pows[i-1] * X;
    }
}

int main(){
    int x; 
	cin >> x;
    degree();
    
    vector<long long> hash(x);
    for(int i = 0; i < x; i++){
        cin >> hash[i];
    }
    for(int i = 0; i < x; i++){
        if(i != 0){
            cout << char((hash[i] - hash[i-1]) / pows[i] + 97);
        }
        else{
            cout << char(hash[i] / pows[i] + 97);
        }
    }
}