#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    vector<int> a, b;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            a.push_back(x[i]);
        } else {
            b.push_back(x[i]);
        }
    }
    vector<int> cnta(100003, 0);
    vector<int> cntb(100003, 0);
    int vala = 0, vala1 = 0, maxCnta = 0, maxCnta1 = 0;
    for (int i : a) {
        cnta[i]++;
    }
    for (int i : a) {
        if (maxCnta < cnta[i]) {
            vala = i;
            maxCnta = cnta[i];
        }
    }
    for (int i : a) {
        if (maxCnta1 < cnta[i] && vala != i) {
            maxCnta1 = cnta[i];
            vala1 = i;
        }
    }
    int valb = 0, valb1 = 0, maxCntb = 0, maxCntb1 = 0;
    for (int i : b) {
        cntb[i]++;
    }
    for (int i : b) {
        if (maxCntb < cntb[i]) {
            valb = i;
            maxCntb = cntb[i];
        }
    }
    for (int i : b) {
        if (maxCntb1 < cntb[i] && valb != i) {
            maxCntb1 = cntb[i];
            valb1 = i;
        }
    }
    if (valb != vala) {
        int res = 0;
        for (int i : a) {
            if (i != vala) {
                res++;
            }
        }
        for (int i : b) {
            if (i != valb) {
                res++;
            }
        }
        cout << res << endl;
    } else {
        int resa = 0, resb = 0, resa1 = 0, resb1 = 0;
        for (int i : a) {
            if (i != vala) {
                resa++;
            }
            if (i != vala1) {
                resa1++;
            }
        }
        for (int i : b) {
            if (i != valb) {
                resb++;
            }
            if (i != valb1) {
                resb1++;
            }
        }
        cout << min(resa + resb1, resa1 + resb) << endl;
    }
    return 0;
}
