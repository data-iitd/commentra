// Importing necessary packages
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Creating a Main class with a main method
int main ( ) {
    // Reading the first word from the user input
    std::string word1 ;
    std::cin >> word1 ;
    // This block of code reads a line from the user input.
    // The resulting string is stored in the 'word1' variable.

    // Reading the second word from the user input
    std::string word2 ;
    std::cin >> word2 ;
    // This block of code reads a line from the user input.
    // The resulting string is stored in the 'word2' variable.

    // Reading the third word from the user input
    std::string word3 ;
    std::cin >> word3 ;
    // This block of code reads a line from the user input.
    // The resulting string is stored in the 'word3' variable.

    // Creating six permutations of the given words
    std::string perm1 = word1 + word2 + word3 ;
    std::string perm2 = word1 + word3 + word2 ;
    std::string perm3 = word2 + word1 + word3 ;
    std::string perm4 = word2 + word3 + word1 ;
    std::string perm5 = word3 + word2 + word1 ;
    std::string perm6 = word3 + word1 + word2 ;

    // Reading the number of students
    int students ;
    std::cin >> students ;
    // This block of code reads an integer value from the user input.
    // The number of students is stored in the'students' variable.

    // Looping through each student's test case
    for ( int i = 0 ; i < students ; i ++ ) {
        // Reading a test case from the user input
        std::string testCase ;
        std::cin >> testCase ;
        // This block of code reads a line from the user input.
        // The resulting string is stored in the 'testCase' variable.

        // Checking if the test case matches any of the permutations
        if ( testCase == perm1 || testCase == perm2 || testCase == perm3 || testCase == perm4 || testCase == perm5 || testCase == perm6 ) {
            // Printing 'ACC' if the test case matches any of the permutations
            std::cout << "ACC" << std::endl ;
        } else {
            // Printing 'WA' if the test case doesn't match any of the permutations
            std::cout << "WA" << std::endl ;
        }
    }

    // Returning from the main method
    return 0 ;
}

