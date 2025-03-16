#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Card {
    char s;
    int v;
};

vector<Card> L(100000/2+2), R(100000/2+2);

void merge(vector<Card>& a, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l;
    int n2 = r - m;

    for (i = 0; i < n1; i++) L[i] = a[l + i];
    for (i = 0; i < n2; i++) R[i] = a[m + i];
    L[n1].v = R[n2].v = 2000000000;
    i = 0;
    j = 0;
    for (k = l; k < r; k++) {
        if (L[i].v <= R[j].v) {
            a[k] = L[i++];
        } else {
            a[k] = R[j++];
        }
    }
}

void merge_sort(vector<Card>& a, int l, int r) {
    if (l + 1 < r) {
        int m = (l + r) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m, r);
        merge(a, l, m, r);
    }
}

int partition(vector<Card>& a, int p, int r) {
    Card x = a[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (a[j].v <= x.v) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void quick_sort(vector<Card>& a, int p, int r) {
    if (p < r) {
        int q = partition(a, p, r);
        quick_sort(a, p, q - 1);
        quick_sort(a, q + 1, r);
    }
}

int main() {
    int n;
    cin >> n;

    vector<Card> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].s >> a[i].v;
        b[i] = a[i];
    }

    merge_sort(a, 0, n);
    quick_sort(b, 0, n - 1);

    bool stable = true;
    for (int i = 0; i < n; i++) {
        if (a[i].s != b[i].s) {
            stable = false;
            break;
        }
    }

    if (stable) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }

    for (int i = 0; i < n; i++) {
        cout << b[i].s << " " << b[i].v << endl;
    }

    return 0;
}
