#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> heap;
int sz = 0;

void push(long long x) {
    int i = sz++;
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

int main() {
    int n, m, i, j;
    long long a[100000];
    cin >> n >> m;
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 0; i < n; i++) push(a[i]);
    for (i = 0; i < m; i++) {
        long long tm = pop();
        tm /= 2;
        push(tm);
    }
    long long ans = 0;
    for (i = 0; i < n; i++) ans += heap[i];
    cout << ans << endl;
    return 0;
}

