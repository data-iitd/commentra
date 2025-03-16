#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i];
    }

    std::vector<int> a, b;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            a.push_back(x[i]);
        } else {
            b.push_back(x[i]);
        }
    }

    std::unordered_map<int, int> cnta, cntb;
    for (int i : a) {
        cnta[i]++;
    }
    for (int i : b) {
        cntb[i]++;
    }

    int vala = 0, vala1 = 0, maxCnta = 0;
    for (auto& p : cnta) {
        if (p.second > maxCnta) {
            vala = p.first;
            maxCnta = p.second;
        }
    }
    int maxCnta1 = 0;
    for (auto& p : cnta) {
        if (p.second > maxCnta1 && p.first != vala) {
            vala1 = p.first;
            maxCnta1 = p.second;
        }
    }

    int valb = 0, valb1 = 0, maxCntb = 0;
    for (auto& p : cntb) {
        if (p.second > maxCntb) {
            valb = p.first;
            maxCntb = p.second;
        }
    }
    int maxCntb1 = 0;
    for (auto& p : cntb) {
        if (p.second > maxCntb1 && p.first != valb) {
            valb1 = p.first;
            maxCntb1 = p.second;
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
        std::cout << res << std::endl;
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
        std::cout << std::min(resa + resb1, resa1 + resb) << std::endl;
    }

    return 0;
}
