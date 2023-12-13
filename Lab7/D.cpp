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
    }return false;
}
void mergeOne(vector <pair<pair<string,string>, double>> &v, int l, int m, int r){
    int i = 0;
    int j = 0;
    int k = l;
    int n1 = m - l + 1;
    int n2 = r - m;
    vector <pair<pair<string, string>, double>> L(n1);
    vector <pair<pair<string, string>, double>> R(n2);
    
	for(int i = 0; i < n1; i++){
        L[i] = v[l + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = v[m + 1 + j];
    }
    while(i < n1 && j < n2){
        if(cmp(L[i],R[j])){
            v[k] = L[i++];
        }
        else{
            v[k] = R[j++]; 
        }
        k++;
    }
    while(i < n1){
        v[k++] = L[i++];
    }
    while(j < n2){
        v[k++] = R[j++];
    }
}
void mergeSort(vector <pair<pair<string,string>,double>> &v, int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        mergeSort(v, m+1, r);
        mergeSort(v, l, m);
        mergeOne(v, l, m, r);
    }
}
int main(){
    int x; 
	cin >> x;
    vector<pair<pair<string, string>, double>> v;
    map <string, double> m {{"A+", 4.00}, {"A", 3.75}, {"B+", 3.50}, {"B", 3.00}, {"C+", 2.50}, {"C", 2.00}, {"D+", 1.50}, {"D", 1.00}, {"F", 0}};
    for(int i = 0; i < x; i++){
        string s1, s2; 
		cin >> s1 >> s2;
        int y; 
		cin >> y;
        double res=0;
        int sum = 0;
        
        for(int i = 0; i < y; i++){
            string s; 
			cin >> s;
            int z; 
			cin >> z;
            res += m[s] * z;
            sum += z;
        }
        res /= sum;
        pair<pair<string, string>, double> pairs;
        pairs.first.first = s1;
        pairs.first.second = s2;
        pairs.second = res;
        v.push_back(pairs);
    }
    mergeSort(v, 0, v.size()-1);
    for(auto i : v){
        cout << i.first.first << " " << i.first.second << " ";
        printf("%0.3f", i.second);
        cout << endl;
    }
}