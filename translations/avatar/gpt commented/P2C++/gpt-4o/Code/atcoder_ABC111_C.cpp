#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    // Read the number of elements
    int n;
    cin >> n;

    // Read the elements into a vector
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    // Initialize two vectors to hold elements at even and odd indices
    vector<int> a, b;

    // Distribute elements into vectors based on their index (even or odd)
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            a.push_back(x[i]);  // Append to vector 'a' if index is even
        } else {
            b.push_back(x[i]);  // Append to vector 'b' if index is odd
        }
    }

    // Initialize maps to hold occurrences of elements in vectors 'a' and 'b'
    unordered_map<int, int> cnta, cntb;

    // Count occurrences of each element in vector 'a'
    for (int i : a) {
        cnta[i]++;
    }

    // Variables to track the most frequent elements in vector 'a'
    int vala = 0, vala1 = 0, maxCnta = 0, maxCnta1 = 0;

    // Find the most frequent element in vector 'a'
    for (const auto& pair : cnta) {
        if (pair.second > maxCnta) {
            vala1 = vala;
            maxCnta1 = maxCnta;
            vala = pair.first;
            maxCnta = pair.second;
        } else if (pair.second > maxCnta1 && pair.first != vala) {
            vala1 = pair.first;
            maxCnta1 = pair.second;
        }
    }

    // Count occurrences of each element in vector 'b'
    for (int i : b) {
        cntb[i]++;
    }

    // Variables to track the most frequent elements in vector 'b'
    int valb = 0, valb1 = 0, maxCntb = 0, maxCntb1 = 0;

    // Find the most frequent element in vector 'b'
    for (const auto& pair : cntb) {
        if (pair.second > maxCntb) {
            valb1 = valb;
            maxCntb1 = maxCntb;
            valb = pair.first;
            maxCntb = pair.second;
        } else if (pair.second > maxCntb1 && pair.first != valb) {
            valb1 = pair.first;
            maxCntb1 = pair.second;
        }
    }

    // Check if the most frequent elements from both vectors are different
    if (valb != vala) {
        int res = 0;
        // Count elements in 'a' that are not the most frequent element
        for (int i : a) {
            if (i != vala) {
                res++;
            }
        }
        // Count elements in 'b' that are not the most frequent element
        for (int i : b) {
            if (i != valb) {
                res++;
            }
        }
        // Print the total count of elements that are not the most frequent
        cout << res << endl;
    } else {
        // Initialize counters for elements not equal to the most frequent elements
        int resa = 0, resb = 0, resa1 = 0, resb1 = 0;

        // Count elements in 'a' that are not the most frequent and second most frequent
        for (int i : a) {
            if (i != vala) {
                resa++;
            }
            if (i != vala1) {
                resa1++;
            }
        }

        // Count elements in 'b' that are not the most frequent and second most frequent
        for (int i : b) {
            if (i != valb) {
                resb++;
            }
            if (i != valb1) {
                resb1++;
            }
        }

        // Print the minimum of the two possible results
        cout << min(resa + resb1, resa1 + resb) << endl;
    }

    return 0;
}
// <END-OF-CODE>
