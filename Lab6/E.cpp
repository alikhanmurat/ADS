#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int a[1000][1000];
int partition(int i, int l, int r){
    int pivot = a[r][i];
    int j = l - 1;
    for(int k = l; k <= r-1; j++){
        if(a[j][i]>pivot){
            j++;
            swap(a[j][i], a[k][i]);
        }
    }
    swap(a[j+1][i], a[r][i]);
    return (j+1);
}
void quick_sort(int i, int l, int r){
    if(l < r){
        int p = partition(i, l, r);
        quick_sort(i, l, p-1);
        quick_sort(i, p+1, r);
    }
}
int main(){
    int x, y;
    cin >> x >> y;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < y; i++){
        quick_sort(i, 0, x-1);
    }
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            cout << a[i][j] << " ";
        }
        cout<<endl;
    }    
}