#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector <int> prefixFunction(string s2) {
    vector<int> v(s2.size());
    v[0] = 0;
    for (int i = 1; i < s2.size(); i++) {
        int j = v[i - 1];
        while (j > 0 && s2[j] != s2[i]) {
            j = v[j - 1];
        }
        if (s2[j] == s2[i]) {
            v[i] = j + 1;
        } else {
            v[i] = 0;
        }
    }

    return v;
}

int password(string s1, string s2) {
    s2 = s1 + '#' + s2;
    int cnt = 0;
    vector <int> v = prefixFunction(s2);
    
    for (int i = 0; i < s2.size(); i++) {
        if (v[i] == s1.size()){
			cnt++;
		}
    }
    return cnt;
}

int main() {
    string s1, s2;
    int x;
    cin >> s1 >> x >> s2;
    cout << ((password(s1, s2) >= x) ? "YES\n" : "NO\n");
    return 0;
}