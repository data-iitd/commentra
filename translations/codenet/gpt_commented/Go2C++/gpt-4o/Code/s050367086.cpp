#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Function to read the next string from input
string getNextString(istringstream &iss) {
    string s;
    iss >> s; // Read the next token
    return s; // Return the scanned text
}

// Function to find the root of the given index using path compression
int root(int i, vector<int> &uni) {
    if (i == uni[i]) {
        return i; // Return if the index is its own root
    }
    uni[i] = root(uni[i], uni); // Path compression
    return uni[i]; // Return the root
}

// Struct to hold the string and its pattern matching table
struct MP {
    string s;
    vector<int> table;

    // Function to initialize the pattern matching table for the string
    void init(const string &s) {
        this->s = s;
        int n = s.length();
        table.resize(n + 1);
        table[0] = -1; // Initialize the first value of the table
        int j = -1;
        for (int i = 0; i < n; i++) {
            while (j >= 0 && s[i] != s[j]) {
                j = table[j]; // Update j based on the table
            }
            j++;
            table[i + 1] = j; // Fill the table with the length of the longest prefix
        }
    }
};

int main() {
    // Initialize input and output streams
    string input;
    getline(cin, input);
    istringstream iss(input);

    // Read two strings from input
    string s = getNextString(iss);
    string t = getNextString(iss);

    // Calculate lengths of the input strings
    int ns = s.length();
    int nt = t.length();

    // Create a vector to hold repeated instances of string s
    vector<string> ss((nt - 1) / ns + 1, s);

    // Concatenate the repeated strings to form a new string
    string sss = string(ss.begin(), ss.end()) + string(ss.begin(), ss.end());

    // Initialize a boolean vector to track matches
    vector<bool> ok(ns, false);

    // Initialize a unique index array and a pattern matching structure
    vector<int> uni(ns);
    MP mp;
    mp.init(t); // Initialize the pattern matching table with string t
    int m = 0;
    for (int i = 0; i < ns; i++) {
        uni[i] = i; // Set each index to itself initially
    }
    bool o;

    // Check for matches of string t in the concatenated string sss
    for (int i = 0; i < ns; i++) {
        o = true;
        m = 0; // Reset m for each new starting index
        while (m < nt) {
            if (t[m] != sss[i + m]) { // Compare characters
                o = false;
                break;
            }
            m++;
        }
        ok[i] = o; // Store the result of the match
        if (o) {
            i += nt - mp.table[m]; // Update index based on the pattern table
            m = mp.table[m]; // Update match index
        }
        while (m >= 0 && t[m] != sss[i + m]) {
            i += m - mp.table[m]; // Update index if mismatch occurs
            m = mp.table[m]; // Update match index
        }
        i--; // Adjust index for the next iteration
        m++; // Move to the next character
    }

    // Calculate the answer based on the matches found
    int ans = 0;
    int r, rr;
    for (int i = 0; i < ns; i++) {
        if (!ok[i]) {
            continue; // Skip if no match
        }
        if (!ok[(i + nt) % ns]) {
            continue; // Skip if no match for the next index
        }
        r = root(i, uni); // Find the root of the current index
        rr = root((i + nt) % ns, uni); // Find the root of the next index
        if (rr == r) {
            cout << -1 << endl; // Output -1 if they are in the same component
            return 0;
        }
        uni[rr] = r; // Union the two components
    }

    // Count the number of matches for each unique root
    vector<int> counter(ns, 0);
    for (int i = 0; i < ns; i++) {
        r = root(i, uni); // Find the root for the current index
        if (!ok[r]) {
            continue; // Skip if no match
        }
        counter[r]++; // Increment the count for the root
    }
    for (int i = 0; i < ns; i++) {
        if (ans < counter[i]) {
            ans = counter[i]; // Update the answer with the maximum count
        }
    }

    // Output the final answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
