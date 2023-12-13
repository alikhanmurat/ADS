#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    int a[x];

    for (int i = 0; i < x; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int d = max(max(abs(x1), abs(x2)), max(abs(y1), abs(y2)));  
        // int d = max({a, b, c, d});
        a[i] = d;
    }

    sort(a, a + x);

    cout << a[y - 1];

    return 0;
}

