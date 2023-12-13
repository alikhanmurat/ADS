#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool cmp(char a, char b){
    return a > b;
}
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
    int x; 
	cin >> x;
    vector <char> v;
    
    for(int i = 0; i < x; i++){
        char c; 
		cin >> c;
        v.push_back(c);
    }
    char c; 
	cin >> c;
    quick_sort(v, 0, x-1);
    
    for(int i = 0; i < x; i++){
        if(cmp(v[i], x)){
            cout << v[i];
            return 0;       
        }
    }
    cout << v[0] << endl;
}