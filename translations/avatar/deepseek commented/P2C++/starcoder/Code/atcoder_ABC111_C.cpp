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

    vector<int> a;
    vector<int> b;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            a.push_back(x[i]);
        } else {
            b.push_back(x[i]);
        }
    }

    vector<int> cnta(100002, 0);
    vector<int> cntb(100002, 0);
    for (int i = 0; i < a.size(); i++) {
        cnta[a[i]]++;
    }
    for (int i = 0; i < b.size(); i++) {
        cntb[b[i]]++;
    }

    int vala = 0;
    int vala1 = 0;
    int maxCnta = 0;
    int maxCnta1 = 0;
    for (int i = 0; i < 100002; i++) {
        if (maxCnta < cnta[i]) {
            vala = i;
            maxCnta = cnta[i];
        }
    }
    for (int i = 0; i < 100002; i++) {
        if (maxCnta1 < cnta[i] && vala!= i) {
            maxCnta1 = cnta[i];
            vala1 = i;
        }
    }

    int valb = 0;
    int valb1 = 0;
    int maxCntb = 0;
    int maxCntb1 = 0;
    for (int i = 0; i < 100002; i++) {
        if (maxCntb < cntb[i]) {
            valb = i;
            maxCntb = cntb[i];
        }
    }
    for (int i = 0; i < 100002; i++) {
        if (maxCntb1 < cntb[i] && valb!= i) {
            maxCntb1 = cntb[i];
            valb1 = i;
        }
    }

    if (valb!= vala) {
        int res = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i]!= vala) {
                res++;
            }
        }
        for (int i = 0; i < b.size(); i++) {
            if (b[i]!= valb) {
                res++;
            }
        }
        cout << res << endl;
    } else {
        int resa = 0;
        int resb = 0;
        int resa1 = 0;
        int resb1 = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i]!= vala) {
                resa++;
            }
            if (a[i]!= vala1) {
                resa1++;
            }
        }
        for (int i = 0; i < b.size(); i++) {
            if (b[i]!= valb) {
                resb++;
            }
            if (b[i]!= valb1) {
                resb1++;
            }
        }
        cout << min(resa + resb1, resa1 + resb) << endl;
    }

    return 0;
}

