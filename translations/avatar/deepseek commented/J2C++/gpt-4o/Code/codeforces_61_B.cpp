#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    // Initialize variables for input words
    string word1, word2, word3;

    // Read and process the three input words
    getline(cin, word1);
    getline(cin, word2);
    getline(cin, word3);

    // Remove non-alphabetic characters and convert to lowercase
    auto cleanWord = [](string &word) {
        word.erase(remove_if(word.begin(), word.end(), [](char c) {
            return !isalpha(c);
        }), word.end());
        transform(word.begin(), word.end(), word.begin(), ::tolower);
    };

    cleanWord(word1);
    cleanWord(word2);
    cleanWord(word3);

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
    cin.ignore(); // Consume the newline character after the integer input

    // Process each test case
    for (int i = 0; i < students; i++) {
        string testCase;
        getline(cin, testCase);
        
        // Clean the test case
        cleanWord(testCase);

        // Check if the test case matches any of the generated permutations
        if (testCase == perm1 || testCase == perm2 || testCase == perm3 ||
            testCase == perm4 || testCase == perm5 || testCase == perm6) {
            cout << "ACC" << endl; // Print "ACC" if a match is found
        } else {
            cout << "WA" << endl; // Print "WA" if no match is found
        }
    }

    return 0;
}
// <END-OF-CODE>
