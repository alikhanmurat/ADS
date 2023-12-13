#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<int> prefixFunction(string s1) {
    vector <int> v(s1.size());
    v[0] = 0;
    for (int i = 1; i < s1.size(); i++) {
        int j = v[i - 1];
        while (j > 0 && s1[j] != s1[i]) {
            j = v[j - 1];
        }
        if (s1[j] == s1[i]) {
            v[i] = j + 1;
        } else {
            v[i] = 0;
        }
    }

    return v;
}

vector<int> kmp(string s1, string s2) {
    s1 = s2 + '#' + s1;
    vector <int> v1;
    vector <int> v2 = prefixFunction(s1);
    for (int i = 0; i < s1.size(); i++) {
        if (v2[i] == s2.size()) {
            v1.push_back(i - 2 * s2.size());
        }
    }
    return v1;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    vector <int> v = kmp(s1, s2);
 
    cout << v.size() << endl;
 
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] + 1 << ' ';
    }
	cout << endl;
}