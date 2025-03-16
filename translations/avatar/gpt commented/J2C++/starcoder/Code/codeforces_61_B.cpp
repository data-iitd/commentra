#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Read three words from the input, remove non-alphabetic characters, and convert them to lowercase
    string word1, word2, word3;
    cin >> word1;
    cin >> word2;
    cin >> word3;
    word1.erase(remove_if(word1.begin(), word1.end(), ::ispunct), word1.end());
    word2.erase(remove_if(word2.begin(), word2.end(), ::ispunct), word2.end());
    word3.erase(remove_if(word3.begin(), word3.end(), ::ispunct), word3.end());
    transform(word1.begin(), word1.end(), word1.begin(), ::tolower);
    transform(word2.begin(), word2.end(), word2.begin(), ::tolower);
    transform(word3.begin(), word3.end(), word3.begin(), ::tolower);
    
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
    cin.ignore();
    
    // Loop through each student's test case
    for (int i = 0; i < students; i++) {
        // Read the test case input, remove non-alphabetic characters, and convert to lowercase
        string testCase;
        getline(cin, testCase);
        testCase.erase(remove_if(testCase.begin(), testCase.end(), ::ispunct), testCase.end());
        transform(testCase.begin(), testCase.end(), testCase.begin(), ::tolower);
        
        // Check if the test case matches any of the generated permutations
        if (testCase == perm1 || testCase == perm2 || testCase == perm3 || testCase == perm4 || testCase == perm5 || testCase == perm6) {
            // If it matches, print "ACC" (Accepted)
            cout << "ACC" << endl;
        } else {
            // If it doesn't match, print "WA" (Wrong Answer)
            cout << "WA" << endl;
        }
    }
    
    return 0;
}

