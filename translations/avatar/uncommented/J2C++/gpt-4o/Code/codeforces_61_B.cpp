#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

std::string cleanString(const std::string& str) {
    std::string cleaned;
    for (char ch : str) {
        if (std::isalpha(ch)) {
            cleaned += std::tolower(ch);
        }
    }
    return cleaned;
}

int main() {
    std::string word1, word2, word3;
    std::getline(std::cin, word1);
    std::getline(std::cin, word2);
    std::getline(std::cin, word3);

    std::string perm1 = cleanString(word1) + cleanString(word2) + cleanString(word3);
    std::string perm2 = cleanString(word1) + cleanString(word3) + cleanString(word2);
    std::string perm3 = cleanString(word2) + cleanString(word1) + cleanString(word3);
    std::string perm4 = cleanString(word2) + cleanString(word3) + cleanString(word1);
    std::string perm5 = cleanString(word3) + cleanString(word2) + cleanString(word1);
    std::string perm6 = cleanString(word3) + cleanString(word1) + cleanString(word2);

    int students;
    std::cin >> students;
    std::cin.ignore(); // To ignore the newline after the integer input

    for (int i = 0; i < students; i++) {
        std::string testCase;
        std::getline(std::cin, testCase);
        std::string cleanedTestCase = cleanString(testCase);

        if (cleanedTestCase == perm1 || cleanedTestCase == perm2 || 
            cleanedTestCase == perm3 || cleanedTestCase == perm4 || 
            cleanedTestCase == perm5 || cleanedTestCase == perm6) {
            std::cout << "ACC" << std::endl;
        } else {
            std::cout << "WA" << std::endl;
        }
    }

    return 0;
}
