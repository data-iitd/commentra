
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;  // Read an integer n from input
    vector<int> x(n);  // Read a list of integers x from input and store in vector x
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    // Split the vector x into two vectors, a and b, based on their indices (even and odd)
    vector<int> a;
    vector<int> b;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            a.push_back(x[i]);
        } else {
            b.push_back(x[i]);
        }
    }

    // Initialize two vectors to count the frequency of each element in a and b
    vector<int> cnta(100002 + 1, 0);
    vector<int> cntb(100002 + 1, 0);

    // Find the most frequent element in list a and its first and second most frequent elements
    int vala = 0;
    int vala1 = 0;
    int maxCnta = 0;
    int maxCnta1 = 0;
    for (int i = 0; i < a.size(); i++) {
        cnta[a[i]] += 1;
    }
    for (int i = 0; i < a.size(); i++) {
        if (maxCnta < cnta[a[i]]) {
            vala = a[i];
            maxCnta = cnta[a[i]];
        }
    }
    for (int i = 0; i < a.size(); i++) {
        if (maxCnta1 < cnta[a[i]] && vala!= a[i]) {
            maxCnta1 = cnta[a[i]];
            vala1 = a[i];
        }
    }

    // Find the most frequent element in list b and its first and second most frequent elements
    int valb = 0;
    int valb1 = 0;
    int maxCntb = 0;
    int maxCntb1 = 0;
    for (int i = 0; i < b.size(); i++) {
        cntb[b[i]] += 1;
    }
    for (int i = 0; i < b.size(); i++) {
        if (maxCntb < cntb[b[i]]) {
            valb = b[i];
            maxCntb = cntb[b[i]];
        }
    }
    for (int i = 0; i < b.size(); i++) {
        if (maxCntb1 < cntb[b[i]] && valb!= b[i]) {
            maxCntb1 = cntb[b[i]];
            valb1 = b[i];
        }
    }

    // Compare the most frequent elements of a and b
    if (valb!= vala) {
        int res = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i]!= vala) {
                res += 1;
            }
        }
        for (int i = 0; i < b.size(); i++) {
            if (b[i]!= valb) {
                res += 1;
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
                resa += 1;
            }
            if (a[i]!= vala1) {
                resa1 += 1;
            }
        }
        for (int i = 0; i < b.size(); i++) {
            if (b[i]!= valb) {
                resb += 1;
            }
            if (b[i]!= valb1) {
                resb1 += 1;
            }
        }
        cout << min(resa + resb1, resa1 + resb) << endl;
    }

    return 0;
}
