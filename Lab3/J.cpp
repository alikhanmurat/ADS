#include <bits/stdc++.h>
using namespace std;

bool isPossible(int a[], int m, int y, int x) {
    int h = 0;
    for (int i = 0; i < x; i++) {
        h += (a[i] + m - 1) / m;  
    }
    return h <= y;
}

int minCapacity(int a[], int y, int x) {
    int l = 1;
    int r = *max_element(a, a + x); 

    while (l < r) {  
        int m = l + (r - l) / 2;  
        if (isPossible(a, m, y, x))
            r = m;
        else
            l = m + 1;
    }

    return l;
}

int main() {
    int x, y;
    cin >> x >> y;

	int a[x];
    for (int i = 0; i < x; i++) {
        cin >> a[i];
    }

    int capacity = minCapacity(a, y, x);
    cout << capacity << endl;

    return 0;
}
