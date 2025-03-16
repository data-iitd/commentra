#include <bits/stdc++.h>
using namespace std;

int main() {
    // Read the number of elements
    int n;
    cin >> n;

    // Read the elements into a list
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    // Initialize two lists to hold elements at even and odd indices
    vector<int> a;
    vector<int> b;

    // Distribute elements into lists based on their index (even or odd)
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            a.push_back(x[i]);  // Append to list 'a' if index is even
        } else {
            b.push_back(x[i]);  // Append to list 'b' if index is odd
        }
    }

    // Initialize counters for occurrences of elements in lists 'a' and 'b'
    vector<int> cnta(100002 + 1, 0);
    vector<int> cntb(100002 + 1, 0);

    // Variables to track the most frequent elements in list 'a'
    int vala = 0;
    int vala1 = 0;
    int maxCnta = 0;
    int maxCnta1 = 0;

    // Count occurrences of each element in list 'a'
    for (int i = 0; i < a.size(); i++) {
        cnta[a[i]] += 1;
    }

    // Find the most frequent element in list 'a'
    for (int i = 0; i < a.size(); i++) {
        if (maxCnta < cnta[a[i]]) {
            vala = a[i];
            maxCnta = cnta[a[i]];
        }
    }

    // Find the second most frequent element in list 'a'
    for (int i = 0; i < a.size(); i++) {
        if (maxCnta1 < cnta[a[i]] && vala!= a[i]) {
            maxCnta1 = cnta[a[i]];
            vala1 = a[i];
        }
    }

    // Variables to track the most frequent elements in list 'b'
    int valb = 0;
    int valb1 = 0;
    int maxCntb = 0;
    int maxCntb1 = 0;

    // Count occurrences of each element in list 'b'
    for (int i = 0; i < b.size(); i++) {
        cntb[b[i]] += 1;
    }

    // Find the most frequent element in list 'b'
    for (int i = 0; i < b.size(); i++) {
        if (maxCntb < cntb[b[i]]) {
            valb = b[i];
            maxCntb = cntb[b[i]];
        }
    }

    // Find the second most frequent element in list 'b'
    for (int i = 0; i < b.size(); i++) {
        if (maxCntb1 < cntb[b[i]] && valb!= b[i]) {
            maxCntb1 = cntb[b[i]];
            valb1 = b[i];
        }
    }

    // Check if the most frequent elements from both lists are different
    if (valb!= vala) {
        int res = 0;
        // Count elements in 'a' that are not the most frequent element
        for (int i = 0; i < a.size(); i++) {
            if (a[i]!= vala) {
                res += 1;
            }
        }
        // Count elements in 'b' that are not the most frequent element
        for (int i = 0; i < b.size(); i++) {
            if (b[i]!= valb) {
                res += 1;
            }
        }
        // Print the total count of elements that are not the most frequent
        cout << res << endl;
    } else {
        // Initialize counters for elements not equal to the most frequent elements
        int resa = 0;
        int resb = 0;
        int resa1 = 0;
        int resb1 = 0;

        // Count elements in 'a' that are not the most frequent and second most frequent
        for (int i = 0; i < a.size(); i++) {
            if (a[i]!= vala) {
                resa += 1;
            }
            if (a[i]!= vala1) {
                resa1 += 1;
            }
        }

        // Count elements in 'b' that are not the most frequent and second most frequent
        for (int i = 0; i < b.size(); i++) {
            if (b[i]!= valb) {
                resb += 1;
            }
            if (b[i]!= valb1) {
                resb1 += 1;
            }
        }

        // Print the minimum of the two possible results
        cout << min(resa + resb1, resa1 + resb) << endl;
    }

    return 0;
}

