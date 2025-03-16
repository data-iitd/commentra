#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

// Function to read a single integer
int inp() {
    int x;
    cin >> x;
    return x;
}

// Function to read a single string
string instr() {
    string s;
    cin >> s;
    return s;
}

// Function to generate all permutations of a vector of strings
set<string> generatePermutations(vector<string>& strings) {
    set<string> permutations;
    sort(strings.begin(), strings.end());
    do {
        string perm = "";
        for (const auto& str : strings) {
            perm += str;
        }
        permutations.insert(perm);
    } while (next_permutation(strings.begin(), strings.end()));
    return permutations;
}

// Main function to solve the problem
void solve() {
    vector<string> l(3);
    for (int i = 0; i < 3; ++i) {
        l[i] = instr();
    }
    
    set<string> permutations = generatePermutations(l);
    
    int testCases = inp();
    for (int i = 0; i < testCases; ++i) {
        string testString = instr();
        if (permutations.find(testString) != permutations.end()) {
            cout << "ACC" << endl;
        } else {
            cout << "WA" << endl;
        }
    }
}

// Starting the program
int main() {
    solve();
    return 0;
}

// <END-OF-CODE>
