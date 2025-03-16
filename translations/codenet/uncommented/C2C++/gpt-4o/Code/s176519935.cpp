#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
public:
    vector<long long> heap;
    long long sz;

    MaxHeap() : sz(0) {}

    void push(long long x) {
        int i = sz++;
        heap.push_back(x);
        while (i > 0) {
            int p = (i - 1) / 2;
            if (heap[p] >= x) break;
            heap[i] = heap[p];
            i = p;
        }
        heap[i] = x;
    }

    long long pop() {
        long long ret = heap[0];
        long long x = heap[--sz];
        heap[sz] = x; // Move the last element to the root
        int i = 0;
        while (i * 2 + 1 < sz) {
            int a = i * 2 + 1, b = i * 2 + 2;
            if (b < sz && heap[b] > heap[a]) a = b;
            if (heap[a] <= x) break;
            heap[i] = heap[a];
            i = a;
        }
        heap[i] = x;
        return ret;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    MaxHeap maxHeap;
    vector<long long> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxHeap.push(a[i]);
    }
    
    for (int i = 0; i < m; i++) {
        long long tm = maxHeap.pop();
        tm /= 2;
        maxHeap.push(tm);
    }
    
    long long ans = 0;
    for (int i = 0; i < maxHeap.sz; i++) {
        ans += maxHeap.heap[i];
    }
    
    cout << ans << endl;
    return 0;
}

// <END-OF-CODE>
