#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void quick_sort(vector <int> v, int l, int r){
    if(r < l+1){
		return;
    }int mid = (l + r) / 2;
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
    vector <int> v(x);
    
    for(int i = 0; i < x; i++){
        cin >> v[i];
    }
    quick_sort(v, 0, x-1);
    int min = abs(v[0] - v[1]);
    
    for(int i = 1; i < x; i++){
        if(abs(v[i] - v[i+1]) < min){
            min = abs(v[i] - v[i+1]);
        }
    }
    for(int i = 0; i < x-1; i++){
        if(abs(v[i] - v[i+1]) == min){
            cout << v[i] << " " << v[i+1]<< " ";
        }
    }
}