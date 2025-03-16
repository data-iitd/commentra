#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> low(200000);
vector<int> high(200000);

int part(vector<int>& a, vector<int>& b, int l, int r) {
    int i = l - 1;
    int j = r;
    int x = b[r];

    while (true) {
        while (b[++i] < x);
        while (i < --j && x < b[j]);

        if (i >= j) break;

        swap(a[i], a[j]);
        swap(b[i], b[j]);
    }

    swap(a[i], a[r]);
    swap(b[i], b[r]);
    return i;
}

void quicksort(vector<int>& a, vector<int>& b, int n) {
    int l, r, v;
    int sp = 1;

    low[0] = 0;
    high[0] = n - 1;

    while (sp > 0) {
        sp--;
        l = low[sp];
        r = high[sp];

        if (l >= r) continue;

        v = part(a, b, l, r);

        if (v - l < r - v) {
            low[sp] = v + 1;
            high[sp++] = r;
            low[sp] = l;
            high[sp++] = v - 1;
        } else {
            low[sp] = l;
            high[sp++] = v - 1;
            low[sp] = v + 1;
            high[sp++] = r;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    vector<int> b(m);
    int cnt = 0;
    int t;

    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }

    quicksort(a, b, m);

    t = 0;
    for (int i = 0; i < m; i++) {
        if (t <= a[i]) {
            t = b[i];
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}

// <END-OF-CODE>
