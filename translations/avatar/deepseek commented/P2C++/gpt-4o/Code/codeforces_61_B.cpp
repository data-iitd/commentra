#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
#include <sstream>
#include <iterator>

using namespace std;

// Function to sanitize a string by converting it to lowercase and removing certain characters
string sanitize(const string& s) {
    string r;
    for (char i : s) {
        if (i != '-' && i != ';' && i != '_') {
            r += tolower(i);
        }
    }
    return r;
}

// Main logic of the program
void solve() {
    vector<string> l;
    for (int i = 0; i < 3; ++i) {
        string input;
        getline(cin, input);
        l.push_back(sanitize(input));
    }

    set<string> permutationsSet;
    sort(l.begin(), l.end());
    do {
        string perm = l[0] + l[1] + l[2];
        permutationsSet.insert(perm);
    } while (next_permutation(l.begin(), l.end()));

    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input
    for (int i = 0; i < t; ++i) {
        string query;
        getline(cin, query);
        if (permutationsSet.find(sanitize(query)) != permutationsSet.end()) {
            cout << "ACC" << endl;
        } else {
            cout << "WA" << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}

// <END-OF-CODE>
