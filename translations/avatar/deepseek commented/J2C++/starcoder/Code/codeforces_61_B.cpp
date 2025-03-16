
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Initialize Scanner for input operations
    string word1, word2, word3 ;
    cin >> word1 >> word2 >> word3 ;

    // Generate all possible permutations of the three words
    string perm1 = word1 + word2 + word3 ;
    string perm2 = word1 + word3 + word2 ;
    string perm3 = word2 + word1 + word3 ;
    string perm4 = word2 + word3 + word1 ;
    string perm5 = word3 + word2 + word1 ;
    string perm6 = word3 + word1 + word2 ;

    // Read the number of test cases
    int students ;
    cin >> students ;
    cin.ignore ( std::numeric_limits<std::streamsize>::max ( ), '\n' ) ; // Consume the newline character after the integer input

    // Process each test case
    for ( int i = 0 ; i < students ; i ++ ) {
        string testCase ;
        getline ( cin, testCase ) ;
        testCase = testCase.erase ( remove_if ( testCase.begin ( ), testCase.end ( ), isalpha ), testCase.end ( ) ) ; // Remove all non-alphabetic characters
        testCase = to_lower ( testCase ) ; // Convert all characters to lowercase

        // Check if the test case matches any of the generated permutations
        if ( testCase == perm1 || testCase == perm2 || testCase == perm3 || testCase == perm4 || testCase == perm5 || testCase == perm6 ) {
            cout << "ACC" << endl ; // Print "ACC" if a match is found
        } else {
            cout << "WA" << endl ; // Print "WA" if no match is found
        }
    }
}

