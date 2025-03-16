#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main() {
    std::string word1, word2, word3;
    std::string perm1, perm2, perm3, perm4, perm5, perm6;
    std::string testCase;

    // Read and process the three input words
    std::getline(std::cin, word1);
    std::getline(std::cin, word2);
    std::getline(std::cin, word3);

    // Remove non-alphabetic characters and convert to lowercase
    word1.erase(std::remove_if(word1.begin(), word1.end(), [](char c) { return !std::isalpha(c); }), word1.end());
    std::transform(word1.begin(), word1.end(), word1.begin(), ::tolower);
    word2.erase(std::remove_if(word2.begin(), word2.end(), [](char c) { return !std::isalpha(c); }), word2.end());
    std::transform(word2.begin(), word2.end(), word2.begin(), ::tolower);
    word3.erase(std::remove_if(word3.begin(), word3.end(), [](char c) { return !std::isalpha(c); }), word3.end());
    std::transform(word3.begin(), word3.end(), word3.begin(), ::tolower);

    // Generate all possible permutations of the three words
    perm1 = word1 + word2 + word3;
    perm2 = word1 + word3 + word2;
    perm3 = word2 + word1 + word3;
    perm4 = word2 + word3 + word1;
    perm5 = word3 + word2 + word1;
    perm6 = word3 + word1 + word2;

    // Read the number of test cases
    int students;
    std::cin >> students;
    std::cin.ignore(); // Consume the newline character after the integer input

    // Process each test case
    for (int i = 0; i < students; i++) {
        std::getline(std::cin, testCase);
        // Remove non-alphabetic characters and convert to lowercase
        testCase.erase(std::remove_if(testCase.begin(), testCase.end(), [](char c) { return !std::isalpha(c); }), testCase.end());
        std::transform(testCase.begin(), testCase.end(), testCase.begin(), ::tolower);

        // Check if the test case matches any of the generated permutations
        if (testCase == perm1 || testCase == perm2 || testCase == perm3 ||
            testCase == perm4 || testCase == perm5 || testCase == perm6) {
            std::cout << "ACC" << std::endl; // Print "ACC" if a match is found
        } else {
            std::cout << "WA" << std::endl; // Print "WA" if no match is found
        }
    }

    return 0;
}
