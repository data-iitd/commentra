
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string word1, word2, word3, perm1, perm2, perm3, perm4, perm5, perm6;
    int students;
    cin >> word1 >> word2 >> word3;
    word1 = regex_replace(word1, regex("[^a-zA-Z]"), "");
    word2 = regex_replace(word2, regex("[^a-zA-Z]"), "");
    word3 = regex_replace(word3, regex("[^a-zA-Z]"), "");
    transform(word1.begin(), word1.end(), word1.begin(), ::tolower);
    transform(word2.begin(), word2.end(), word2.begin(), ::tolower);
    transform(word3.begin(), word3.end(), word3.begin(), ::tolower);
    perm1 = word1 + word2 + word3;
    perm2 = word1 + word3 + word2;
    perm3 = word2 + word1 + word3;
    perm4 = word2 + word3 + word1;
    perm5 = word3 + word2 + word1;
    perm6 = word3 + word1 + word2;
    cin >> students;
    cin.ignore();
    for (int i = 0; i < students; i++) {
        string testCase;
        getline(cin, testCase);
        testCase = regex_replace(testCase, regex("[^a-zA-Z]"), "");
        transform(testCase.begin(), testCase.end(), testCase.begin(), ::tolower);
        if (testCase == perm1 || testCase == perm2 || testCase == perm3 || testCase == perm4 || testCase == perm5 || testCase == perm6) {
            cout << "ACC" << endl;
        } else {
            cout << "WA" << endl;
        }
    }
    return 0;
}
