#include <iostream>
#include <vector>
#include <unordered_map>
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

    unordered_map<int, int> cnta, cntb;

    int vala = 0, vala1 = 0, maxCnta = 0, maxCnta1 = 0;
    for (int i : a) {
        cnta[i]++;
    }

    for (auto& p : cnta) {
        if (maxCnta < p.second) {
            vala = p.first;
            maxCnta = p.second;
        }
    }

    for (auto& p : cnta) {
        if (maxCnta1 < p.second && vala != p.first) {
            maxCnta1 = p.second;
            vala1 = p.first;
        }
    }

    int valb = 0, valb1 = 0, maxCntb = 0, maxCntb1 = 0;
    for (int i : b) {
        cntb[i]++;
    }

    for (auto& p : cntb) {
        if (maxCntb < p.second) {
            valb = p.first;
            maxCntb = p.second;
        }
    }

    for (auto& p : cntb) {
        if (maxCntb1 < p.second && valb != p.first) {
            maxCntb1 = p.second;
            valb1 = p.first;
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
