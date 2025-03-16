
// Importing necessary libraries
#include <iostream>
#include <string>
#include <algorithm>

// Creating a main function
int main() {
    // Initializing a string variable to store the first word from the user input
    std::string word1;
    // This block of code prompts the user to enter a word and stores it in the 'word1' variable.

    // Initializing a string variable to store the second word from the user input
    std::string word2;
    // This block of code prompts the user to enter a word and stores it in the 'word2' variable.

    // Initializing a string variable to store the third word from the user input
    std::string word3;
    // This block of code prompts the user to enter a word and stores it in the 'word3' variable.

    // Creating six permutations of the given words
    std::string perm1 = word1 + word2 + word3;
    std::string perm2 = word1 + word3 + word2;
    std::string perm3 = word2 + word1 + word3;
    std::string perm4 = word2 + word3 + word1;
    std::string perm5 = word3 + word2 + word1;
    std::string perm6 = word3 + word1 + word2;

    // Initializing an integer variable to store the number of students
    int students;
    // This block of code prompts the user to enter the number of students and stores it in the'students' variable.

    // Looping through each student's test case
    for (int i = 0; i < students; i++) {
        // Initializing a string variable to store the test case from the user input
        std::string testCase;
        // This block of code prompts the user to enter a test case and stores it in the 'testCase' variable.

        // Checking if the test case matches any of the permutations
        if (testCase == perm1 || testCase == perm2 || testCase == perm3 || testCase == perm4 || testCase == perm5 || testCase == perm6) {
            // Printing 'ACC' if the test case matches any of the permutations
            std::cout << "ACC" << std::endl;
        } else {
            // Printing 'WA' if the test case doesn't match any of the permutations
            std::cout << "WA" << std::endl;
        }
    }

    // Returning 0 to indicate successful execution
    return 0;
}

