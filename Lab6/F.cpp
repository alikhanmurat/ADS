#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool cmp(pair<pair<string, string>, double> p1, pair<pair<string, string>, double> p2){
    if(p1.second < p2.second){
		return true;
    }if(p1.second == p2.second && p1.first.first < p2.first.first){
		return true;
    }if(p1.second == p2.second && p1.first.first == p2.first.first && p1.first.second < p2.first.second){
		return true;
    }
	
	return false;
}
int partition_GPA(vector<pair<pair<string, string>, double>>  v, int l, int r){
    pair<pair<string, string>, double> pivot = v[r];
    int i = l-1;
    for(int j = l; j <= r-1; j++){
        if(cmp(v[j], pivot)){
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1], v[r]);
    return (i+1);
}
void quick_sort_GPA(vector<pair<pair<string, string>, double>> v, int l, int r){
    if(l < r){
        int p = partition_GPA(v, l, r);
        quick_sort_GPA(v, l, p-1);
        quick_sort_GPA(v, p+1, r);
    }
}
void quick_sort_Surname(vector <pair<pair<string, string>, double>> v, int l, int r){
    if(r < l+1){
	return;
    }
	int mid = (l + r) / 2;
    pair<pair<string, string>, double> pivot = v[mid];
    int j = l;
    swap(v[r], v[mid]);
    for(int i = l; i <= r; i++){
        if(v[i].first.first < pivot.first.first){
            swap(v[i], v[j]);
            j++;
        }
    }
    swap(v[j],v[r]);
    quick_sort_Surname(v, l, j-1);
    quick_sort_Surname(v, j+1, r);
}
void quick_sort_Name(vector <pair<pair<string,string>,double>>&v,int l,int r){
    if(r<l+1){
	return;
    }
	int mid = (l + r) / 2;
    pair<pair<string, string>, double> pivot = v[mid];
    int j = l;
    swap(v[r], v[mid]);
    for(int i = l; i <= r; i++){
        if(v[i].first.second < pivot.first.second){
            swap(v[i], v[j]);
            j++;
        }
    }
    swap(v[j],v[r]);
    quick_sort_Name(v, l, j-1);
    quick_sort_Name(v, j+1, r);
}
int main(){
    ll x; 
	cin>> x;
    vector<pair<pair<string, string>, double>> v;
    map <string, double> m {{"A+", 4.00}, {"A", 3.75}, {"B+", 3.50}, {"B", 3.00}, {"C+", 2.50}, {"C", 2.00}, {"D+", 1.50}, {"D", 1.00}, {"F", 0}};
    for(int i = 0; i < x; i++){
        string s1, s2; 
		cin >> s1 >> s2;
        int y; 
		cin >> y;
        double res = 0;
        int cnt_sum = 0;
        for(int i = 0; i < y; i++){
            string a; 
			cin >> a;
            int b; 
			cin >> b;
            res += m[a] * b;
            cnt_sum += b;
        }
        res /= cnt_sum;
        pair<pair<string, string>, double> GPA;
        GPA.first.first = s1;
        GPA.first.second = s2;
        GPA.second = res;
        v.push_back(GPA);
    }
    quick_sort_GPA(v, 0, v.size()-1);

    for(auto i : v){
        cout << i.first.first << " " << i.first.second << " ";
        printf("%0.3f", i.second);
        cout << endl;
    }
}