#include <iostream>
#include <vector>
#include <string>

struct Card {
    char s;
    int v;
};

std::vector<Card> L(100000 / 2 + 2), R(100000 / 2 + 2);

void merge(std::vector<Card>& a, int l, int m, int r) {
    int n1 = m - l;
    int n2 = r - m;

    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int i = 0; i < n2; i++) R[i] = a[m + i];
    L[n1].v = R[n2].v = 2000000000;

    int i = 0, j = 0;
    for (int k = l; k < r; k++) {
        if (L[i].v <= R[j].v) {
            a[k] = L[i++];
        } else {
            a[k] = R[j++];
        }
    }
}

void mergeSort(std::vector<Card>& a, int l, int r) {
    if (l + 1 < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m, r);
        merge(a, l, m, r);
    }
}

int partition(std::vector<Card>& a, int p, int r) {
    Card x = a[r];
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (a[j].v <= x.v) {
            i++;
            std::swap(a[i], a[j]);
        }
    }
    std::swap(a[i + 1], a[r]);
    return i + 1;
}

void quickSort(std::vector<Card>& a, int p, int r) {
    if (p < r) {
        int q = partition(a, p, r);
        quickSort(a, p, q - 1);
        quickSort(a, q + 1, r);
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Card> a(n), b(n);
    std::string s;
    bool stable = true;

    for (int i = 0; i < n; i++) {
        std::cin >> s >> a[i].v;
        a[i].s = b[i].s = s[0];
        b[i].v = a[i].v;
    }

    mergeSort(a, 0, n);
    quickSort(b, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if (a[i].s != b[i].s) {
            stable = false;
        }
    }

    if (stable) {
        std::cout << "Stable\n";
    } else {
        std::cout << "Not stable\n";
    }

    for (int i = 0; i < n; i++) {
        std::cout << b[i].s << " " << b[i].v << "\n";
    }

    return 0;
}

// <END-OF-CODE>
