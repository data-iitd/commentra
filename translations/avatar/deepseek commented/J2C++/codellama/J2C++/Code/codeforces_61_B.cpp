
#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

int main() {
    // Initialize Scanner for input operations
    string word1, word2, word3;
    cin >> word1 >> word2 >> word3;

    // Generate all possible permutations of the three words
    string perm1 = word1 + word2 + word3;
    string perm2 = word1 + word3 + word2;
    string perm3 = word2 + word1 + word3;
    string perm4 = word2 + word3 + word1;
    string perm5 = word3 + word2 + word1;
    string perm6 = word3 + word1 + word2;

    // Read the number of test cases
    int students;
    cin >> students;

    // Process each test case
    for (int i = 0; i < students; i++) {
        string testCase;
        cin >> testCase;
        // Check if the test case matches any of the generated permutations
        if (testCase.compare(perm1) == 0 || testCase.compare(perm2) == 0 || testCase.compare(perm3) == 0 ||
            testCase.compare(perm4) == 0 || testCase.compare(perm5) == 0 || testCase.compare(perm6) == 0) {
            cout << "ACC" << endl; // Print "ACC" if a match is found
        } else {
            cout << "WA" << endl; // Print "WA" if no match is found
        }
    }

    return 0;
}

