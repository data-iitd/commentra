#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    std::string word1, word2, word3;
    std::getline(std::cin, word1);
    std::getline(std::cin, word2);
    std::getline(std::cin, word3);

    std::transform(word1.begin(), word1.end(), word1.begin(), ::tolower);
    std::transform(word2.begin(), word2.end(), word2.begin(), ::tolower);
    std::transform(word3.begin(), word3.end(), word3.begin(), ::tolower);

    word1.erase(std::remove_if(word1.begin(), word1.end(), [](char c) { return !std::isalpha(c); }), word1.end());
    word2.erase(std::remove_if(word2.begin(), word2.end(), [](char c) { return !std::isalpha(c); }), word2.end());
    word3.erase(std::remove_if(word3.begin(), word3.end(), [](char c) { return !std::isalpha(c); }), word3.end());

    std::string perm1 = word1 + word2 + word3;
    std::string perm2 = word1 + word3 + word2;
    std::string perm3 = word2 + word1 + word3;
    std::string perm4 = word2 + word3 + word1;
    std::string perm5 = word3 + word2 + word1;
    std::string perm6 = word3 + word1 + word2;

    int students;
    std::cin >> students;
    std::cin.ignore();

    for (int i = 0; i < students; ++i) {
        std::string testCase;
        std::getline(std::cin, testCase);

        std::transform(testCase.begin(), testCase.end(), testCase.begin(), ::tolower);
        testCase.erase(std::remove_if(testCase.begin(), testCase.end(), [](char c) { return !std::isalpha(c); }), testCase.end());

        if (testCase == perm1 || testCase == perm2 || testCase == perm3 || testCase == perm4 || testCase == perm5 || testCase == perm6) {
            std::cout << "ACC" << std::endl;
        } else {
            std::cout << "WA" << std::endl;
        }
    }

    return 0;
}

