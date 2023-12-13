#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void quick_sort(vector <char> v, int l, int r){
    if (r < l + 1){
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
    int x; 
	cin >> x;
    vector <char> v1;
    vector <char> v2;
    string s; 
	cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'a' || s[i] == 'e' ||s[i] == 'i' ||s[i] == 'o' ||s[i] == 'u'){
            v1.push_back(s[i]);
        } else{
            v2.push_back(s[i]);
        }
    }
    quick_sort(v1, 0, v1.size()-1);
    quick_sort(v2, 0, v2.size()-1);
    
	for(auto i : v1){
        cout << i;
    }
    for(auto i : v2){
        cout << i;
    }
}
