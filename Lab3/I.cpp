#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int binarySearch(int arr[], int x, int y){
	int l = 0; 
	int r = x - 1;
	int m;
	
	while (l <= r){
		m = (l + r) / 2;
		
		if (y == arr[m]){
			return m;
		}else if ( y > arr[m]){
			l = m + 1;
		}else {
			r = m - 1;
		}
	} 
	
	return -1;
}

int main(){
	ll x, y;
	cin >> x;
	int arr[x];
	
	for (int i = 0; i < x; i++){
		cin >> arr[i];
	}
	cin >> y;
	sort (arr, arr + x);
	int result = binarySearch(arr, x, y);
	
	if (result >= 0){
		cout << "Yes";
	}else {
		cout << "No";
	}
return 0;
}
