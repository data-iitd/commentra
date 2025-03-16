#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string cleanString(const string& input) {
    string result;
    for (char ch : input) {
        if (isalpha(ch)) {
            result += tolower(ch);
        }
    }
    return result;
}

int main() {
    // Read three words from the input
    string word1, word2, word3;
    getline(cin, word1);
    getline(cin, word2);
    getline(cin, word3);
    
    // Clean the words by removing non-alphabetic characters and converting to lowercase
    word1 = cleanString(word1);
    word2 = cleanString(word2);
    word3 = cleanString(word3);
    
    // Generate all possible permutations of the three words
    string perm1 = word1 + word2 + word3;
    string perm2 = word1 + word3 + word2;
    string perm3 = word2 + word1 + word3;
    string perm4 = word2 + word3 + word1;
    string perm5 = word3 + word2 + word1;
    string perm6 = word3 + word1 + word2;
    
    // Read the number of students (test cases)
    int students;
    cin >> students;
    cin.ignore(); // Consume the newline character after the integer input
    
    // Loop through each student's test case
    for (int i = 0; i < students; i++) {
        // Read the test case input, clean it
        string testCase;
        getline(cin, testCase);
        testCase = cleanString(testCase);
        
        // Check if the test case matches any of the generated permutations
        if (testCase == perm1 || testCase == perm2 || 
            testCase == perm3 || testCase == perm4 || 
            testCase == perm5 || testCase == perm6) {
            // If it matches, print "ACC" (Accepted)
            cout << "ACC" << endl;
        } else {
            // If it doesn't match, print "WA" (Wrong Answer)
            cout << "WA" << endl;
        }
    }
    
    return 0;
}

// <END-OF-CODE>
