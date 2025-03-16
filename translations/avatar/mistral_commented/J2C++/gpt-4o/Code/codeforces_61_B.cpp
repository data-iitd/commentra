// Importing necessary libraries
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

// Using the standard namespace
using namespace std;

// Main function
int main() {
    // Initializing variables to store the words
    string word1, word2, word3;

    // Reading the first word from the user input
    getline(cin, word1);
    // Removing non-alphabetic characters and converting to lowercase
    word1.erase(remove_if(word1.begin(), word1.end(), [](char c) { return !isalpha(c); }), word1.end());
    transform(word1.begin(), word1.end(), word1.begin(), ::tolower);

    // Reading the second word from the user input
    getline(cin, word2);
    // Removing non-alphabetic characters and converting to lowercase
    word2.erase(remove_if(word2.begin(), word2.end(), [](char c) { return !isalpha(c); }), word2.end());
    transform(word2.begin(), word2.end(), word2.begin(), ::tolower);

    // Reading the third word from the user input
    getline(cin, word3);
    // Removing non-alphabetic characters and converting to lowercase
    word3.erase(remove_if(word3.begin(), word3.end(), [](char c) { return !isalpha(c); }), word3.end());
    transform(word3.begin(), word3.end(), word3.begin(), ::tolower);

    // Creating six permutations of the given words
    string perm1 = word1 + word2 + word3;
    string perm2 = word1 + word3 + word2;
    string perm3 = word2 + word1 + word3;
    string perm4 = word2 + word3 + word1;
    string perm5 = word3 + word2 + word1;
    string perm6 = word3 + word1 + word2;

    // Reading the number of students
    int students;
    cin >> students;
    cin.ignore(); // Consuming the newline character left after reading an integer.

    // Looping through each student's test case
    for (int i = 0; i < students; i++) {
        // Reading a test case from the user input
        string testCase;
        getline(cin, testCase);
        // Removing non-alphabetic characters and converting to lowercase
        testCase.erase(remove_if(testCase.begin(), testCase.end(), [](char c) { return !isalpha(c); }), testCase.end());
        transform(testCase.begin(), testCase.end(), testCase.begin(), ::tolower);

        // Checking if the test case matches any of the permutations
        if (testCase == perm1 || testCase == perm2 || testCase == perm3 || testCase == perm4 || testCase == perm5 || testCase == perm6) {
            // Printing 'ACC' if the test case matches any of the permutations
            cout << "ACC" << endl;
        } else {
            // Printing 'WA' if the test case doesn't match any of the permutations
            cout << "WA" << endl;
        }
    }

    return 0; // Ending the program
}

// <END-OF-CODE>
