#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool compare(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2) { 
    if(p1.second < p2.second){
		return true; 
    }if(p1.second == p2.second && p1.first.second < p2.first.second){
	return true; 
    }if(p1.second == p2.second && p1.first.second == p2.first.second && p1.first.first < p2.first.first){
	return true; 
    }
	
	return false; 
} 
int partition(vector <pair<pair<int, int>, int>> v, int l, int r) { 
    pair<pair<int, int>, int> pivot = v[r]; 
    int j = (l - 1); 
    for(int i = l; i <= r - 1; i++) { 
        if(compare(v[j], pivot)) { 
            j++; 
            swap(v[j], v[i]); 
        } 
    } 
    swap(v[j + 1], v[r]); 
    return (j+1); 
} 
 void quickSort(vector <pair<pair<int, int>, int>> v, int l, int r) { 
    if(l < r) { 
        int p = partition(v, l, r); 
        quickSort(v, l, p - 1); 
        quickSort(v, p + 1, r); 
    } 
}
 
int convert(string s, int l, int r) { 
    int beg = 1; 
    int res = 0; 
    for(int i = l; i < r; i++) { 
        if(s[i] == '0' && i == 0) { 
            res = s[i + 1] - '0'; 
            break;  
        } 
        else { 
            res = beg * res + (s[i] - '0'); 
            beg = 10; 
        } 
    } 
    return res; 
} 
int main(){ 
    int x; 
    cin >> x; 
    vector <pair<pair<int, int>, int>> v; 
    for(int i = 0; i < x; i++) { 
        string s; 
		cin >> s; 
        int day = convert(s, 0, 2); 
        int month = convert(s, 3, 5); 
        int year = convert(s, 6, 10); 
        pair<pair<int, int>, int> date; 
        date.first.first = day; 
        date.first.second = month; 
        date.second = year; 
        v.push_back(date); 
    } 
    quickSort(v, 0, x - 1); 
    for(int i = 0; i < v.size(); i++) { 
        if(v[i].first.first < 10 && v[i].first.second < 10){
			cout << "0" << v[i].first.first << "-0" << v[i].first.second << "-" << v[i].second << endl; 
        }else if(v[i].first.first < 10 && v[i].first.second >= 10){
		cout << "0" << v[i].first.first << "-" << v[i].first.second << "-" << v[i].second << endl; 
        }else if(v[i].first.first >= 10 && v[i].first.second < 10){
			cout << v[i].first.first << "-0" << v[i].first.second << "-" << v[i].second << endl; 
        }else{
		cout << v[i].first.first << "-" << v[i].first.second << "-" << v[i].second << endl;
		}	
		  
    } 
 
}