#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool isPossible(int a[], int x, int m, int y) {
    int cnt = 0;
    for (int i = 0; i < x; ++i) {
        cnt += (a[i] + m - 1) / m;  
    }
    return cnt <= y;
}

int minCapacity(int a[], int x, int y) {
    int l = 1;  
    int r = *max_element(a, a + x);  
 
    while (l < r) {
        int m = l + (r - l) / 2; 
        if (isPossible(a, x, m, y))
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
    for (int i = 0; i < x; ++i) {
        cin >> a[i];
    }

    int capacity = minCapacity(a, x, y);
    cout << capacity;

    return 0;
}
