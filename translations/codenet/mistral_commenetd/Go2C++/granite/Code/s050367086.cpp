
#include <bits/stdc++.h>
using namespace std;

// Define the MP structure and its methods
struct MP {
    string s;
    vector<int> table;

    void init(string s) {
        this->s = s;
        int n = s.length();
        table.resize(n+1);
        table[0] = -1; // Set first index to -1 for initialization
        int j = -1;
        for (int i = 0; i < n; i++) {
            // While j is not equal to the root of the previous character, update j
            while (j >= 0 && s[i]!= s[j]) {
                j = table[j];
            }
            j++;
            // Set table[i] to the index of the next occurrence of the current character in s
            table[i+1] = j;
        }
    }
};

// Define the root function to calculate the root of a given index in uni array
int root(int i, vector<int>& uni) {
    if (i == uni[i]) {
        return i;
    }
    uni[i] = root(uni[i], uni);
    return uni[i];
}

int main() {
    // Open the standard input and output files
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // Initialize scanner and writer
    string s, t;
    getline(cin, s);
    getline(cin, t);
    int ns = s.length();
    int nt = t.length();
    vector<string> ss(nt-1/ns+1, s);
    string sss = ss[0] + ss[0];
    vector<bool> ok(ns, false);

    // Initialize unordered map mp and array uni for suffix array calculation
    MP mp;
    mp.init(t);
    int m = 0;
    vector<int> uni(ns);
    for (int i = 0; i < ns; i++) {
        uni[i] = i;
    }
    bool o = true;

    // Iterate through all characters in string s
    for (int i = 0; i < ns; i++) {
        // Initialize o to true
        o = true;

        // Iterate through all characters in string t
        for (m = 0; m < nt; m++) {
            // Check if current character in s matches the character at the same position in t
            if (t[m]!= sss[i+m]) {
                // If not, set o to false and break the loop
                o = false;
                break;
            }
        }

        // If all characters match, set ok[i] to true and update variables r and m accordingly
        if (o) {
            i += nt - mp.table[m];
            m = mp.table[m];
        }

        // While characters in s and t do not match, update i and m accordingly
        while (m >= 0 && t[m]!= sss[i+m]) {
            i += m - mp.table[m];
            m = mp.table[m];
        }

        // Decrement i and increment m to move to the next pair of characters
        i--;
        m++;
    }

    // Initialize variable ans to store the answer
    int ans = 0;

    // Initialize variables r and rr for root calculation
    int r, rr;

    // Iterate through all characters in string s again
    for (int i = 0; i < ns; i++) {
        // If ok[i] is false, continue to the next iteration
        if (!ok[i]) {
            continue;
        }

        // If ok[(i+nt)%ns] is false, continue to the next iteration
        if (!ok[(i+nt)%ns]) {
            continue;
        }

        // Calculate roots r and rr of indices i and (i+nt)%ns respectively
        r = root(i, uni);
        rr = root((i+nt)%ns, uni);

        // If roots r and rr are equal, print -1 and exit the program
        if (rr == r) {
            cout << -1 << endl;
            return 0;
        }

        // Update uni array with root r
        uni[rr] = r;
    }

    // Initialize counter array to store the frequency of each root
    vector<int> counter(ns, 0);

    // Iterate through all roots and update their frequencies in counter array
    for (int i = 0; i < ns; i++) {
        r = root(i, uni);
        if (!ok[r]) {
            continue;
        }
        counter[r]++;
    }

    // Find the maximum frequency in counter array and store it in variable ans
    for (int i = 0; i < ns; i++) {
        if (ans < counter[i]) {
            ans = counter[i];
        }
    }

    // Print the answer
    cout << ans << endl;

    return 0;
}

