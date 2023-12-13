#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void quick_sort(vector <int> v, int l, int r){
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
    ll x, y;
    cin >> x >> y;
    vector <int> v1(x);
    vector <int> v2(y);
    
    for(int i = 0; i < x; i++){
        cin >> v1[i];
    }
    for(int j = 0; j < y; j++){
        cin >> v2[j];
    }
    quick_sort(v1, 0, x-1);
    quick_sort(v2, 0, y-1);
    
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if(v1[i] == v2[j]){
                cout << v1[i] << " ";
                v2[j] = 0;
                break;
            }
        }
    }
}