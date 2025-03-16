

#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string word1, word2, word3;
    std::cin >> word1 >> word2 >> word3;

    std::string perm1 = word1 + word2 + word3;
    std::string perm2 = word1 + word3 + word2;
    std::string perm3 = word2 + word1 + word3;
    std::string perm4 = word2 + word3 + word1;
    std::string perm5 = word3 + word2 + word1;
    std::string perm6 = word3 + word1 + word2;

    int students;
    std::cin >> students;

    for (int i = 0; i < students; i++) {
        std::string testCase;
        std::cin >> testCase;

        std::transform(testCase.begin(), testCase.end(), testCase.begin(), ::tolower);
        std::transform(word1.begin(), word1.end(), word1.begin(), ::tolower);
        std::transform(word2.begin(), word2.end(), word2.begin(), ::tolower);
        std::transform(word3.begin(), word3.end(), word3.begin(), ::tolower);

        if (testCase == perm1 || testCase == perm2 || testCase == perm3 ||
            testCase == perm4 || testCase == perm5 || testCase == perm6) {
            std::cout << "ACC" << std::endl;
        } else {
            std::cout << "WA" << std::endl;
        }
    }

    return 0;
}
