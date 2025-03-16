#include <iostream>
#include <vector>

using namespace std;

// Function to generate all patterns of length k from the given array
void duplicatePatterns(vector<int>& elems, int k, vector<vector<int>>& result, vector<int>& pattern) {
    if (pattern.size() == k) {
        result.push_back(pattern);
        return;
    }

    for (int e : elems) {
        pattern.push_back(e);
        duplicatePatterns(elems, k, result, pattern);
        pattern.pop_back();
    }
}

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    // Generate all possible patterns of length k from the given array [0, 1, 2, 3]
    vector<int> elems = {0, 1, 2, 3};
    vector<vector<int>> patterns;
    vector<int> pattern;

    duplicatePatterns(elems, k, patterns, pattern);

    // Check each generated pattern
    for (const auto& P : patterns) {
        // Apply bitwise operation to RGB values of the given input
        int r = a, g = b, b_val = c; // Renamed b to b_val to avoid conflict with the type 'b'
        for (int i = 0; i < P.size(); i++) {
            if (P[i] == 0) {
                continue;
            } else if (P[i] == 1) {
                r *= 2;
            } else if (P[i] == 2) {
                g *= 2;
            } else if (P[i] == 3) {
                b_val *= 2;
            }
        }

        // Check if the result satisfies the condition g > r and b > g
        if (g > r && b_val > g) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    // If all patterns are checked and no satisfying pattern is found, print "No"
    cout << "No" << endl;
    return 0;
}

// <END-OF-CODE>
