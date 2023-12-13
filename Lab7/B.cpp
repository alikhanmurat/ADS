#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void merge(int a[], int b[], int x, int y){
    int i = 0;
    int j = 0;

    while(i < x && j < y){
        if(a[i] < b[j]){
            cout << a[i++] << " ";
        } else{
            cout << b[j++] << " ";
        }
    }
    while(i < x){
        cout << a[i++] << " ";
    }
    while(j < y){
        cout << b[j++] << " ";
    }
}
int main(){
    int x; 
	cin >> x;
    int a[x];
    
    for(int i = 0; i < x; i++){
        cin >> a[i];
    }

    int y; 
	cin >> y;
    int b[y];

    for(int j = 0; j < y; j++){
        cin >> b[j];
    }

    merge(a, b, x, y);
    return 0;
}
