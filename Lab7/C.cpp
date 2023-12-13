#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<int> merge(vector<int> left, vector<int> right) {
	vector<int> result;
 	int l = 0, r = 0;
 	while (l < left.size() && r < right.size()) {
  		if (left[l] > right[r]) {
   		result.push_back(right[r]);
   		r++;
  	}
        else{
            result.push_back(left[l]);
            l++;
        }
	}
 	while (l < left.size()) {
  		result.push_back(left[l]);
  		l++;
 	}
 	while (r < right.size()) {
  		result.push_back(right[r]);
  		r++;
 	}
 	return result;
}

vector<int> merge_sort(vector<int> v) {
	if (v.size() == 1) {
	return v;
    }
	vector <int> l, r;
    int x = v.size();
    
    for (int i = 0; i < x / 2; i++) {
        l.push_back(v[i]);
    }
    for (int i = x / 2; i < x; i++) {
        r.push_back(v[i]);
    }
    l = merge_sort(l);
    r = merge_sort(r);
    
    return merge(l, r);
}
int main() {
    int x, y;
    cin >> x >> y;
    vector<int> v1(x);
    vector<int> v2(y);
    for(int i = 0; i < x; i++){
		cin >> v1[i];
    }for(int i = 0; i < y; i++){
		cin >> v2[i];
    }
	
	if(x == 0 || y == 0){
		return 0;
	}
    v1 = merge_sort(v1);
    v2 = merge_sort(v2);
    int l1 = 0, l2 = 0;
    
    while(l1 < x && l2 < y){
        if(v1[l1] == v2[l2]){
            cout << v1[l1] << ' ';
            l1++;
            l2++;
        }
        else if(v1[l1] < v2[l2]){
			l1++;
        }else{
			l2++;
		}
    }

    return 0;
}