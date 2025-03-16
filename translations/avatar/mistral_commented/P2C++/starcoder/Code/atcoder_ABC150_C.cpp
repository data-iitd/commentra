#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Ask the user for the size of the permutation list
    int n;
    cin >> n;

    // Create a list of all possible permutations of numbers from 1 to n
    vector<vector<int>> orig;
    for (int i = 1; i <= n; i++) {
        vector<int> v;
        for (int j = 1; j <= n; j++) {
            v.push_back(j);
        }
        orig.push_back(v);
    }

    // Ask the user for two permutations as tuples
    vector<int> p, q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push_back(x);
    }

    // Find the indices of p and q in the orig list
    int pn = -1, qn = -1;
    for (int i = 0; i < orig.size(); i++) {
        if (orig[i] == p) {
            pn = i;
        }
        if (orig[i] == q) {
            qn = i;
        }
    }

    // Print the absolute difference between the indices of p and q
    cout << abs(pn - qn) << endl;

    return 0;
}

