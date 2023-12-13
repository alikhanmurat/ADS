#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

int main() {

    int x, y, z, w;
    cin >> x;
    int a[x];

    for(int i = 0; i < x; ++i) {
        cin >> a[i];
    }

    cin >> z >> w;
    vector <int> v1, v2;
    for(int i = 0; i < z; ++i) {
        for(int j = 0; j < w; ++j) {
            cin >> y;
            if(i % 2 == 0) {
                v1.push_back(y);
            } else {
                v2.push_back(y);
            }
        }
        if(!v2.empty()) {
            for(int j = w - 1; j >= 0; --j) {
                v1.push_back(v2[j]);
            }
            v2.clear();
        }
    }

    for(int i = 0; i < x; i++) {
        int l = 0;
        int r = (z * w) - 1;

        while(l <= r) {
            if(a[i] < v1[r] || a[i] > v1[l]) {
                cout << -1 << endl;
                break;
            }
            int m = (l + r)/2;
            if(v1[m] == a[i]) {
                cout << m / w << " ";
                if((m / w) % 2 == 0) {
                    cout << m % w << endl;
                } else { 
                    cout << w - (m % w) - 1 << endl;
                }
                break;
            } else if (v1[m] < a[i]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
    }

    return 0;
}