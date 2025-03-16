#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Take the number of elements in the list from user input
    int n;
    cin >> n;

    // Initialize a vector 'x' to store the input elements
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    // Initialize two vectors 'a' and 'b' to store even and odd indexed elements respectively
    vector<int> a, b;

    // Iterate through the vector 'x' and append even and odd indexed elements to their respective vectors
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            a.push_back(x[i]);
        } else {
            b.push_back(x[i]);
        }
    }

    // Initialize two arrays 'cnta' and 'cntb' to store the count of each element in vectors 'a' and 'b' respectively
    const int MAX_SIZE = 100002;
    vector<int> cnta(MAX_SIZE + 1, 0);
    vector<int> cntb(MAX_SIZE + 1, 0);

    // Initialize variables to store the elements with maximum count in vectors 'a' and 'b'
    int vala = 0, valb = 0;
    int maxCnta = 0, maxCntb = 0;
    int vala1 = 0, valb1 = 0;
    int maxCnta1 = 0, maxCntb1 = 0;

    // Count occurrences in vector 'a'
    for (int i : a) {
        cnta[i]++;
    }

    // Find the element with maximum count in vector 'a'
    for (int i : a) {
        if (maxCnta < cnta[i]) {
            vala = i;
            maxCnta = cnta[i];
        }
    }

    // Find the second element with maximum count in vector 'a'
    for (int i : a) {
        if (maxCnta1 < cnta[i] && i != vala) {
            maxCnta1 = cnta[i];
            vala1 = i;
        }
    }

    // Count occurrences in vector 'b'
    for (int i : b) {
        cntb[i]++;
    }

    // Find the element with maximum count in vector 'b'
    for (int i : b) {
        if (maxCntb < cntb[i]) {
            valb = i;
            maxCntb = cntb[i];
        }
    }

    // Find the second element with maximum count in vector 'b'
    for (int i : b) {
        if (maxCntb1 < cntb[i] && i != valb) {
            maxCntb1 = cntb[i];
            valb1 = i;
        }
    }

    // Check if 'vala' and 'valb' are the same or not
    if (valb != vala) {
        // If they are not the same, calculate the sum of counts of all elements except 'vala' and 'valb'
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
        // If 'vala' and 'valb' are the same, calculate the sum of counts of all elements except 'vala' and the second element with maximum count
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
// <END-OF-CODE>
