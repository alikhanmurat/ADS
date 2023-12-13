#include <bits/stdc++.h>
#define ll long long int
using namespace std;


struct Heap {
    ll *a;
    ll capacity;
    ll size;

    long long parent(long long i) {
        return (i - 1)/2;
    }

    long long left(long long i) {
        return i*2 + 1;
    }

    long long right(long long i) {
        return i*2 + 2;
    }

    void heapUp(long long i) {
        if (i > 0) {
            long long p = parent(i);
            if (a[i] > a[p]) {
                swap(a[i], a[p]);
                heapUp(p);
            }
        }
        
    }

    void heapDown(long long i) {
        ll l = left(i);
        ll r = right(i);
        ll max = i;
        if (l < this->size && a[max] < a[l]) {
            max = l;
        }
        if (r < this->size && a[max] < a[r]) {
            max = r;
        }
        if (max != i) {
            swap(a[i], a[max]);
            heapDown(max);
        }
    }

    void add(long long x) {
        a[size] = x;
        size++;
        heapUp(size - 1);
    }

    void cut_max() {
        a[0] = a[size-1];
        size = max((long long)0, size - 1);
        heapDown(0);
    }

    Heap(long long x) {
        a = new long long[x];
        this->capacity = x;
        this->size = 0;
    }
};

int main() {
    ll n, x; 
	cin >> n >> x;
    Heap H(n);
    for (long long i = 0; i < n; i++) {
        ll a; 
		cin >> a;
        H.add(a);
    }
    ll sum = 0;
    while(x--) {
        sum += H.a[0];
        ll newMax = max((long long)0, H.a[0] - 1);
        H.cut_max();
        H.add(newMax);
    }
    cout << sum;
}