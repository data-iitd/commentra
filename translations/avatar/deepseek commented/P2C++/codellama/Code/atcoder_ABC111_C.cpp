#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    // Split the list x into two lists, a and b, based on their indices (even and odd)
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            a.push_back(x[i]);
        } else {
            b.push_back(x[i]);
        }
    }

    // Initialize two lists to count the frequency of each element in a and b
    vector<int> cnta(100002, 0), cntb(100002, 0);

    // Find the most frequent element in list a and its first and second most frequent elements
    int vala = 0, vala1 = 0, maxCnta = 0, maxCnta1 = 0;
    for (int i = 0; i < a.size(); i++) {
        cnta[a[i]]++;
    }
    for (int i = 0; i < a.size(); i++) {
        if (maxCnta < cnta[a[i]]) {
            vala = a[i];
            maxCnta = cnta[a[i]];
        }
    }
    for (int i = 0; i < a.size(); i++) {
        if (maxCnta1 < cnta[a[i]] && vala != a[i]) {
            maxCnta1 = cnta[a[i]];
            vala1 = a[i];
        }
    }

    // Find the most frequent element in list b and its first and second most frequent elements
    int valb = 0, valb1 = 0, maxCntb = 0, maxCntb1 = 0;
    for (int i = 0; i < b.size(); i++) {
        cntb[b[i]]++;
    }
    for (int i = 0; i < b.size(); i++) {
        if (maxCntb < cntb[b[i]]) {
            valb = b[i];
            maxCntb = cntb[b[i]];
        }
    }
    for (int i = 0; i < b.size(); i++) {
        if (maxCntb1 < cntb[b[i]] && valb != b[i]) {
            maxCntb1 = cntb[b[i]];
            valb1 = b[i];
        }
    }

    // Compare the most frequent elements of a and b
    if (valb != vala) {
        int res = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != vala) {
                res++;
            }
        }
        for (int i = 0; i < b.size(); i++) {
            if (b[i] != valb) {
                res++;
            }
        }
        cout << res << endl;
    } else {
        int resa = 0, resb = 0, resa1 = 0, resb1 = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != vala) {
                resa++;
            }
            if (a[i] != vala1) {
                resa1++;
            }
        }
        for (int i = 0; i < b.size(); i++) {
            if (b[i] != valb) {
                resb++;
            }
            if (b[i] != valb1) {
                resb1++;
            }
        }
        cout << min(resa + resb1, resa1 + resb) << endl;
    }

    return 0;
}

