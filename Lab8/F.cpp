#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int substrings(const string& s) {
    ll x = s.length();
    vector <int> sArray(x);
    vector <int> lcp(x, 0);

    for (int i = 0; i < x; i++) {
        sArray[i] = i;
    }

    sort(sArray.begin(), sArray.end(), [&s](int a, int b) {
        return s.substr(a) < s.substr(b);
    });

    for (int i = 1; i < x; i++) {
        ll j = sArray[i - 1];
        ll k = sArray[i];
        while (k < x && j < x && s[j] == s[k]) {
            lcp[i]++;
            j++;
            k++;
        }
    }

    ll dSubstrings = x - sArray[0];
    for (int i = 1; i < x; i++) {
        dSubstrings += (x - sArray[i]) - lcp[i];
    }

    return dSubstrings;
}

int main() {
    string s;
    cin >> s;
    cout << substrings(s);
    return 0;
}