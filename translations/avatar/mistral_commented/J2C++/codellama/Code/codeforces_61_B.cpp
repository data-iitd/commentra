// Including necessary headers
#include <iostream>
#include <string>
#include <cctype>

// Creating a Main class with a main method
int main ( ) {
    // Initializing a string variable to store the first word
    std::string word1 ;
    // Initializing a string variable to store the second word
    std::string word2 ;
    // Initializing a string variable to store the third word
    std::string word3 ;
    // Initializing a string variable to store the test case
    std::string testCase ;
    // Initializing an integer variable to store the number of students
    int students ;

    // Reading the first word from the user input
    std::cin >> word1 ;
    // This block of code reads a line from the user input and stores it in the 'word1' variable.

    // Reading the second word from the user input
    std::cin >> word2 ;
    // This block of code reads a line from the user input and stores it in the 'word2' variable.

    // Reading the third word from the user input
    std::cin >> word3 ;
    // This block of code reads a line from the user input and stores it in the 'word3' variable.

    // Creating six permutations of the given words
    std::string perm1 = word1 + word2 + word3 ;
    std::string perm2 = word1 + word3 + word2 ;
    std::string perm3 = word2 + word1 + word3 ;
    std::string perm4 = word2 + word3 + word1 ;
    std::string perm5 = word3 + word2 + word1 ;
    std::string perm6 = word3 + word1 + word2 ;

    // Reading the number of students
    std::cin >> students ;
    // This block of code reads an integer value from the user input and stores it in the 'students' variable.

    // Looping through each student's test case
    for ( int i = 0 ; i < students ; i ++ ) {
        // Reading a test case from the user input
        std::cin >> testCase ;
        // This block of code reads a line from the user input and stores it in the 'testCase' variable.

        // Checking if the test case matches any of the permutations
        if ( testCase.compare ( perm1 ) == 0 || testCase.compare ( perm2 ) == 0 || testCase.compare ( perm3 ) == 0 || testCase.compare ( perm4 ) == 0 || testCase.compare ( perm5 ) == 0 || testCase.compare ( perm6 ) == 0 ) {
            // Printing 'ACC' if the test case matches any of the permutations
            std::cout << "ACC" << std::endl ;
        } else {
            // Printing 'WA' if the test case doesn't match any of the permutations
            std::cout << "WA" << std::endl ;
        }
    }

    // Ending the program
    return 0 ;
}

