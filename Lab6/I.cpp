#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void quick_sort(vector <char> v, int l, int r){
    if(r < l+1){
	return;
    }
	int mid = (l + r) / 2;
    int pivot = v[mid];
    int j = l;
    swap(v[r], v[mid]);
    for(int i = l; i <= r; i++){
        if(v[i] < pivot){
            swap(v[i], v[j]);
            j++;
        }
    }
    swap(v[j], v[r]);
    quick_sort(v, l, j-1);
    quick_sort(v, j+1, r);
}
int main(){
    vector <char> v;
    string s; 
	cin >> s;
    for(int i = 0; i < s.size(); i++){
        v.push_back(s[i]);
    }
    quick_sort(v, 0, v.size()-1);
    for(auto i : v){
        cout << i;
    }
}