#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <bitset>

using namespace std;

const int MOD = 1000000000 + 7;
const int ALPHABET_NUM = 26;
const long long INF_INT64 = 1LL << 60;
const int INF_BIT60 = 1 << 60;
const int INF_INT32 = 1 << 30;
const int INF_BIT30 = 1 << 30;
const int NIL = -1;

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    string item;
    for (char ch : s) {
        if (ch == delim) {
            if (!item.empty()) {
                elems.push_back(item);
                item.clear();
            }
        } else {
            item += ch;
        }
    }
    if (!item.empty()) {
        elems.push_back(item);
    }
    return elems;
}

vector<int> splitInt(const string &s, char delim) {
    vector<int> elems;
    string item;
    for (char ch : s) {
        if (ch == delim) {
            if (!item.empty()) {
                elems.push_back(stoi(item));
                item.clear();
            }
        } else {
            item += ch;
        }
    }
    if (!item.empty()) {
        elems.push_back(stoi(item));
    }
    return elems;
}

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    // Generate all possible patterns of length k from the given array [0, 1, 2, 3]
    vector<vector<int>> duplicatePatterns(int elems[], int k) {
        vector<vector<int>> result;
        vector<int> current;
        generatePatterns(result, current, elems, k, 0);
        return result;
    }

    void generatePatterns(vector<vector<int>> &result, vector<int> &current, int elems[], int k, int depth) {
        if (depth == k) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < 4; ++i) {
            current.push_back(elems[i]);
            generatePatterns(result, current, elems, k, depth + 1);
            current.pop_back();
        }
    }

    vector<vector<int>> patterns = duplicatePatterns({0, 1, 2, 3}, k);

    // Check each generated pattern
    for (const auto &P : patterns) {
        // Apply bitwise operation to RGB values of the given input
        int r = a, g = b, b_ = c;
        for (int i = 0; i < P.size(); ++i) {
            if (P[i] == 1) {
                r *= 2;
            } else if (P[i] == 2) {
                g *= 2;
            } else if (P[i] == 3) {
                b_ *= 2;
            }
        }

        // Check if the result satisfies the condition g > r and b_ > g
        if (g > r && b_ > g) {
            cout << "Yes" << endl;
            return;
        }
    }

    // If all patterns are checked and no satisfying pattern is found, print "No"
    cout << "No" << endl;

    return 0;
}
