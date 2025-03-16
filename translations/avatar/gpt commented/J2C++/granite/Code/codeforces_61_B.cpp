
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string word1, word2, word3, perm1, perm2, perm3, perm4, perm5, perm6, testCase;
    int students;

    // Read three words from the input, remove non-alphabetic characters, and convert them to lowercase
    std::cin >> word1 >> word2 >> word3;
    std::transform(word1.begin(), word1.end(), word1.begin(), ::tolower);
    std::transform(word2.begin(), word2.end(), word2.begin(), ::tolower);
    std::transform(word3.begin(), word3.end(), word3.begin(), ::tolower);

    // Generate all possible permutations of the three words
    perm1 = word1 + word2 + word3;
    perm2 = word1 + word3 + word2;
    perm3 = word2 + word1 + word3;
    perm4 = word2 + word3 + word1;
    perm5 = word3 + word2 + word1;
    perm6 = word3 + word1 + word2;

    // Read the number of students (test cases)
    std::cin >> students;

    // Loop through each student's test case
    for (int i = 0; i < students; i++) {
        // Read the test case input, remove non-alphabetic characters, and convert to lowercase
        std::cin >> testCase;
        std::transform(testCase.begin(), testCase.end(), testCase.begin(), ::tolower);

        // Check if the test case matches any of the generated permutations
        if (testCase == perm1 || testCase == perm2 ||
            testCase == perm3 || testCase == perm4 ||
            testCase == perm5 || testCase == perm6) {
            // If it matches, print "ACC" (Accepted)
            std::cout << "ACC" << std::endl;
        } else {
            // If it doesn't match, print "WA" (Wrong Answer)
            std::cout << "WA" << std::endl;
        }
    }

    return 0;
}
