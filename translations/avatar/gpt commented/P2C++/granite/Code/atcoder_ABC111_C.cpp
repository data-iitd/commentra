
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

    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            a.push_back(x[i]);
        } else {
            b.push_back(x[i]);
        }
    }

    vector<int> cnta(100002 + 1, 0);
    vector<int> cntb(100002 + 1, 0);

    for (int i = 0; i < a.size(); i++) {
        cnta[a[i]]++;
    }

    for (int i = 0; i < b.size(); i++) {
        cntb[b[i]]++;
    }

    int vala = 0, maxCnta = 0;
    for (int i = 0; i < cnta.size(); i++) {
        if (maxCnta < cnta[i]) {
            vala = i;
            maxCnta = cnta[i];
        }
    }

    int valb = 0, maxCntb = 0;
    for (int i = 0; i < cntb.size(); i++) {
        if (maxCntb < cntb[i]) {
            valb = i;
            maxCntb = cntb[i];
        }
    }

    if (vala!= valb) {
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
        int resa = 0, resa1 = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i]!= vala) {
                resa++;
            }
            if (a[i]!= vala) {
                resa1++;
            }
        }

        int resb = 0, resb1 = 0;
        for (int i = 0; i < b.size(); i++) {
            if (b[i]!= valb) {
                resb++;
            }
            if (b[i]!= valb) {
                resb1++;
            }
        }

        cout << min(resa + resb1, resa1 + resb) << endl;
    }

    return 0;
}
