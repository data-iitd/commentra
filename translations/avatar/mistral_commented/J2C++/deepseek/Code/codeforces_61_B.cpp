#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    std::string word1, word2, word3;
    std::string perm1, perm2, perm3, perm4, perm5, perm6;
    std::string testCase;
    int students;

    // Reading the first word from the user input
    std::getline(std::cin, word1);
    word1.erase(std::remove_if(word1.begin(), word1.end(), [](char c) { return !std::isalpha(c); }), word1.end());
    std::transform(word1.begin(), word1.end(), word1.begin(), ::tolower);

    // Reading the second word from the user input
    std::getline(std::cin, word2);
    word2.erase(std::remove_if(word2.begin(), word2.end(), [](char c) { return !std::isalpha(c); }), word2.end());
    std::transform(word2.begin(), word2.end(), word2.begin(), ::tolower);

    // Reading the third word from the user input
    std::getline(std::cin, word3);
    word3.erase(std::remove_if(word3.begin(), word3.end(), [](char c) { return !std::isalpha(c); }), word3.end());
    std::transform(word3.begin(), word3.end(), word3.begin(), ::tolower);

    // Creating six permutations of the given words
    perm1 = word1 + word2 + word3;
    perm2 = word1 + word3 + word2;
    perm3 = word2 + word1 + word3;
    perm4 = word2 + word3 + word1;
    perm5 = word3 + word2 + word1;
    perm6 = word3 + word1 + word2;

    // Reading the number of students
    std::cin >> students;
    std::cin.ignore(); // Consuming the newline character left after reading an integer.

    // Looping through each student's test case
    for (int i = 0; i < students; i++) {
        // Reading a test case from the user input
        std::getline(std::cin, testCase);
        testCase.erase(std::remove_if(testCase.begin(), testCase.end(), [](char c) { return !std::isalpha(c); }), testCase.end());
        std::transform(testCase.begin(), testCase.end(), testCase.begin(), ::tolower);

        // Checking if the test case matches any of the permutations
        if (testCase == perm1 || testCase == perm2 || testCase == perm3 || testCase == perm4 || testCase == perm5 || testCase == perm6) {
            // Printing 'ACC' if the test case matches any of the permutations
            std::cout << "ACC" << std::endl;
        } else {
            // Printing 'WA' if the test case doesn't match any of the permutations
            std::cout << "WA" << std::endl;
        }
    }

    return 0;
}
