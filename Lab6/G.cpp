#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool compare(pair<string, string> p1, pair<string, string> p2){
    return p1.first < p2.first;
}

int partition(vector<pair<string, string> > v, int l, int r){
    int ind = l;
    pair<string, string> pivot = v[r];
    for(int i = l; i < r; i++){
        if(compare(v[i], pivot)){
            swap(v[i], v[ind]);
            ind++;
        }
    }
    swap(v[ind], v[r]);
    return ind;
}

void quicksort(vector<pair<string, string> > v, int l, int r){
    if(l < r){
        int p = partition(v, l, r);
        quicksort(v, l, p - 1);
        quicksort(v, p + 1, r);
    }
}

int main() {
    int x;
    cin >> x;
    vector<pair<string, string> > v;
    
	while(x--){
        string s1, s2;
        cin >> s1 >> s2;
        bool check = false;
        for(int i = 0; i < v.size(); i++){
            if(s1 == v[i].second){
                v[i].second = s2;
                check = true;
            }
        }
        if(!check){
			v.push_back(make_pair(s1, s2));
		}
    }
    

    quicksort(v, 0, v.size() - 1);

    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i].first << ' ' << v[i].second << endl;
    }
    

    return 0;
}
